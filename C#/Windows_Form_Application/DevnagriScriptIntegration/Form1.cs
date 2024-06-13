using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DevnagriScriptIntegration
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Add_Click(object sender, EventArgs e)
        {
            string constring = "data source = (localdb)\\BillingAppLocalDbServer; initial catalog = testDB; integrated security = True";
            SqlConnection con = new SqlConnection(constring);
            con.Open();

            // The datatype of [name],[surname] columns in sql should be nvarchar.
            // To fetch and write devanagri data in database 'N' has to be appended before the values.
            string query = "INSERT INTO [dbo].[Table1] ([name],[surname]) VALUES (N'" + tb_name.Text + "', N'" + tb_surname.Text + "')";
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.ExecuteNonQuery();
        }
    }
}
