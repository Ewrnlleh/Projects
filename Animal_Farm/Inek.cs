using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Media;

namespace NDP___Proje
{
    class Inek : Hayvan
    {
        int urun = 0;
        int sure = 0;
        int kontrol = 0;
        int lira;
        SoundPlayer ses = new SoundPlayer();

        public int Enerji(int deger)
        {
            if (deger != 0)
            {
                if (deger < 8)
                {
                    deger = 0;

                }
                else
                    deger -= 8;
            }
            return deger;
        }


        public int YemVer(int deger)
        {
            if (deger != 0)
                deger = 100;
            return deger;
        }


        public string Durum(int deger, string can)
        {
            if (kontrol == 0)
            {
                if (deger == 0)
                {
                    ses.SoundLocation = "inek.wav";
                    ses.Play();
                    can = "ÖLDÜ";
                    kontrol = 1;
                }
            }
            return can;
        }


        public string Uretim(int deger, string adet)
        {
            if (deger != 0) sure++;
            if (sure == 8)
            {
                urun++;
                adet = Convert.ToString(urun) + " ADET";
                sure = 0;
            }
            return adet;
        }


        public int Satıs()
        {
            lira = urun * 5;
            urun = 0;
            return lira;
        }

    }
}
