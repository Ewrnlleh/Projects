using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Proje.Models
{
    public class RentCar
	{
		public int Id { get; set; }

		public string CarName { get; set; }

		public int? Year { get; set; }

		public string Description { get; set; }

		public int Price { get; set; }

		public string gear { get; set; }

		public string Color { get; set; }

		public string Fuel { get; set; }

		public string Image { get; set; }

		public int Distance { get; set; }

		public int CategoryId { get; set; }

		public Category Category { get; set; }

		public int LanguageId { get; set; }

		public Language Language { get; set; }

		public Origin Origin { get; set; }

		public string OriginId { get; set; }

	}
}
