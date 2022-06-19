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
    public class RentCarsController : Controller
    {
        private readonly ApplicationDbContext _context;

        private readonly IWebHostEnvironment _hostingEnvironment;

        public RentCarsController(ApplicationDbContext context, IWebHostEnvironment hostingEnvironment)
        {
            _context = context;
            _hostingEnvironment = hostingEnvironment;
        }

        // GET: RentCars
        public async Task<IActionResult> Index()
        {
            var applicationDbContext = _context.RentCar.Include(r => r.Category).Include(r => r.Language);
            return View(await applicationDbContext.ToListAsync());
        }

        // GET: RentCars/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var rentCar = await _context.RentCar
                .Include(r => r.Category)
                .Include(r => r.Language)
                .FirstOrDefaultAsync(m => m.Id == id);
            if (rentCar == null)
            {
                return NotFound();
            }

            return View(rentCar);
        }

        // GET: RentCars/Create
        public IActionResult Create()
        {
            ViewData["CategoryId"] = new SelectList(_context.Categori, "Id", "Id");
            ViewData["LanguageId"] = new SelectList(_context.Dil, "Id", "Id");
            return View();
        }

        // POST: RentCars/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to, for 
        // more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("Id,CarName,Year,Description,Price,gear,Color,Fuel,Image,Distance,CategoryId,LanguageId,OriginId")] RentCar rentCar)
        {
            if (ModelState.IsValid)
            {
                //******
                string webRootPath = _hostingEnvironment.WebRootPath;
                var files = HttpContext.Request.Form.Files;


                string fileName = Guid.NewGuid().ToString();
                var uploads = Path.Combine(webRootPath, @"images\kiralik-images");
                var extension = Path.GetExtension(files[0].FileName);

                using (var fileStream = new FileStream(Path.Combine(uploads, fileName + extension), FileMode.Create))
                {
                    files[0].CopyTo(fileStream);
                }
                rentCar.Image = @"\images\kiralik-images\" + fileName + extension;

                //********
                _context.Add(rentCar);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            ViewData["CategoryId"] = new SelectList(_context.Categori, "Id", "Id", rentCar.CategoryId);
            ViewData["LanguageId"] = new SelectList(_context.Dil, "Id", "Id", rentCar.LanguageId);
            return View(rentCar);
        }

        // GET: RentCars/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var rentCar = await _context.RentCar.FindAsync(id);
            if (rentCar == null)
            {
                return NotFound();
            }
            ViewData["CategoryId"] = new SelectList(_context.Categori, "Id", "Id", rentCar.CategoryId);
            ViewData["LanguageId"] = new SelectList(_context.Dil, "Id", "Id", rentCar.LanguageId);
            return View(rentCar);
        }

        // POST: RentCars/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to, for 
        // more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("Id,CarName,Year,Description,Price,gear,Color,Fuel,Image,Distance,CategoryId,LanguageId,OriginId")] RentCar rentCar)
        {
            if (id != rentCar.Id)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(rentCar);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!RentCarExists(rentCar.Id))
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
            ViewData["CategoryId"] = new SelectList(_context.Categori, "Id", "Id", rentCar.CategoryId);
            ViewData["LanguageId"] = new SelectList(_context.Dil, "Id", "Id", rentCar.LanguageId);
            return View(rentCar);
        }

        // GET: RentCars/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var rentCar = await _context.RentCar
                .Include(r => r.Category)
                .Include(r => r.Language)
                .FirstOrDefaultAsync(m => m.Id == id);
            if (rentCar == null)
            {
                return NotFound();
            }

            return View(rentCar);
        }

        // POST: RentCars/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var rentCar = await _context.RentCar.FindAsync(id);
            _context.RentCar.Remove(rentCar);
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool RentCarExists(int id)
        {
            return _context.RentCar.Any(e => e.Id == id);
        }
    }
}
