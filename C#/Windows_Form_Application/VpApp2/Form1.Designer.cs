namespace VpApp2
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
            this.FirstName = new System.Windows.Forms.TextBox();
            this.FName = new System.Windows.Forms.Label();
            this.lname = new System.Windows.Forms.Label();
            this.LastName = new System.Windows.Forms.TextBox();
            this.mail = new System.Windows.Forms.Label();
            this.MailID = new System.Windows.Forms.TextBox();
            this.services = new System.Windows.Forms.GroupBox();
            this.lbl_sms = new System.Windows.Forms.Label();
            this.Chk_Trans_report = new System.Windows.Forms.CheckBox();
            this.Chk_reports = new System.Windows.Forms.CheckBox();
            this.Chk_SMS_not = new System.Windows.Forms.CheckBox();
            this.lbl_report = new System.Windows.Forms.Label();
            this.lbl_trn_report = new System.Windows.Forms.Label();
            this.btn_signup = new System.Windows.Forms.Button();
            this.services.SuspendLayout();
            this.SuspendLayout();
            // 
            // FirstName
            // 
            this.FirstName.Location = new System.Drawing.Point(261, 45);
            this.FirstName.Name = "FirstName";
            this.FirstName.Size = new System.Drawing.Size(366, 22);
            this.FirstName.TabIndex = 0;
            // 
            // FName
            // 
            this.FName.AutoSize = true;
            this.FName.Location = new System.Drawing.Point(53, 48);
            this.FName.Name = "FName";
            this.FName.Size = new System.Drawing.Size(72, 16);
            this.FName.TabIndex = 1;
            this.FName.Text = "First Name";
            // 
            // lname
            // 
            this.lname.AutoSize = true;
            this.lname.Location = new System.Drawing.Point(53, 95);
            this.lname.Name = "lname";
            this.lname.Size = new System.Drawing.Size(72, 16);
            this.lname.TabIndex = 3;
            this.lname.Text = "Last Name";
            // 
            // LastName
            // 
            this.LastName.Location = new System.Drawing.Point(261, 92);
            this.LastName.Name = "LastName";
            this.LastName.Size = new System.Drawing.Size(366, 22);
            this.LastName.TabIndex = 2;
            // 
            // mail
            // 
            this.mail.AutoSize = true;
            this.mail.Location = new System.Drawing.Point(53, 143);
            this.mail.Name = "mail";
            this.mail.Size = new System.Drawing.Size(57, 16);
            this.mail.TabIndex = 5;
            this.mail.Text = "Emali ID";
            // 
            // MailID
            // 
            this.MailID.Location = new System.Drawing.Point(261, 140);
            this.MailID.Name = "MailID";
            this.MailID.Size = new System.Drawing.Size(366, 22);
            this.MailID.TabIndex = 4;
            // 
            // services
            // 
            this.services.Controls.Add(this.lbl_trn_report);
            this.services.Controls.Add(this.lbl_report);
            this.services.Controls.Add(this.lbl_sms);
            this.services.Controls.Add(this.Chk_Trans_report);
            this.services.Controls.Add(this.Chk_reports);
            this.services.Controls.Add(this.Chk_SMS_not);
            this.services.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.services.Location = new System.Drawing.Point(56, 259);
            this.services.Name = "services";
            this.services.Size = new System.Drawing.Size(395, 194);
            this.services.TabIndex = 6;
            this.services.TabStop = false;
            this.services.Text = "Services";
            this.services.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // lbl_sms
            // 
            this.lbl_sms.AutoSize = true;
            this.lbl_sms.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_sms.Location = new System.Drawing.Point(274, 51);
            this.lbl_sms.Name = "lbl_sms";
            this.lbl_sms.Size = new System.Drawing.Size(0, 28);
            this.lbl_sms.TabIndex = 7;
            this.lbl_sms.UseCompatibleTextRendering = true;
            this.lbl_sms.Click += new System.EventHandler(this.sms_Click);
            // 
            // Chk_Trans_report
            // 
            this.Chk_Trans_report.AutoSize = true;
            this.Chk_Trans_report.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Chk_Trans_report.Location = new System.Drawing.Point(18, 147);
            this.Chk_Trans_report.Name = "Chk_Trans_report";
            this.Chk_Trans_report.Size = new System.Drawing.Size(209, 29);
            this.Chk_Trans_report.TabIndex = 9;
            this.Chk_Trans_report.Text = "Transaction Reports";
            this.Chk_Trans_report.UseVisualStyleBackColor = true;
            // 
            // Chk_reports
            // 
            this.Chk_reports.AutoSize = true;
            this.Chk_reports.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Chk_reports.Location = new System.Drawing.Point(17, 98);
            this.Chk_reports.Name = "Chk_reports";
            this.Chk_reports.Size = new System.Drawing.Size(101, 29);
            this.Chk_reports.TabIndex = 8;
            this.Chk_reports.Text = "Reports";
            this.Chk_reports.UseVisualStyleBackColor = true;
            // 
            // Chk_SMS_not
            // 
            this.Chk_SMS_not.AutoSize = true;
            this.Chk_SMS_not.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Chk_SMS_not.Location = new System.Drawing.Point(17, 51);
            this.Chk_SMS_not.Name = "Chk_SMS_not";
            this.Chk_SMS_not.Size = new System.Drawing.Size(179, 29);
            this.Chk_SMS_not.TabIndex = 7;
            this.Chk_SMS_not.Text = "SMS Notification";
            this.Chk_SMS_not.UseVisualStyleBackColor = true;
            // 
            // lbl_report
            // 
            this.lbl_report.AutoSize = true;
            this.lbl_report.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_report.Location = new System.Drawing.Point(274, 98);
            this.lbl_report.Name = "lbl_report";
            this.lbl_report.Size = new System.Drawing.Size(0, 25);
            this.lbl_report.TabIndex = 10;
            // 
            // lbl_trn_report
            // 
            this.lbl_trn_report.AutoSize = true;
            this.lbl_trn_report.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_trn_report.Location = new System.Drawing.Point(274, 147);
            this.lbl_trn_report.Name = "lbl_trn_report";
            this.lbl_trn_report.Size = new System.Drawing.Size(0, 25);
            this.lbl_trn_report.TabIndex = 11;
            // 
            // btn_signup
            // 
            this.btn_signup.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_signup.Location = new System.Drawing.Point(421, 487);
            this.btn_signup.Name = "btn_signup";
            this.btn_signup.Size = new System.Drawing.Size(206, 44);
            this.btn_signup.TabIndex = 7;
            this.btn_signup.Text = "Sign Up";
            this.btn_signup.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(723, 600);
            this.Controls.Add(this.btn_signup);
            this.Controls.Add(this.services);
            this.Controls.Add(this.mail);
            this.Controls.Add(this.MailID);
            this.Controls.Add(this.lname);
            this.Controls.Add(this.LastName);
            this.Controls.Add(this.FName);
            this.Controls.Add(this.FirstName);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.services.ResumeLayout(false);
            this.services.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox FirstName;
        private System.Windows.Forms.Label FName;
        private System.Windows.Forms.Label lname;
        private System.Windows.Forms.TextBox LastName;
        private System.Windows.Forms.Label mail;
        private System.Windows.Forms.TextBox MailID;
        private System.Windows.Forms.GroupBox services;
        private System.Windows.Forms.CheckBox Chk_Trans_report;
        private System.Windows.Forms.CheckBox Chk_reports;
        private System.Windows.Forms.CheckBox Chk_SMS_not;
        private System.Windows.Forms.Label lbl_sms;
        private System.Windows.Forms.Label lbl_trn_report;
        private System.Windows.Forms.Label lbl_report;
        private System.Windows.Forms.Button btn_signup;
    }
}

