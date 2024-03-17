using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DatabaseProject
{
    public partial class SignUp : Form
    {
        DBAccess DBObject = new DBAccess();
        public SignUp()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string username = textBox1.Text;
            string useremail = textBox2.Text;
            string userpassword = textBox3.Text;
            string usercountry = comboBox1.Text;

            if(username.Equals(""))
            {
                MessageBox.Show("Please enter your user name.");
            }
            else if (useremail.Equals(""))
            {
                MessageBox.Show("Please enter your user e-mail.");
            }
            else if (userpassword.Equals(""))
            {
                MessageBox.Show("Please enter your user password.");
            }
            else if (usercountry.Equals(""))
            {
                MessageBox.Show("Please enter your user country.");
            }
            else
            {
                SqlCommand insertCommand = new SqlCommand("insert into Users(Name,Email,Password,Country) values(@username, @useremail, @userpassword, @usercountry)");

                //Securing the data: by using following code the user data is hidden to DBObject
                insertCommand.Parameters.AddWithValue("@username", username);
                insertCommand.Parameters.AddWithValue("@useremail", useremail);
                insertCommand.Parameters.AddWithValue("@userpassword", userpassword);
                insertCommand.Parameters.AddWithValue("@usercountry", usercountry);

                int row = DBObject.executeQuery(insertCommand);

                if (row == 1)
                {
                    MessageBox.Show("Account is created successfully...");

                    this.Hide();

                    HomePage home = new HomePage();

                    home.Show();
                }
                else
                {
                    MessageBox.Show("Error occured.");
                }
            }
            
        }
    }
}
