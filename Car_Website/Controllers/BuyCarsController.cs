using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using Proje.Data;
using Proje.Models;
using Microsoft.AspNetCore.Hosting;
using System.IO;


namespace Proje.Controllers
{
    public class BuyCarsController : Controller
    {
        private readonly ApplicationDbContext _context;
        private readonly IWebHostEnvironment _hostingEnvironment;

        public BuyCarsController(ApplicationDbContext context, IWebHostEnvironment hostingEnvironment)
        {
            _context = context;
            _hostingEnvironment = hostingEnvironment;
        }

        // GET: BuyCars
        public async Task<IActionResult> Index()
        {
            var applicationDbContext = _context.BuyCar.Include(b => b.Category).Include(b => b.Language);
            return View(await applicationDbContext.ToListAsync());
        }

        // GET: BuyCars/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var buyCar = await _context.BuyCar
                .Include(b => b.Category)
                .Include(b => b.Language)
                .FirstOrDefaultAsync(m => m.Id == id);
            if (buyCar == null)
            {
                return NotFound();
            }

            return View(buyCar);
        }

        // GET: BuyCars/Create
        public IActionResult Create()
        {
            ViewData["CategoryId"] = new SelectList(_context.Categori, "Id", "Id");
            ViewData["LanguageId"] = new SelectList(_context.Dil, "Id", "Id");
            return View();
        }

        // POST: BuyCars/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to, for 
        // more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("Id,CarName,Year,Description,Price,gear,Color,Fuel,Image,Distance,CategoryId,LanguageId,OriginId")] BuyCar buyCar)
        {
            if (ModelState.IsValid)
            { //******
                string webRootPath = _hostingEnvironment.WebRootPath;
                var files = HttpContext.Request.Form.Files;


                string fileName = Guid.NewGuid().ToString();
                var uploads = Path.Combine(webRootPath, @"images\satilik-images");
                var extension = Path.GetExtension(files[0].FileName);

                using (var fileStream = new FileStream(Path.Combine(uploads, fileName + extension), FileMode.Create))
                {
                    files[0].CopyTo(fileStream);
                }
                buyCar.Image = @"\images\satilik-images\" + fileName + extension;

                //********
                _context.Add(buyCar);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            ViewData["CategoryId"] = new SelectList(_context.Categori, "Id", "Id", buyCar.CategoryId);
            ViewData["LanguageId"] = new SelectList(_context.Dil, "Id", "Id", buyCar.LanguageId);
            return View(buyCar);
        }

        // GET: BuyCars/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var buyCar = await _context.BuyCar.FindAsync(id);
            if (buyCar == null)
            {
                return NotFound();
            }
            ViewData["CategoryId"] = new SelectList(_context.Categori, "Id", "Id", buyCar.CategoryId);
            ViewData["LanguageId"] = new SelectList(_context.Dil, "Id", "Id", buyCar.LanguageId);
            return View(buyCar);
        }

        // POST: BuyCars/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to, for 
        // more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("Id,CarName,Year,Description,Price,gear,Color,Fuel,Image,Distance,CategoryId,LanguageId,OriginId")] BuyCar buyCar)
        {
            if (id != buyCar.Id)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(buyCar);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!BuyCarExists(buyCar.Id))
                    {
                        return NotFound();
                    }
                    else
                    {
                        throw;
                    }
                }
                return RedirectToAction(nameof(Index));
            }
            ViewData["CategoryId"] = new SelectList(_context.Categori, "Id", "Id", buyCar.CategoryId);
            ViewData["LanguageId"] = new SelectList(_context.Dil, "Id", "Id", buyCar.LanguageId);
            return View(buyCar);
        }

        // GET: BuyCars/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var buyCar = await _context.BuyCar
                .Include(b => b.Category)
                .Include(b => b.Language)
                .FirstOrDefaultAsync(m => m.Id == id);
            if (buyCar == null)
            {
                return NotFound();
            }

            return View(buyCar);
        }

        // POST: BuyCars/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var buyCar = await _context.BuyCar.FindAsync(id);
            _context.BuyCar.Remove(buyCar);
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool BuyCarExists(int id)
        {
            return _context.BuyCar.Any(e => e.Id == id);
        }
    }
}
