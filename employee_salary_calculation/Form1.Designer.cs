


namespace Ödev_1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnBilgi = new System.Windows.Forms.Button();
            this.btnMaas = new System.Windows.Forms.Button();
            this.rtBilgi = new System.Windows.Forms.RichTextBox();
            this.lvMaas = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader4 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader5 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader6 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader7 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader8 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader9 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader10 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader11 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader12 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader13 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader14 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader15 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader16 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.label1 = new System.Windows.Forms.Label();
            this.txtTC = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // btnBilgi
            // 
            this.btnBilgi.Location = new System.Drawing.Point(12, 394);
            this.btnBilgi.Name = "btnBilgi";
            this.btnBilgi.Size = new System.Drawing.Size(200, 40);
            this.btnBilgi.TabIndex = 2;
            this.btnBilgi.Text = "Personel Bilgilerini Yükle";
            this.btnBilgi.UseVisualStyleBackColor = true;
            this.btnBilgi.Click += new System.EventHandler(this.btnBilgi_Click);
            // 
            // btnMaas
            // 
            this.btnMaas.Location = new System.Drawing.Point(218, 394);
            this.btnMaas.Name = "btnMaas";
            this.btnMaas.Size = new System.Drawing.Size(200, 40);
            this.btnMaas.TabIndex = 3;
            this.btnMaas.Text = "Personel Maaşını Hesapla";
            this.btnMaas.UseVisualStyleBackColor = true;
            this.btnMaas.Click += new System.EventHandler(this.btnMaas_Click);
            // 
            // rtBilgi
            // 
            this.rtBilgi.Location = new System.Drawing.Point(12, 12);
            this.rtBilgi.Name = "rtBilgi";
            this.rtBilgi.ReadOnly = true;
            this.rtBilgi.Size = new System.Drawing.Size(1000, 170);
            this.rtBilgi.TabIndex = 4;
            this.rtBilgi.Text = "";
            // 
            // lvMaas
            // 
            this.lvMaas.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3,
            this.columnHeader4,
            this.columnHeader5,
            this.columnHeader6,
            this.columnHeader7,
            this.columnHeader8,
            this.columnHeader9,
            this.columnHeader10,
            this.columnHeader11,
            this.columnHeader12,
            this.columnHeader13,
            this.columnHeader14,
            this.columnHeader15,
            this.columnHeader16});
            this.lvMaas.FullRowSelect = true;
            this.lvMaas.GridLines = true;
            this.lvMaas.Location = new System.Drawing.Point(12, 188);
            this.lvMaas.Name = "lvMaas";
            this.lvMaas.Size = new System.Drawing.Size(1000, 200);
            this.lvMaas.TabIndex = 5;
            this.lvMaas.UseCompatibleStateImageBehavior = false;
            this.lvMaas.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "TC";
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "Adı";
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "Soyadı";
            // 
            // columnHeader4
            // 
            this.columnHeader4.Text = "Yaş";
            // 
            // columnHeader5
            // 
            this.columnHeader5.Text = "Çalışma süresi";
            // 
            // columnHeader6
            // 
            this.columnHeader6.Text = "Evlilik durumu";
            // 
            // columnHeader7
            // 
            this.columnHeader7.Text = "Eşi çalışıyormu";
            // 
            // columnHeader8
            // 
            this.columnHeader8.Text = "Çocuk sayısı";
            // 
            // columnHeader9
            // 
            this.columnHeader9.Text = "Taban maaş";
            // 
            // columnHeader10
            // 
            this.columnHeader10.Text = "Makam tazminatı";
            // 
            // columnHeader11
            // 
            this.columnHeader11.Text = "İdari görev tazminatı";
            // 
            // columnHeader12
            // 
            this.columnHeader12.Text = "Fazla mesai saati";
            // 
            // columnHeader13
            // 
            this.columnHeader13.Text = "Fazla mesai saat ücreti";
            // 
            // columnHeader14
            // 
            this.columnHeader14.Text = "Vergi matrahı";
            // 
            // columnHeader15
            // 
            this.columnHeader15.Text = "Personel resmi yolu";
            // 
            // columnHeader16
            // 
            this.columnHeader16.Text = "NET MAAŞ";
            this.columnHeader16.Width = 95;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(604, 415);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(182, 17);
            this.label1.TabIndex = 6;
            this.label1.Text = "TC Kimlik Numarası İle Arat:";
            // 
            // txtTC
            // 
            this.txtTC.Location = new System.Drawing.Point(792, 412);
            this.txtTC.Name = "txtTC";
            this.txtTC.Size = new System.Drawing.Size(220, 22);
            this.txtTC.TabIndex = 7;
            this.txtTC.TextChanged += new System.EventHandler(this.txtTC_TextChanged);
            this.txtTC.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtTC_KeyPress);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1023, 450);
            this.Controls.Add(this.txtTC);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.lvMaas);
            this.Controls.Add(this.rtBilgi);
            this.Controls.Add(this.btnMaas);
            this.Controls.Add(this.btnBilgi);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button btnBilgi;
        private System.Windows.Forms.Button btnMaas;
        private System.Windows.Forms.RichTextBox rtBilgi;
        private System.Windows.Forms.ListView lvMaas;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtTC;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.ColumnHeader columnHeader4;
        private System.Windows.Forms.ColumnHeader columnHeader5;
        private System.Windows.Forms.ColumnHeader columnHeader6;
        private System.Windows.Forms.ColumnHeader columnHeader7;
        private System.Windows.Forms.ColumnHeader columnHeader8;
        private System.Windows.Forms.ColumnHeader columnHeader9;
        private System.Windows.Forms.ColumnHeader columnHeader10;
        private System.Windows.Forms.ColumnHeader columnHeader11;
        private System.Windows.Forms.ColumnHeader columnHeader12;
        private System.Windows.Forms.ColumnHeader columnHeader13;
        private System.Windows.Forms.ColumnHeader columnHeader14;
        private System.Windows.Forms.ColumnHeader columnHeader15;
        private System.Windows.Forms.ColumnHeader columnHeader16;
    }
}

