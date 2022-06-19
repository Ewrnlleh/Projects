

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NDP___Proje
{
    interface Hayvan
    {
        int Enerji(int deger);
        int YemVer(int deger);
        string Durum(int deger, string can);
        string Uretim(int deger, string adet);
        int Satıs();
    }
}
