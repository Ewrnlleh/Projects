
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Npgsql;

namespace DatabaseProgram
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        public NpgsqlConnection conn;
        string connstring = String.Format("Server=localhost;Port=5432;"+"UserId=postgres;Password=1234;Database=ProjeDatabase;");



        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            anaPanel.Visible = false;
            kisiEklePanel.Visible = true;
            dosyaOlusturPanel.Visible = false;
            ogrencilerPanel.Visible = false;
            dosyaSilPanel.Visible = false;
            kisiSilPanel.Visible = false;
            anaPanel.Visible = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            anaPanel.Visible = false;
            kisiEklePanel.Visible = false;
            dosyaOlusturPanel.Visible = true;
            ogrencilerPanel.Visible = false;
            dosyaSilPanel.Visible = false;
            kisiSilPanel.Visible = false;
            anaPanel.Visible = false;
        }

        private void button5_Click(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {

        }

        private void button8_Click(object sender, EventArgs e)
        {

        }

        private void button6_Click(object sender, EventArgs e)
        {

        }

        private void button7_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button4_Click_1(object sender, EventArgs e)
        {
            anaPanel.Visible = false;
            kisiEklePanel.Visible = false;
            dosyaOlusturPanel.Visible = false;
            ogrencilerPanel.Visible = false;
            dosyaSilPanel.Visible = false;
            kisiSilPanel.Visible = true;
       
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {

        }

        private void label15_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            conn = new NpgsqlConnection(connstring);

            anaPanel.Visible = true;
            kisiEklePanel.Visible = false;
            dosyaOlusturPanel.Visible = false;
            ogrencilerPanel.Visible = false;
            dosyaSilPanel.Visible = false;
            kisiSilPanel.Visible = false;
           


        }

        private void ogrencilerButton_Click(object sender, EventArgs e)
        {
            anaPanel.Visible = false;
            kisiEklePanel.Visible = false;
            dosyaOlusturPanel.Visible = false;
            ogrencilerPanel.Visible = true;
            dosyaSilPanel.Visible = false;
            kisiSilPanel.Visible = false;
            anaPanel.Visible = false;
        }

        private void dosyaSilButton_Click(object sender, EventArgs e)
        {
            anaPanel.Visible = false;
            kisiEklePanel.Visible = false;
            dosyaOlusturPanel.Visible = false;
            ogrencilerPanel.Visible = false;
            dosyaSilPanel.Visible = true;
            kisiSilPanel.Visible = false;
            anaPanel.Visible = false;
        }

        private void ekleButton_Click(object sender, EventArgs e)
        {
            try
            {
                conn.Open();
            }
        }
    }
}
