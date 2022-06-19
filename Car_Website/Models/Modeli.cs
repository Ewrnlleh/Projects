using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Proje.Models
{
    public class Modeli
    {
        public int Id { get; set; }

        public string Name { get; set; }

        public DateTime ModelDate { get; set; }

        public int? OriginId { get; set; }

        public Origin Origin { get; set; }
    }
}
