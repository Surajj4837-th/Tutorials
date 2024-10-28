namespace DatabaseConnection
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
            this.button1 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.Nametxt = new System.Windows.Forms.TextBox();
            this.MaleRB = new System.Windows.Forms.RadioButton();
            this.Age = new System.Windows.Forms.Label();
            this.Agetxt = new System.Windows.Forms.TextBox();
            this.Phone = new System.Windows.Forms.Label();
            this.Phonetxt = new System.Windows.Forms.TextBox();
            this.FemaleRB = new System.Windows.Forms.RadioButton();
            this.Savebtn = new System.Windows.Forms.Button();
            this.showbtn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.button1.Location = new System.Drawing.Point(251, 0);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(40, 40);
            this.button1.TabIndex = 1;
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(50, 18);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(57, 20);
            this.label1.TabIndex = 2;
            this.label1.Text = "Name";
            // 
            // Nametxt
            // 
            this.Nametxt.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.Nametxt.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Nametxt.Location = new System.Drawing.Point(48, 46);
            this.Nametxt.Name = "Nametxt";
            this.Nametxt.Size = new System.Drawing.Size(125, 27);
            this.Nametxt.TabIndex = 3;
            // 
            // MaleRB
            // 
            this.MaleRB.AutoSize = true;
            this.MaleRB.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.MaleRB.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.MaleRB.Location = new System.Drawing.Point(50, 263);
            this.MaleRB.Name = "MaleRB";
            this.MaleRB.Size = new System.Drawing.Size(70, 24);
            this.MaleRB.TabIndex = 4;
            this.MaleRB.TabStop = true;
            this.MaleRB.Text = "Male";
            this.MaleRB.UseVisualStyleBackColor = false;
            // 
            // Age
            // 
            this.Age.AutoSize = true;
            this.Age.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.Age.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Age.Location = new System.Drawing.Point(50, 97);
            this.Age.Name = "Age";
            this.Age.Size = new System.Drawing.Size(41, 20);
            this.Age.TabIndex = 2;
            this.Age.Text = "Age";
            // 
            // Agetxt
            // 
            this.Agetxt.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.Agetxt.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Agetxt.Location = new System.Drawing.Point(48, 125);
            this.Agetxt.Name = "Agetxt";
            this.Agetxt.Size = new System.Drawing.Size(125, 27);
            this.Agetxt.TabIndex = 3;
            // 
            // Phone
            // 
            this.Phone.AutoSize = true;
            this.Phone.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.Phone.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Phone.Location = new System.Drawing.Point(50, 171);
            this.Phone.Name = "Phone";
            this.Phone.Size = new System.Drawing.Size(61, 20);
            this.Phone.TabIndex = 2;
            this.Phone.Text = "Phone";
            // 
            // Phonetxt
            // 
            this.Phonetxt.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.Phonetxt.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Phonetxt.Location = new System.Drawing.Point(48, 199);
            this.Phonetxt.Name = "Phonetxt";
            this.Phonetxt.Size = new System.Drawing.Size(125, 27);
            this.Phonetxt.TabIndex = 3;
            // 
            // FemaleRB
            // 
            this.FemaleRB.AutoSize = true;
            this.FemaleRB.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.FemaleRB.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FemaleRB.Location = new System.Drawing.Point(50, 307);
            this.FemaleRB.Name = "FemaleRB";
            this.FemaleRB.Size = new System.Drawing.Size(91, 24);
            this.FemaleRB.TabIndex = 4;
            this.FemaleRB.TabStop = true;
            this.FemaleRB.Text = "Female";
            this.FemaleRB.UseVisualStyleBackColor = false;
            // 
            // Savebtn
            // 
            this.Savebtn.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.Savebtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Savebtn.Location = new System.Drawing.Point(42, 378);
            this.Savebtn.Name = "Savebtn";
            this.Savebtn.Size = new System.Drawing.Size(84, 28);
            this.Savebtn.TabIndex = 5;
            this.Savebtn.Text = "Save";
            this.Savebtn.UseVisualStyleBackColor = false;
            this.Savebtn.Click += new System.EventHandler(this.Savebtn_Click);
            // 
            // showbtn
            // 
            this.showbtn.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.showbtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.showbtn.Location = new System.Drawing.Point(146, 378);
            this.showbtn.Name = "showbtn";
            this.showbtn.Size = new System.Drawing.Size(84, 28);
            this.showbtn.TabIndex = 7;
            this.showbtn.Text = "Show";
            this.showbtn.UseVisualStyleBackColor = false;
            this.showbtn.Click += new System.EventHandler(this.showbtn_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.ClientSize = new System.Drawing.Size(292, 450);
            this.Controls.Add(this.showbtn);
            this.Controls.Add(this.Savebtn);
            this.Controls.Add(this.FemaleRB);
            this.Controls.Add(this.MaleRB);
            this.Controls.Add(this.Phonetxt);
            this.Controls.Add(this.Phone);
            this.Controls.Add(this.Agetxt);
            this.Controls.Add(this.Age);
            this.Controls.Add(this.Nametxt);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button1);
            this.ForeColor = System.Drawing.Color.RosyBrown;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.IsMdiContainer = true;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox Nametxt;
        private System.Windows.Forms.RadioButton MaleRB;
        private System.Windows.Forms.Label Age;
        private System.Windows.Forms.TextBox Agetxt;
        private System.Windows.Forms.Label Phone;
        private System.Windows.Forms.TextBox Phonetxt;
        private System.Windows.Forms.RadioButton FemaleRB;
        private System.Windows.Forms.Button Savebtn;
        private System.Windows.Forms.Button showbtn;
    }
}

