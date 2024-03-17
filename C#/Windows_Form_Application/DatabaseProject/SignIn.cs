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
    public partial class SignIn : Form
    {
        DBAccess objDBAccess = new DBAccess();
        DataTable dtUser =  new DataTable();

        public SignIn()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string email = textBox2.Text;
            string password = textBox3.Text;

            if(email.Equals(""))
            {
                MessageBox.Show("Please enter email.");
            }
            else if (password.Equals(""))
            {
                MessageBox.Show("Please enter password.");
            }
            else
            {
                string query = "Select * from Users Where Email= '" + email + "' AND Password = '" + password + "'";
                objDBAccess.readDatathroughAdapter(query, dtUser);  //dtUser stores the data on RAM. So it should be temporarily used.

                if (dtUser.Rows.Count == 1 )
                {
                    MessageBox.Show("You are logged in successfully.");
                    objDBAccess.closeConn();

                    this.Hide();

                    HomePage home = new HomePage();

                    home.Show();
                }
                else
                {
                    MessageBox.Show("Invalid credentials, provide correct data.");
                }
            }
        }
    }
}
