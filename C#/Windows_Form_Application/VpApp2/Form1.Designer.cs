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
            this.tb_FirstName = new System.Windows.Forms.TextBox();
            this.lbl_fname = new System.Windows.Forms.Label();
            this.tb_LastName = new System.Windows.Forms.TextBox();
            this.lbl_mail = new System.Windows.Forms.Label();
            this.tb_MailID = new System.Windows.Forms.TextBox();
            this.services = new System.Windows.Forms.GroupBox();
            this.lbl_trn_report = new System.Windows.Forms.Label();
            this.lbl_report = new System.Windows.Forms.Label();
            this.lbl_sms = new System.Windows.Forms.Label();
            this.Chk_Trans_report = new System.Windows.Forms.CheckBox();
            this.Chk_reports = new System.Windows.Forms.CheckBox();
            this.Chk_SMS_not = new System.Windows.Forms.CheckBox();
            this.btn_signup = new System.Windows.Forms.Button();
            this.lbl_lname = new System.Windows.Forms.Label();
            this.services.SuspendLayout();
            this.SuspendLayout();
            // 
            // tb_FirstName
            // 
            this.tb_FirstName.Location = new System.Drawing.Point(261, 45);
            this.tb_FirstName.Name = "tb_FirstName";
            this.tb_FirstName.Size = new System.Drawing.Size(366, 22);
            this.tb_FirstName.TabIndex = 0;
            // 
            // lbl_fname
            // 
            this.lbl_fname.AutoSize = true;
            this.lbl_fname.Location = new System.Drawing.Point(53, 48);
            this.lbl_fname.Name = "lbl_fname";
            this.lbl_fname.Size = new System.Drawing.Size(72, 16);
            this.lbl_fname.TabIndex = 1;
            this.lbl_fname.Text = "First Name";
            // 
            // tb_LastName
            // 
            this.tb_LastName.Location = new System.Drawing.Point(261, 92);
            this.tb_LastName.Name = "tb_LastName";
            this.tb_LastName.Size = new System.Drawing.Size(366, 22);
            this.tb_LastName.TabIndex = 2;
            // 
            // lbl_mail
            // 
            this.lbl_mail.AutoSize = true;
            this.lbl_mail.Location = new System.Drawing.Point(53, 143);
            this.lbl_mail.Name = "lbl_mail";
            this.lbl_mail.Size = new System.Drawing.Size(57, 16);
            this.lbl_mail.TabIndex = 5;
            this.lbl_mail.Text = "Emali ID";
            // 
            // tb_MailID
            // 
            this.tb_MailID.Location = new System.Drawing.Point(261, 140);
            this.tb_MailID.Name = "tb_MailID";
            this.tb_MailID.Size = new System.Drawing.Size(366, 22);
            this.tb_MailID.TabIndex = 4;
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
            this.services.Size = new System.Drawing.Size(917, 194);
            this.services.TabIndex = 6;
            this.services.TabStop = false;
            this.services.Text = "Services";
            // 
            // lbl_trn_report
            // 
            this.lbl_trn_report.AutoSize = true;
            this.lbl_trn_report.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_trn_report.ForeColor = System.Drawing.Color.Tomato;
            this.lbl_trn_report.Location = new System.Drawing.Point(274, 147);
            this.lbl_trn_report.Name = "lbl_trn_report";
            this.lbl_trn_report.Size = new System.Drawing.Size(65, 31);
            this.lbl_trn_report.TabIndex = 11;
            this.lbl_trn_report.Text = "........";
            // 
            // lbl_report
            // 
            this.lbl_report.AutoSize = true;
            this.lbl_report.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_report.ForeColor = System.Drawing.Color.Tomato;
            this.lbl_report.Location = new System.Drawing.Point(274, 98);
            this.lbl_report.Name = "lbl_report";
            this.lbl_report.Size = new System.Drawing.Size(65, 31);
            this.lbl_report.TabIndex = 10;
            this.lbl_report.Text = "........";
            // 
            // lbl_sms
            // 
            this.lbl_sms.AutoSize = true;
            this.lbl_sms.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_sms.ForeColor = System.Drawing.Color.Tomato;
            this.lbl_sms.Location = new System.Drawing.Point(274, 51);
            this.lbl_sms.Name = "lbl_sms";
            this.lbl_sms.Size = new System.Drawing.Size(66, 36);
            this.lbl_sms.TabIndex = 7;
            this.lbl_sms.Text = "........";
            this.lbl_sms.UseCompatibleTextRendering = true;
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
            this.Chk_Trans_report.CheckedChanged += new System.EventHandler(this.Chk_Trans_report_CheckedChanged);
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
            this.Chk_reports.CheckedChanged += new System.EventHandler(this.Chk_reports_CheckedChanged);
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
            this.Chk_SMS_not.CheckedChanged += new System.EventHandler(this.Chk_SMS_not_CheckedChanged);
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
            this.btn_signup.Click += new System.EventHandler(this.btn_signup_Click);
            // 
            // lbl_lname
            // 
            this.lbl_lname.AutoSize = true;
            this.lbl_lname.Location = new System.Drawing.Point(53, 98);
            this.lbl_lname.Name = "lbl_lname";
            this.lbl_lname.Size = new System.Drawing.Size(72, 16);
            this.lbl_lname.TabIndex = 8;
            this.lbl_lname.Text = "Last Name";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1038, 629);
            this.Controls.Add(this.lbl_lname);
            this.Controls.Add(this.btn_signup);
            this.Controls.Add(this.services);
            this.Controls.Add(this.lbl_mail);
            this.Controls.Add(this.tb_MailID);
            this.Controls.Add(this.tb_LastName);
            this.Controls.Add(this.lbl_fname);
            this.Controls.Add(this.tb_FirstName);
            this.Name = "Form1";
            this.Text = "Form1";
            this.services.ResumeLayout(false);
            this.services.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox tb_FirstName;
        private System.Windows.Forms.Label lbl_fname;
        private System.Windows.Forms.Label lname;
        private System.Windows.Forms.TextBox tb_LastName;
        private System.Windows.Forms.Label lbl_mail;
        private System.Windows.Forms.TextBox tb_MailID;
        private System.Windows.Forms.GroupBox services;
        private System.Windows.Forms.CheckBox Chk_Trans_report;
        private System.Windows.Forms.CheckBox Chk_reports;
        private System.Windows.Forms.CheckBox Chk_SMS_not;
        private System.Windows.Forms.Label lbl_sms;
        private System.Windows.Forms.Label lbl_trn_report;
        private System.Windows.Forms.Label lbl_report;
        private System.Windows.Forms.Button btn_signup;
        private System.Windows.Forms.Label lbl_lname;
    }
}

