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


        public Form1()
        {
            InitializeComponent();
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
