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
    public partial class CommandBuilderForm : Form
    {

        DBAccess objDBAccess = new DBAccess();
        DataTable dt_info = new DataTable();
        public CommandBuilderForm()
        {
            InitializeComponent();
        }

        private void CommandBuilderForm_Load(object sender, EventArgs e)
        {
            string query = "Select * from Users";

            objDBAccess.readDatathroughAdapter(query, dt_info);

            dataGridView1.DataSource = dt_info;
            objDBAccess.closeConn();
        }
    }
}
