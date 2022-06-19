


using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Ödev_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnBilgi_Click(object sender, EventArgs e)
        {
            // Dosya seçme menüsünü açar ve Bilgileri richtextboxa aktarır.
            OpenFileDialog dosyaSec = new OpenFileDialog();
            if (dosyaSec.ShowDialog() == DialogResult.OK)
            {
                string dosyaYolu = dosyaSec.FileName;
                StreamReader dosyaOku = new StreamReader(File.OpenRead(dosyaYolu));
                rtBilgi.Text = dosyaOku.ReadToEnd();
                dosyaOku.Dispose();
            }

           
    
        }

        private void btnMaas_Click(object sender, EventArgs e)
        {
            // Richtextboxda bilgi var ise hesaplamalara başla
            if (rtBilgi.Text != "")
            {   
                lvMaas.Items.Clear(); // Tekrar hesaplama butonuna basıldığında bilgileri yenilemek için gerekli
                string hepsi = rtBilgi.Text; // hepsi stringine bilgileri aktar
                string[] satirlar = hepsi.Split('\n'); // bilgileri satırlara ayır

                foreach (string s in satirlar)
                {
                    string[] kelimeler = s.Split(' '); // bilgileri kelimelere ayır

                    // Her Kelimeyi Uygun Verilere Ata
                    double tc = Convert.ToDouble(kelimeler[0]);
                    string adi = kelimeler[1];
                    string soyadi = kelimeler[2];
                    double yas = Convert.ToDouble(kelimeler[3]);
                    double calismaSuresi = Convert.ToDouble(kelimeler[4]);
                    char evlilikDurumu = Convert.ToChar(kelimeler[5]);
                    char esiCalisiyormu = Convert.ToChar(kelimeler[6]);
                    double cocukSayisi = Convert.ToDouble(kelimeler[7]);
                    double tabanMaas = Convert.ToDouble(kelimeler[8]);
                    double makamTazminati = Convert.ToDouble(kelimeler[9]);
                    double idariGorevTazminati = Convert.ToDouble(kelimeler[10]);
                    double fazlaMesaiSaati = Convert.ToDouble(kelimeler[11]);
                    double fazlaMesaiSaatiUcreti = Convert.ToDouble(kelimeler[12]);
                    double vergiMatrahi = Convert.ToDouble(kelimeler[13]);
                    string personelResmiYolu = kelimeler[14];

                    double burutMaas = 0;
                    double damgaVergisi = 0;
                    double gelirVergisi = 0;
                    double emekliKesintisi = 0;
                    double netMaas = 0;

                    if (evlilikDurumu == 'B')// Bekar ise
                    {
                        burutMaas = tabanMaas + makamTazminati + idariGorevTazminati + cocukSayisi * 30 + fazlaMesaiSaati * fazlaMesaiSaatiUcreti;
                    }
                    else if (evlilikDurumu == 'E' && esiCalisiyormu == 'E') // Evli ve eşi çalışıyor ise
                    {
                        burutMaas = tabanMaas + makamTazminati + idariGorevTazminati + cocukSayisi * 30 + fazlaMesaiSaati * fazlaMesaiSaatiUcreti;
                    }
                    else if (evlilikDurumu == 'E' && esiCalisiyormu == 'H') // Evli ve eşi çalışmıyor ise
                    {
                        burutMaas = tabanMaas + makamTazminati + idariGorevTazminati + 200 + cocukSayisi * 30 + fazlaMesaiSaati * fazlaMesaiSaatiUcreti;
                    }


                    damgaVergisi = (burutMaas * 10) / 100;


                    if (vergiMatrahi < 10000) // 10000 TL den küçük iken
                    {
                        gelirVergisi = (burutMaas * 15) / 100;
                    }
                    else if (vergiMatrahi >= 10000 && vergiMatrahi < 20000) // 10000 ile 20000 arasında
                    {
                        gelirVergisi = (burutMaas * 20) / 100;
                    }
                    else if (vergiMatrahi >= 20000 && vergiMatrahi < 30000) // 20000 ile 30000 arasında
                    {
                        gelirVergisi = (burutMaas * 25) / 100;
                    }
                    else if (vergiMatrahi >= 30000) // 30000 TL den büyük veya eşit
                    {
                        gelirVergisi = (burutMaas * 30) / 100;
                    }


                    emekliKesintisi = (burutMaas * 15) / 100;


                    netMaas = burutMaas - (emekliKesintisi + gelirVergisi + damgaVergisi);

                    
                    // Hesaplanan Bilgileri NetMaaş ile Birlikte Listviewe Ekler
                    ListViewItem Kullanici = new ListViewItem(kelimeler);
                    Kullanici.SubItems.Add(Convert.ToString(netMaas));
                    lvMaas.Items.Add(Kullanici);


                }
            }

            // Eğer richtextboxda bilgi yoksa
            else
                MessageBox.Show("Lütfen Önce Personel Bilgilerini Yükleyiniz...");


        }


        private void txtTC_TextChanged(object sender, EventArgs e)
        {


            // TC Textboxı silindiğinde maaş butonunu çalıştır
            if (txtTC.Text == "")
            {
                btnMaas_Click(sender,e);
            }

            // TC'si yazılan personelin bilgilerini listview de göster
            var list = lvMaas.Items
                                .Cast<ListViewItem>()
                                .Where(
                                    x => x.SubItems
                                          .Cast<ListViewItem.ListViewSubItem>()
                                          .Any(y => y.Text.Contains(txtTC.Text)))
                                .ToArray();
            lvMaas.Items.Clear();
            lvMaas.Items.AddRange(list);

        }

        // Tc Textboxına sadece sayı girişi olmasını sağlar.
        private void txtTC_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = !char.IsDigit(e.KeyChar) && !char.IsControl(e.KeyChar);
        }


    }   
}

