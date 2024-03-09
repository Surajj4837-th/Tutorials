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
    public partial class Confirmation : Form
    {
        public Confirmation()
        {
            InitializeComponent();
        }

        private void Confirmation_Load(object sender, EventArgs e)
        {
            Con_lbl_fname.Text = Form1.FirstName;

            COn_lbl_lname.Text = Form1.LastName;

            Con_lbl_mail.Text = Form1.email;

            if (Form1.sms)
            {
                Con_lbl_sms.Text = "✓";
            }
            else
            {
                Con_lbl_sms.Text = "X";
            }

            if (Form1.reports)
            {
                Con_lbl_reports.Text = "✓";
            }
            else
            {
                Con_lbl_reports.Text = "X";
            }

            if (Form1.transactions)
            {
                Con_lbl_trns_reports.Text = "✓";
            }
            else
            {
                Con_lbl_trns_reports.Text = "X";
            }
        }
    }
}
