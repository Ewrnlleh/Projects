

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text.RegularExpressions;

namespace Odev_3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }



        private void Btn_Click(object sender, EventArgs e)
        {
            string ıslem = txtIslem.Text;

            char[] Operator = { '+', '-', '*', '/' };


            var sayi = ıslem.Split(Operator); //sadece sayıları alma

            var isaret = Regex.Replace(txtIslem.Text, "[0-9,.]", ""); // sadece işaretleri alma


            int l = 0;
            foreach (var a in isaret)
            {

                if (a == '*' || a == '/')
                {
                    l++; // ne kadar * veya / bulunduğunu hesaplama
                }

            }



            double[] sayi2 = new double[sayi.Length - l]; // yeni sayı dizisinin boyutunu bulma

            int i = 0;
            int c = 0;
            int k = 0;

            foreach (var a in isaret)
            {

                // yeni sayı dizisine işlem yapılan iki sayının sonucunu atama
                if (a == '*')
                {
                    if (i <= sayi.Length) 
                    {
                        sayi2[k] = Convert.ToDouble(sayi[i]) * Convert.ToDouble(sayi[i + 1]);
                        k++;
                        c++;
                    }

                }
                if (a == '/')
                {
                    if (i <= sayi.Length)
                    {
                        sayi2[k] = Convert.ToDouble(sayi[i]) / Convert.ToDouble(sayi[i + 1]);
                        k++;
                        c++; 
                    }
                }

                else if (c < sayi.Length && k < (sayi.Length - l) && isaret[c] != '*' && isaret[c] != '/') 
                {
                    // çarpma veya bölme değilse normal aynı sayıyı atama
                    sayi2[k] = Convert.ToDouble(sayi[c]);
                    k++;
                }
                i++;
                c++;

            }

            if (l == 0) 
                sayi2[k] = Convert.ToDouble(sayi[c]);

            double sonuc = sayi2[0];
            var isaret2 = Regex.Replace(txtIslem.Text, "[0-9,*,/,.]", ""); // sadece + ve - işlemlerini bulundurma

            // oluşan ikinci dizedeki sayıları toplama veya çıkarma;
            for (int a = 0; a < isaret2.Length; a++)
            {
                if (isaret2[a] == '+')
                {
                    sonuc += sayi2[a + 1];
                }
                if (isaret2[a] == '-')
                {
                    sonuc -= sayi2[a + 1];
                }

            }

            //sonucu bulma;
            txtSonuc.Text = Convert.ToString(sonuc);

        }

    }
}
