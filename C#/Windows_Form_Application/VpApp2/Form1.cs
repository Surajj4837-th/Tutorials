using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace VpApp2
{
    public partial class Form1 : Form
    {
        public static string FirstName = null;
        public static string LastName = null;
        public static string email = null;

        public static Boolean sms;
        public static Boolean reports;
        public static Boolean transactions;


        Confirmation C = new Confirmation();



        public Form1()
        {
            InitializeComponent();
        }

        private void btn_signup_Click(object sender, EventArgs e)
        {
            FirstName = tb_FirstName.Text;
            LastName = tb_LastName.Text;
            email = tb_MailID.Text;

            this.Hide();
            C.Show();

        }

        private void Chk_SMS_not_CheckedChanged(object sender, EventArgs e)
        {
            if(Chk_SMS_not.Checked)
            {
                sms = true;
                lbl_sms.Text = "Services charges may apply for SMS.";
            }
            else
            {
                sms = false;
                lbl_sms.Text = "........";
            }
        }

        private void Chk_reports_CheckedChanged(object sender, EventArgs e)
        {
            if (Chk_reports.Checked)
            {
                reports = true;
            }
            else
            {
                reports = false;
            }
        }

        private void Chk_Trans_report_CheckedChanged(object sender, EventArgs e)
        {
            if (Chk_Trans_report.Checked)
            {
                transactions = true;
                lbl_trn_report.Text = "Services charges may apply for transactios.";
            }
            else
            {
                transactions = false;
                lbl_trn_report.Text = "........";
            }
        }

    }
}

/*
 * 1. Boolean keyword used for heck box status.
 * 
 * 2. static used for using the variables across forms.
 */