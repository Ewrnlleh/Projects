using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using Proje.Data;
using Proje.Models;

namespace Proje.Controllers
{
    public class ModelisController : Controller
    {
        private readonly ApplicationDbContext _context;

        public ModelisController(ApplicationDbContext context)
        {
            _context = context;
        }

        // GET: Modelis
        public async Task<IActionResult> Index()
        {
            var applicationDbContext = _context.Modeli.Include(m => m.Origin);
            return View(await applicationDbContext.ToListAsync());
        }

        // GET: Modelis/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var modeli = await _context.Modeli
                .Include(m => m.Origin)
                .FirstOrDefaultAsync(m => m.Id == id);
            if (modeli == null)
            {
                return NotFound();
            }

            return View(modeli);
        }

        // GET: Modelis/Create
        public IActionResult Create()
        {
            ViewData["OriginId"] = new SelectList(_context.Origin, "Id", "Id");
            return View();
        }

        // POST: Modelis/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to, for 
        // more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("Id,Name,ModelDate,OriginId")] Modeli modeli)
        {
            if (ModelState.IsValid)
            {
                _context.Add(modeli);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            ViewData["OriginId"] = new SelectList(_context.Origin, "Id", "Id", modeli.OriginId);
            return View(modeli);
        }

        // GET: Modelis/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var modeli = await _context.Modeli.FindAsync(id);
            if (modeli == null)
            {
                return NotFound();
            }
            ViewData["OriginId"] = new SelectList(_context.Origin, "Id", "Id", modeli.OriginId);
            return View(modeli);
        }

        // POST: Modelis/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to, for 
        // more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("Id,Name,ModelDate,OriginId")] Modeli modeli)
        {
            if (id != modeli.Id)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(modeli);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!ModeliExists(modeli.Id))
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
            ViewData["OriginId"] = new SelectList(_context.Origin, "Id", "Id", modeli.OriginId);
            return View(modeli);
        }

        // GET: Modelis/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var modeli = await _context.Modeli
                .Include(m => m.Origin)
                .FirstOrDefaultAsync(m => m.Id == id);
            if (modeli == null)
            {
                return NotFound();
            }

            return View(modeli);
        }

        // POST: Modelis/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var modeli = await _context.Modeli.FindAsync(id);
            _context.Modeli.Remove(modeli);
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool ModeliExists(int id)
        {
            return _context.Modeli.Any(e => e.Id == id);
        }
    }
}
