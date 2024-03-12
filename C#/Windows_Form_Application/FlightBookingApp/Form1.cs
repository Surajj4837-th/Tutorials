using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FlightBookingApp
{
    public partial class Form1 : Form
    {
        public static Boolean Passport, ID_Card;

        public static string to, from, start_date, end_date, first_name, last_name, doc_no, issue_date, expiry_date, weight;

        private void button1_Click(object sender, EventArgs e)
        {
            to = tb_To.Text;
            from = tb_From.Text;
            start_date = monthCalendar1.SelectionStart.ToString("dd MM yyyy");
            end_date = monthCalendar1.SelectionEnd.ToString("dd MM yyyy");

            first_name = tb_fname.Text;
            last_name = tb_lname.Text;
            doc_no = tb_DocNo.Text;

            issue_date = dtp_IssueDate.Value.ToString("dd MM yyyyy");
            expiry_date = dtp_Expiry.Value.ToString("dd MM yyyyy");

            weight = nud_bag.Value.ToString();

            this.Hide();

            Form2 f2 = new Form2();
            f2.Show();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            nud_bag.Increment = 5;
            nud_bag.ReadOnly = true;

            monthCalendar1.MaxSelectionCount = 100;
            monthCalendar1.ShowToday = true;
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void dtp_IssueDate_ValueChanged(object sender, EventArgs e)
        {
            DateTime issue_dt = dtp_IssueDate.Value;

            dtp_Expiry.MinDate = issue_dt;
        }

        private void rb_passport_CheckedChanged(object sender, EventArgs e)
        {
            if(rb_passport.Checked)
            {
                lbl_Doc2.Text = "Passport No.";
                lbl_IssuesDate.Text = "Passport No.";
                lbl_ExpiryDate.Text = "Passport No.";

                Passport = true;
            }

            if (rb_ID.Checked)
            {
                lbl_Doc2.Text = "ID Card No.";
                lbl_IssuesDate.Text = "ID Card No.";
                lbl_ExpiryDate.Text = "ID Card No.";

                ID_Card = true;
            }
        }
    }
}
