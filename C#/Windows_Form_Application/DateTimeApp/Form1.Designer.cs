namespace DateTimeApp
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
            this.dateTimePicker1 = new System.Windows.Forms.DateTimePicker();
            this.lbl_Date1 = new System.Windows.Forms.Label();
            this.lbl_date2 = new System.Windows.Forms.Label();
            this.lbl_Date3 = new System.Windows.Forms.Label();
            this.lbl_time1 = new System.Windows.Forms.Label();
            this.lbl_Time2 = new System.Windows.Forms.Label();
            this.btn_Show = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // dateTimePicker1
            // 
            this.dateTimePicker1.Font = new System.Drawing.Font("Microsoft YaHei", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dateTimePicker1.Location = new System.Drawing.Point(260, 48);
            this.dateTimePicker1.Name = "dateTimePicker1";
            this.dateTimePicker1.Size = new System.Drawing.Size(392, 34);
            this.dateTimePicker1.TabIndex = 0;
            // 
            // lbl_Date1
            // 
            this.lbl_Date1.AutoSize = true;
            this.lbl_Date1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_Date1.Location = new System.Drawing.Point(257, 128);
            this.lbl_Date1.Name = "lbl_Date1";
            this.lbl_Date1.Size = new System.Drawing.Size(94, 31);
            this.lbl_Date1.TabIndex = 1;
            this.lbl_Date1.Text = "Date 1";
            // 
            // lbl_date2
            // 
            this.lbl_date2.AutoSize = true;
            this.lbl_date2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_date2.Location = new System.Drawing.Point(255, 198);
            this.lbl_date2.Name = "lbl_date2";
            this.lbl_date2.Size = new System.Drawing.Size(75, 25);
            this.lbl_date2.TabIndex = 2;
            this.lbl_date2.Text = "Date 2";
            // 
            // lbl_Date3
            // 
            this.lbl_Date3.AccessibleRole = System.Windows.Forms.AccessibleRole.IpAddress;
            this.lbl_Date3.AutoSize = true;
            this.lbl_Date3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_Date3.Location = new System.Drawing.Point(255, 271);
            this.lbl_Date3.Name = "lbl_Date3";
            this.lbl_Date3.Size = new System.Drawing.Size(75, 25);
            this.lbl_Date3.TabIndex = 3;
            this.lbl_Date3.Text = "Date 3";
            // 
            // lbl_time1
            // 
            this.lbl_time1.AccessibleRole = System.Windows.Forms.AccessibleRole.IpAddress;
            this.lbl_time1.AutoSize = true;
            this.lbl_time1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_time1.Location = new System.Drawing.Point(255, 343);
            this.lbl_time1.Name = "lbl_time1";
            this.lbl_time1.Size = new System.Drawing.Size(98, 31);
            this.lbl_time1.TabIndex = 4;
            this.lbl_time1.Text = "Time 1";
            // 
            // lbl_Time2
            // 
            this.lbl_Time2.AccessibleRole = System.Windows.Forms.AccessibleRole.IpAddress;
            this.lbl_Time2.AutoSize = true;
            this.lbl_Time2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_Time2.Location = new System.Drawing.Point(257, 419);
            this.lbl_Time2.Name = "lbl_Time2";
            this.lbl_Time2.Size = new System.Drawing.Size(98, 31);
            this.lbl_Time2.TabIndex = 5;
            this.lbl_Time2.Text = "Time 2";
            // 
            // btn_Show
            // 
            this.btn_Show.Font = new System.Drawing.Font("Microsoft YaHei UI", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_Show.Location = new System.Drawing.Point(739, 550);
            this.btn_Show.Name = "btn_Show";
            this.btn_Show.Size = new System.Drawing.Size(179, 70);
            this.btn_Show.TabIndex = 6;
            this.btn_Show.Text = "Show";
            this.btn_Show.UseVisualStyleBackColor = true;
            this.btn_Show.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1083, 690);
            this.Controls.Add(this.btn_Show);
            this.Controls.Add(this.lbl_Time2);
            this.Controls.Add(this.lbl_time1);
            this.Controls.Add(this.lbl_Date3);
            this.Controls.Add(this.lbl_date2);
            this.Controls.Add(this.lbl_Date1);
            this.Controls.Add(this.dateTimePicker1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DateTimePicker dateTimePicker1;
        private System.Windows.Forms.Label lbl_Date1;
        private System.Windows.Forms.Label lbl_date2;
        private System.Windows.Forms.Label lbl_Date3;
        private System.Windows.Forms.Label lbl_time1;
        private System.Windows.Forms.Label lbl_Time2;
        private System.Windows.Forms.Button btn_Show;
    }
}

