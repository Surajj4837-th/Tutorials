using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data;
using System.Data.SqlClient;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.StartPanel;
using System.Xml.Linq;

namespace DatabaseProject
{
    public partial class HomePage : Form
    {

        DBAccess objDBAccess = new DBAccess();
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

        private void button1_Click(object sender, EventArgs e)
        {
            string newUserName = textBox1.Text;
            string newUserEmail = textBox2.Text;
            string newUserPassword = textBox3.Text;
            string newUserCountry = comboBox1.Text;

            if(newUserName.Equals(""))
            {
                MessageBox.Show("Please fill your name.");
            }
            else if (newUserEmail.Equals(""))
            {
                MessageBox.Show("Please fill your mail ID.");
            }
            else if (newUserPassword.Equals(""))
            {
                MessageBox.Show("Please fill your password.");
            }
            else if (newUserCountry.Equals(""))
            {
                MessageBox.Show("Please fill your country.");
            }
            else
            {
                string query = "Update Users SET Name = '" + @newUserName + "', Email = '" + @newUserEmail + "', Password = '" + @newUserPassword + "', Country = '" + @newUserCountry + "' where  ID = '" + SignIn.st_id + "'";

                SqlCommand updateCommnad = new SqlCommand(query);

                //Securing the data: by using following code the user data is hidden to DBObject
                updateCommnad.Parameters.AddWithValue("@username", @newUserName);
                updateCommnad.Parameters.AddWithValue("@useremail", @newUserEmail);
                updateCommnad.Parameters.AddWithValue("@userpassword", @newUserPassword);
                updateCommnad.Parameters.AddWithValue("@usercountry", @newUserCountry);

                int row = objDBAccess.executeQuery(updateCommnad);

                if (row == 1)
                {
                    MessageBox.Show("Account information is updated successfully...");

                    this.Hide();

                    SignIn signin = new SignIn();

                    signin.Show();
                }
                else
                {
                    MessageBox.Show("Error occured.");
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            DialogResult dialog = MessageBox.Show("Are you sure?", "Delete Account", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);

            if (dialog == DialogResult.Yes)
            {
                string deletequery = "DELETE from Users where ID = '" + SignIn.st_id + "'";

                SqlCommand deleteCommand = new SqlCommand(deletequery);

                int row = objDBAccess.executeQuery(deleteCommand);

                if (row == 1)
                {
                    MessageBox.Show("Account is deleted successfully...");

                    this.Hide();

                    SignIn signin = new SignIn();

                    signin.Show();
                }
                else
                {
                    MessageBox.Show("Error occured.");
                }
            }
        }
    }
}
