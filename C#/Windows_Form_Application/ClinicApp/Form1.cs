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
        DataTable dt_Doctors = new DataTable();
        DataTable dt_SpeificClinicDoctors = new DataTable();

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            FillClinicTable();
            FillDoctorsTable();

            comboBox1.DataSource = dt_Clinic;
            comboBox1.DisplayMember = "CName";  //Display this value in combo box
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
            dt_Clinic.Rows.Add(3, "Eye expert", "AECS layout", "345", "6");
            dt_Clinic.Rows.Add(4, "Clinic3", "Bombay", "456", "8");
        }

        private void FillDoctorsTable()
        {
            dt_Doctors.Columns.Add("CID", typeof(int)); // Doctors will be mapped to different clinincs based on their clinic IDs (CID).
            dt_Doctors.Columns.Add("DocName");
            dt_Doctors.Columns.Add("DocSpec");
            dt_Doctors.Columns.Add("DocContact");

            dt_Doctors.Rows.Add(1, "Dr A", "Eye", "123");
            dt_Doctors.Rows.Add(1, "Dr B", "Nose", "234");
            dt_Doctors.Rows.Add(2, "Dr C", "Teeth", "345");
            dt_Doctors.Rows.Add(3, "Dr D", "Throat", "456");
            dt_Doctors.Rows.Add(3, "Dr E", "Lungs", "567");
            dt_Doctors.Rows.Add(3, "Dr F", "Stomach", "678");
            dt_Doctors.Rows.Add(4, "Dr G", "Bones", "789");
            dt_Doctors.Rows.Add(4, "Dr H", "Child", "890");
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            lbl_ClinicName.Text = dt_Clinic.Rows[comboBox1.SelectedIndex]["CName"].ToString();
            // comboBox1.SelectedIndex returns row number
            // CName returns column number

            lbl_ClinicAddress.Text = dt_Clinic.Rows[comboBox1.SelectedIndex]["CAddress"].ToString();
            lbl_Rating.Text = dt_Clinic.Rows[comboBox1.SelectedIndex]["CRating"].ToString();
            lbl_Contact.Text = dt_Clinic.Rows[comboBox1.SelectedIndex]["CContact"].ToString();

            //Select doctors from specific clinic
            dt_SpeificClinicDoctors = dt_Doctors.Select("CID = " + dt_Clinic.Rows[comboBox1.SelectedIndex]["CID"]).CopyToDataTable();
            //comboBox1.SelectedIndex: returns row number
            //"CID": returns column number.

            comboBox2.DataSource = dt_SpeificClinicDoctors;
            comboBox2.DisplayMember = "DocName";    //Display this value in combo box

        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            lbl_DcName.Text = dt_SpeificClinicDoctors.Rows[comboBox2.SelectedIndex]["DocName"].ToString();
            lbl_DcSpec.Text = dt_SpeificClinicDoctors.Rows[comboBox2.SelectedIndex]["DocSpec"].ToString();
            lbl_DcContact.Text = dt_SpeificClinicDoctors.Rows[comboBox2.SelectedIndex]["DocContact"].ToString();

        }
    }
}
