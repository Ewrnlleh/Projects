

namespace Odev_3
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
            this.txtIslem = new System.Windows.Forms.TextBox();
            this.txtSonuc = new System.Windows.Forms.TextBox();
            this.btn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // txtIslem
            // 
            this.txtIslem.Location = new System.Drawing.Point(47, 70);
            this.txtIslem.Name = "txtIslem";
            this.txtIslem.Size = new System.Drawing.Size(290, 22);
            this.txtIslem.TabIndex = 0;
            // 
            // txtSonuc
            // 
            this.txtSonuc.Location = new System.Drawing.Point(47, 120);
            this.txtSonuc.Name = "txtSonuc";
            this.txtSonuc.ReadOnly = true;
            this.txtSonuc.Size = new System.Drawing.Size(290, 22);
            this.txtSonuc.TabIndex = 1;
            // 
            // btn
            // 
            this.btn.Location = new System.Drawing.Point(82, 170);
            this.btn.Name = "btn";
            this.btn.Size = new System.Drawing.Size(220, 80);
            this.btn.TabIndex = 2;
            this.btn.Text = "Hesapla";
            this.btn.UseVisualStyleBackColor = true;
            this.btn.Click += new System.EventHandler(this.Btn_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(392, 316);
            this.Controls.Add(this.btn);
            this.Controls.Add(this.txtSonuc);
            this.Controls.Add(this.txtIslem);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtIslem;
        private System.Windows.Forms.TextBox txtSonuc;
        private System.Windows.Forms.Button btn;
    }
}

