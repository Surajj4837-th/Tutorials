using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics.Tracing;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace VPApp1
{
    public partial class LoginForm : Form
    {
        public LoginForm()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void btnlogin_Click(object sender, EventArgs e)
        {
            this.Hide();

            string id = textID.Text;
            string pass = Txtpwd.Text;

            if(id == "123" && pass == "qwerty")
            {
                Form1 f1 = new Form1();
                f1.Show();
            }
            else
            {
                MessageBox.Show("Password or ID is incorrect");
            }
        }

        private void btnreset_Click(object sender, EventArgs e)
        {
            textID.Text = "";
            Txtpwd.Text = "";
        }
    }
}
