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

        private void LoginCheck()
        {
            string id = textID.Text;
            string pass = Txtpwd.Text;

            if (id == "123" && pass == "qwerty")
            {
                this.Hide();
                Form1 f1 = new Form1();
                f1.Show();
            }
            else
            {
                MessageBox.Show("Password or ID is incorrect");
            }
        }

        private void Reset()
        {
            textID.Text = "";
            Txtpwd.Text = "";
        }

        private void btnlogin_Click(object sender, EventArgs e)
        {
            LoginCheck();           
        }

        private void btnreset_Click(object sender, EventArgs e)
        {
            Reset();
        }

        private void Txtpwd_KeyPress(object sender, KeyPressEventArgs e)
        {
            if(e.KeyChar == (char)Keys.Enter)
            {
                LoginCheck();
            }

            if (e.KeyChar == (char)Keys.Escape)
            {
                Reset();
            }
        }
    }
}
