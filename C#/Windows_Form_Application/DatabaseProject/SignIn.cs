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

        public static string st_id, st_name, st_email, st_password, st_country;

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
                string query = "Select * from Users Where Email= N'" + email + "' AND Password = N'" + password + "'";
                objDBAccess.readDatathroughAdapter(query, dtUser);  //dtUser stores the data on RAM. So it should be temporarily used.

                if (dtUser.Rows.Count >= 1 )
                {
                    MessageBox.Show("You are logged in successfully.");
                    objDBAccess.closeConn();

                    st_id = dtUser.Rows[0]["ID"].ToString();
                    st_name = dtUser.Rows[0]["Name"].ToString();
                    st_email = dtUser.Rows[0]["Email"].ToString();
                    st_password = dtUser.Rows[0]["Password"].ToString();
                    st_country = dtUser.Rows[0]["Country"].ToString();

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

        private void label2_Click(object sender, EventArgs e)
        {
            this.Hide();

            SignUp signUp = new SignUp();

            signUp.Show();
        }
    }
}

