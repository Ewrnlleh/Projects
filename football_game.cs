


using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Ödev_2
{
    public class Futbolcu
    {
        protected string AdSoyad;
        protected int FormaNo;
        protected int Hiz;
        protected int Dayaniklik;
        protected int Pas;
        protected int Sut;
        protected int Yetenek;
        protected int Kararlilik;
        protected int DogalForm;
        protected int Sans;



        public Futbolcu()
        {
            Random Rastgele = new Random();
            Hiz = Rastgele.Next(50, 100);
            Dayaniklik = Rastgele.Next(50, 100);
            Pas = Rastgele.Next(50, 100);
            Sut = Rastgele.Next(50, 100);
            Yetenek = Rastgele.Next(50, 100);
            Kararlilik = Rastgele.Next(50, 100);
            DogalForm = Rastgele.Next(50, 100);
            Sans = Rastgele.Next(50, 100);
        }

        public Futbolcu(string ad, int no)
        {
            AdSoyad = ad;
            FormaNo = no;
        }

        public virtual Boolean PasVer()
        {
            double PasSkor;

            PasSkor = Pas * 0.3 + Yetenek * 0.3 + Dayaniklik * 0.1 + DogalForm * 0.1 + Sans * 0.2;

            if (PasSkor > 60)
            {
                return true;
            }
            else
            {
                return false;
            }

        }

        public virtual void GolVurusu()
        {
            double GolSkor;

            GolSkor = Yetenek * 0.3 + Sut * 0.2 + Kararlilik * 0.1 + DogalForm * 0.1 + Hiz * 0.1 + Sans * 0.2;

        }


    }

    public class Defans : Futbolcu
    {
        private int PozisyonAlma;
        private int Kafa;
        private int Sicrama;


        public Defans(string ad, int no)
        {
            AdSoyad = ad;
            FormaNo = no;

            Random Rastgele = new Random();

            PozisyonAlma = Rastgele.Next(50, 90);
            Kafa = Rastgele.Next(50, 90);
            Sicrama = Rastgele.Next(50, 90);
            Thread.Sleep(20); // Döngü hızlı çalıştığından dolayı aynı sayı üretimini engellemek için

        }

        public override Boolean PasVer()
        {
            double PasSkor;

            PasSkor = Pas * 0.3 + Yetenek * 0.3 + Dayaniklik * 0.1 + DogalForm * 0.1 + PozisyonAlma * 0.1 + Sans * 0.2;
           
            if (PasSkor > 70)
            {
                Console.WriteLine("Pas Başarılı  " + AdSoyad + "  " + FormaNo);
                return true;
            }
            else
            {
                Console.WriteLine("Pas Verilemedi");
                return false;
            }
           

        }

        public override void GolVurusu()
        {
            double GolSkor;

            GolSkor = Yetenek * 0.3 + Sut * 0.2 + Kararlilik * 0.1 + DogalForm * 0.1 + Kafa * 0.1 + Sicrama * 0.1 + Sans * 0.1;
           
            if (GolSkor > 80)
            {
                Console.WriteLine("GOLLLL  " + AdSoyad + "  " + FormaNo);
            }

            else
                Console.WriteLine("Gol Vuruşu Başarılı Değil");
        }
    }

    public class OrtaSaha : Futbolcu
    {

        private int UzunTop;
        private int IlkDokunus;
        private int Uretkenlik;
        private int TopSurme;
        private int OzelYetenek;


        public OrtaSaha(string ad, int no)
        {
            AdSoyad = ad;
            FormaNo = no;

            Random Rastgele = new Random();

            UzunTop = Rastgele.Next(60, 100);
            IlkDokunus = Rastgele.Next(60, 100);
            Uretkenlik = Rastgele.Next(60, 100);
            TopSurme = Rastgele.Next(60, 100);
            OzelYetenek = Rastgele.Next(60, 100);
            Thread.Sleep(20);

        }

        public override Boolean PasVer()
        {
            double PasSkor;

            PasSkor = Pas * 0.3 + Yetenek * 0.2 + OzelYetenek * 0.2 + Dayaniklik * 0.1 + DogalForm * 0.1 + UzunTop * 0.1 + TopSurme * 0.1 + Sans * 0.1;
           
            if (PasSkor > 70)
            {
                Console.WriteLine("Pas Başarılı  " + AdSoyad + "  " + FormaNo);
                return true;
            }
            else
            {
                Console.WriteLine("Pas Verilemedi");
                return false;
            }

        }

        public override void GolVurusu()
        {
            double GolSkor;

            GolSkor = Yetenek * 0.3 + OzelYetenek * 0.2 + Sut * 0.2 + IlkDokunus * 0.1 + Kararlilik * 0.1 + DogalForm * 0.1 + Sans * 0.1;
           
            if (GolSkor > 80)
            {
                Console.WriteLine("GOLLLL  " + AdSoyad + "  " + FormaNo);
            }

            else
                Console.WriteLine("Gol Vuruşu Başarılı Değil");
        }


    }

    public class Forvet : Futbolcu
    {
        private int Bitiricilik;
        private int IlkDokunus;
        private int Kafa;
        private int OzelYetenek;
        private int SogukKanlilik;


        public Forvet(string ad, int no)
        {
            AdSoyad = ad;
            FormaNo = no;

            Random Rastgele = new Random();

            Bitiricilik = Rastgele.Next(70, 100);
            IlkDokunus = Rastgele.Next(70, 100);
            Kafa = Rastgele.Next(70, 100);
            OzelYetenek = Rastgele.Next(70, 100);
            SogukKanlilik = Rastgele.Next(70, 100);
            Thread.Sleep(20);

        }

        public override Boolean PasVer()
        {
            double PasSkor;

            PasSkor = Pas * 0.3 + Yetenek * 0.2 + OzelYetenek * 0.2 + Dayaniklik * 0.1 + DogalForm * 0.1 + Sans * 0.1;
         
            if (PasSkor > 70)
            {
                Console.WriteLine("Pas Başarılı  " + AdSoyad + "  " + FormaNo);
                return true;
            }
            else
            {
                Console.WriteLine("Pas Verilemedi");
                return false;
            }

        }

        public override void GolVurusu()
        {
            double GolSkor;

            GolSkor = Yetenek * 0.2 + OzelYetenek * 0.2 + Sut * 0.1 + Kafa * 0.1 + IlkDokunus * 0.1 + Bitiricilik * 0.1 + SogukKanlilik * 0.1 + Kararlilik * 0.1 + DogalForm * 0.1 + Sans * 0.1;
       
            if (GolSkor > 80)
            {
                Console.WriteLine("GOLLLL  " + AdSoyad + "  " + FormaNo);
            }

            else
                Console.WriteLine("Gol Vuruşu Başarılı Değil");
        }
    }


    class Program
    {

        public static void Mac()
        {
            List<Futbolcu> takim = new List<Futbolcu>
            {
                new Futbolcu("Mert Günok", 1),//kaleci
                new Defans("Zeki Çelik", 2),
                new Defans("Burak Bekaroğlu", 3),
                new Defans("Melih Okutan", 4),
                new Defans("Ufuk Budak", 5),
                new OrtaSaha("Emre Belezoğlu", 6),
                new OrtaSaha("Abdurrahman Çağlar", 7),
                new OrtaSaha("Billal Sebaihi", 8),
                new OrtaSaha("Erkan Süer", 9),
                new Forvet("Cenk Tosun", 10),
                new Forvet("Özgür Can Özcan", 11)
            };

            Random RastgeleSayi = new Random();

            int FormaNo;
            int Kontrol=0; // Oyuncunun kendisine pas vermesini önlemek için kontrol tanımı
            Boolean gololabilir = true;

            for (int i = 1; i <= 3; i++)
            {
                FormaNo = RastgeleSayi.Next(1,11);

                if (FormaNo != Kontrol) // Eğer aynı numaralı oyuncu gelirse döngü çalışmayacak
                {
                    if (!takim[FormaNo].PasVer())
                    {
                        gololabilir = false;
                        break;
                    }
                }
                else 
                    i = i - 1; // for döngüsünün tekrarlaması için

                Kontrol = FormaNo; // Bir sonraki döngüde sayıların aynı olup olmadığını kontrol etmek için

            }

            for (int i = 1; i <= 1; i++) 
            {
                if (gololabilir)
                {
                    FormaNo = RastgeleSayi.Next(1, 11);

                    if (FormaNo != Kontrol)
                    {
                        takim[FormaNo].GolVurusu();
                    }
                    else
                        i = i - 1;

                }
            }
        }



        static void Main(string[] args)
        {

            Mac();

            Console.ReadKey();

        }
    }


}
