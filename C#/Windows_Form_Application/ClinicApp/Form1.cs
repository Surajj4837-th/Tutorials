using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ClinicApp
{
    public partial class Form1 : Form
    {
        DataTable dt_Clinic = new DataTable();

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            FillClinicTable();

            comboBox1.DataSource = dt_Clinic;
            comboBox1.DisplayMember = "CName";
        }

        private void FillClinicTable()
        {
            dt_Clinic.Columns.Add("CID", typeof(int));
            dt_Clinic.Columns.Add("CName");
            dt_Clinic.Columns.Add("CAddress");
            dt_Clinic.Columns.Add("CContact");
            dt_Clinic.Columns.Add("CRating");

            dt_Clinic.Rows.Add(1, "Dentist Pro Clinic", "Palm Beach Florida", "123", "7");
            dt_Clinic.Rows.Add(2, "Clinic2", "Marathahalli", "234", "5");
            dt_Clinic.Rows.Add(3, "Eye expert", "AECS layout", "345",  "6");
            dt_Clinic.Rows.Add(4, "Clinic3", "Bombay", "456", "8");
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            lbl_ClinicName.Text = dt_Clinic.Rows[comboBox1.SelectedIndex]["CName"].ToString();
            // comboBox1.SelectedIndex returns row number
            // CName returns column number

            lbl_ClinicAddress.Text = dt_Clinic.Rows[comboBox1.SelectedIndex]["CAddress"].ToString();
            lbl_Rating.Text = dt_Clinic.Rows[comboBox1.SelectedIndex]["CRating"].ToString();
            lbl_Contact.Text = dt_Clinic.Rows[comboBox1.SelectedIndex]["CContact"].ToString();

        }
    }
}
