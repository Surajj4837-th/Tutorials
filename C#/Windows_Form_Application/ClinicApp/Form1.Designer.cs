namespace ClinicApp
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
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.lbl_ClinicName = new System.Windows.Forms.Label();
            this.lbl_ClinicAddress = new System.Windows.Forms.Label();
            this.lbl_Rating = new System.Windows.Forms.Label();
            this.lbl_Contact = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // comboBox1
            // 
            this.comboBox1.Font = new System.Drawing.Font("MS PGothic", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(21, 60);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(232, 26);
            this.comboBox1.TabIndex = 0;
            this.comboBox1.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft YaHei", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(21, 26);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(140, 30);
            this.label1.TabIndex = 1;
            this.label1.Text = "Select Clinic";
            // 
            // lbl_ClinicName
            // 
            this.lbl_ClinicName.AutoSize = true;
            this.lbl_ClinicName.Font = new System.Drawing.Font("Microsoft YaHei", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_ClinicName.Location = new System.Drawing.Point(21, 110);
            this.lbl_ClinicName.Name = "lbl_ClinicName";
            this.lbl_ClinicName.Size = new System.Drawing.Size(112, 24);
            this.lbl_ClinicName.TabIndex = 2;
            this.lbl_ClinicName.Text = "Select Clinic";
            // 
            // lbl_ClinicAddress
            // 
            this.lbl_ClinicAddress.AutoSize = true;
            this.lbl_ClinicAddress.Font = new System.Drawing.Font("Microsoft YaHei", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_ClinicAddress.Location = new System.Drawing.Point(21, 155);
            this.lbl_ClinicAddress.Name = "lbl_ClinicAddress";
            this.lbl_ClinicAddress.Size = new System.Drawing.Size(112, 24);
            this.lbl_ClinicAddress.TabIndex = 3;
            this.lbl_ClinicAddress.Text = "Select Clinic";
            // 
            // lbl_Rating
            // 
            this.lbl_Rating.AutoSize = true;
            this.lbl_Rating.Font = new System.Drawing.Font("Microsoft YaHei", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_Rating.Location = new System.Drawing.Point(21, 207);
            this.lbl_Rating.Name = "lbl_Rating";
            this.lbl_Rating.Size = new System.Drawing.Size(112, 24);
            this.lbl_Rating.TabIndex = 4;
            this.lbl_Rating.Text = "Select Clinic";
            // 
            // lbl_Contact
            // 
            this.lbl_Contact.AutoSize = true;
            this.lbl_Contact.Font = new System.Drawing.Font("Microsoft YaHei", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_Contact.Location = new System.Drawing.Point(21, 247);
            this.lbl_Contact.Name = "lbl_Contact";
            this.lbl_Contact.Size = new System.Drawing.Size(112, 24);
            this.lbl_Contact.TabIndex = 5;
            this.lbl_Contact.Text = "Select Clinic";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.lbl_Contact);
            this.Controls.Add(this.lbl_Rating);
            this.Controls.Add(this.lbl_ClinicAddress);
            this.Controls.Add(this.lbl_ClinicName);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.comboBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lbl_ClinicName;
        private System.Windows.Forms.Label lbl_ClinicAddress;
        private System.Windows.Forms.Label lbl_Rating;
        private System.Windows.Forms.Label lbl_Contact;
    }
}

