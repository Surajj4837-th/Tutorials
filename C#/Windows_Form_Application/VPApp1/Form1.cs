using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace VPApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            lblHello.Text = "Hello World";
        }

        private void btnset_Click(object sender, EventArgs e)
        {
            lblHello.Text = "Hello World Again";
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            lblHello.Text = "Cancelled";
        }

        private void lgtot_Click(object sender, EventArgs e)
        {
            LoginForm L1 = new LoginForm();
            L1.Show();
        }
    }
}

/*
 * 1. Form1 is the complete form.
 * 
 * 2. Form1_Load() is function that will do operatins when form is application is loaded
 */