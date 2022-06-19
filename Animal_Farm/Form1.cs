using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace NDP___Proje
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        Tavuk tavuk = new Tavuk();
        Ordek ordek = new Ordek();
        Inek inek = new Inek();
        Keci keci = new Keci();

        int saniye = 0;
        int kasa = 0;


        private void btnSatOrdek_Click(object sender, EventArgs e)
        {
            kasa += ordek.Satıs();
            lblKasa.Text = Convert.ToString(kasa) + " TL";
            lblOrdek.Text = "0 ADET";
        }
        private void btnSatInek_Click(object sender, EventArgs e)
        {
            kasa += inek.Satıs();
            lblKasa.Text = Convert.ToString(kasa) + " TL";
            lblInek.Text = "0 ADET";
        }
        private void btnSatKeci_Click(object sender, EventArgs e)
        {
            kasa += keci.Satıs();
            lblKasa.Text = Convert.ToString(kasa) + " TL";
            lblKeci.Text = "0 ADET";
        }
        private void btnSatTavuk_Click(object sender, EventArgs e)
        {
            kasa += tavuk.Satıs();
            lblKasa.Text = Convert.ToString(kasa) + " TL";
            lblTavuk.Text = "0 ADET";   
        }



        private void timer1_Tick(object sender, EventArgs e)
        {

            saniye++;
            lblSure.Text = Convert.ToString(saniye) + " SN";

            progTavuk.Value = tavuk.Enerji(progTavuk.Value);
            progOrdek.Value = ordek.Enerji(progOrdek.Value);
            progInek.Value = inek.Enerji(progInek.Value);
            progKeci.Value = keci.Enerji(progKeci.Value);

            lblTavuk.Text = tavuk.Uretim(progTavuk.Value, lblTavuk.Text);
            lblOrdek.Text = ordek.Uretim(progOrdek.Value, lblOrdek.Text);
            lblInek.Text = inek.Uretim(progInek.Value, lblInek.Text);
            lblKeci.Text = keci.Uretim(progKeci.Value, lblKeci.Text);

            txtTavukCan.Text = tavuk.Durum(progTavuk.Value, txtTavukCan.Text);
            txtOrdekCan.Text = ordek.Durum(progOrdek.Value, txtOrdekCan.Text);
            txtInekCan.Text = inek.Durum(progInek.Value, txtInekCan.Text);
            txtKeciCan.Text = keci.Durum(progKeci.Value, txtKeciCan.Text);

        }


        private void btnYemTavuk_Click(object sender, EventArgs e)
        {
            progTavuk.Value = tavuk.YemVer(progTavuk.Value);
        }

        private void btnYemOrdek_Click(object sender, EventArgs e)
        {
            progOrdek.Value = ordek.YemVer(progOrdek.Value);
        }

        private void btnYemInek_Click(object sender, EventArgs e)
        {
            progInek.Value = inek.YemVer(progInek.Value);
        }

        private void btnYemKeci_Click(object sender, EventArgs e)
        {
            progKeci.Value = keci.YemVer(progKeci.Value);
        }

    }
}
