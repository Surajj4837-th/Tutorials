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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void btn_done_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            if(Form1.Passport)
            {
                label3.Text = "Passport No.:";
                label2.Text = "Passport Exp.:";
            }

            if(Form1.ID_Card)
            {
                label3.Text = "ID Card No.:";
                label2.Text = "ID Card Exp.:";
            }


            lbl_fullname.Text = Form1.first_name + " " + Form1.last_name;
            lbl_DepCity.Text = Form1.from;
            lbl_Dstcity.Text = Form1.to;
            lbl_tripDates.Text = Form1.start_date + " to " + Form1.end_date;
            lbl_Docno.Text = Form1.doc_no;
            lbl_DocExp.Text = Form1.expiry_date;
            lbl_wt.Text = Form1.weight;
        }
    }
}
