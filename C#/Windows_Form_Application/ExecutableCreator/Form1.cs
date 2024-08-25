using DatabaseProject;
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
using System.Xml.Linq;

namespace ExecutableCreator
{
    public partial class Form1 : Form
    {
        DBAccess obj_DBAccess = new DBAccess();
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(textBox1.Text.Equals("") || textBox2.Text.Equals(""))
            {

            }
            else
            {
                SqlCommand insertCommand = new SqlCommand("insert into Table1 (Name, Surname) values (@Name, @Surname)");
                insertCommand.Parameters.AddWithValue("@Name", textBox1.Text.ToString());
                insertCommand.Parameters.AddWithValue("@Surname", textBox2.Text.ToString());

                obj_DBAccess.executeQuery(insertCommand);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form Disp = new DisplayList();
            Disp.Show();
        }
    }
}
