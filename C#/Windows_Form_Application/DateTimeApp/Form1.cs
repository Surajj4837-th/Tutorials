using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DateTimeApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            lbl_Date1.Text = dateTimePicker1.Value.ToString();

            lbl_date2.Text = dateTimePicker1.Value.ToString("MM, dd, yyyy");

            lbl_Date3.Text = dateTimePicker1.Value.ToLongDateString();

            lbl_time1.Text = dateTimePicker1.Value.ToShortTimeString();

            lbl_Time2.Text = dateTimePicker1.Value.ToLongTimeString();
        }
    }
}
