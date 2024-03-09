namespace DialogBox
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
            this.btn_Yes = new System.Windows.Forms.Button();
            this.lbl_Cancel = new System.Windows.Forms.Label();
            this.lbl_YesNo = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // btn_Yes
            // 
            this.btn_Yes.Font = new System.Drawing.Font("Microsoft YaHei", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_Yes.Location = new System.Drawing.Point(621, 160);
            this.btn_Yes.Name = "btn_Yes";
            this.btn_Yes.Size = new System.Drawing.Size(114, 50);
            this.btn_Yes.TabIndex = 0;
            this.btn_Yes.Text = "Yes";
            this.btn_Yes.UseVisualStyleBackColor = true;
            this.btn_Yes.Click += new System.EventHandler(this.btn_Yes_Click);
            // 
            // lbl_Cancel
            // 
            this.lbl_Cancel.AutoSize = true;
            this.lbl_Cancel.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_Cancel.ForeColor = System.Drawing.Color.Crimson;
            this.lbl_Cancel.Location = new System.Drawing.Point(173, 355);
            this.lbl_Cancel.Name = "lbl_Cancel";
            this.lbl_Cancel.Size = new System.Drawing.Size(54, 36);
            this.lbl_Cancel.TabIndex = 1;
            this.lbl_Cancel.Text = ".....";
            // 
            // lbl_YesNo
            // 
            this.lbl_YesNo.AutoSize = true;
            this.lbl_YesNo.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_YesNo.ForeColor = System.Drawing.Color.LimeGreen;
            this.lbl_YesNo.Location = new System.Drawing.Point(173, 432);
            this.lbl_YesNo.Name = "lbl_YesNo";
            this.lbl_YesNo.Size = new System.Drawing.Size(43, 29);
            this.lbl_YesNo.TabIndex = 2;
            this.lbl_YesNo.Text = ".....";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1333, 818);
            this.Controls.Add(this.lbl_YesNo);
            this.Controls.Add(this.lbl_Cancel);
            this.Controls.Add(this.btn_Yes);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btn_Yes;
        private System.Windows.Forms.Label lbl_Cancel;
        private System.Windows.Forms.Label lbl_YesNo;
    }
}

