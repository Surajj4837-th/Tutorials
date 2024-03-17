using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DatabaseProject
{
    public partial class HomePage : Form
    {
        public HomePage()
        {
            InitializeComponent();
        }

        private void HomePage_Load(object sender, EventArgs e)
        {
            label6.Text = "Welcome " + SignIn.st_name;
            textBox1.Text = SignIn.st_name;
            textBox2.Text = SignIn.st_email;
            textBox3.Text = SignIn.st_password;
            comboBox1.Text = SignIn.st_country;
        }
    }
}
