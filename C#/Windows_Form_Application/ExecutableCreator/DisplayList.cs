using DatabaseProject;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ExecutableCreator
{
    public partial class DisplayList : Form
    {
        DataTable dt_Customers = new DataTable();
        DBAccess obj_DBAccess = new DBAccess();
        public DisplayList()
        {

            InitializeComponent();
            dt_Customers.Columns.Add("Name");
            dt_Customers.Columns.Add("Surname");

            dataGridView1.DataSource = dt_Customers;
            dataGridView1.Columns[0].HeaderText = "Name";
            dataGridView1.Columns[0].AutoSizeMode = DataGridViewAutoSizeColumnMode.Fill;
            dataGridView1.Columns[1].HeaderText = "Surname";
            dataGridView1.Columns[1].AutoSizeMode = DataGridViewAutoSizeColumnMode.Fill;

            string query = "Select * from Table1";

            dt_Customers.Rows.Clear();
            obj_DBAccess.readDatathroughAdapter(query, dt_Customers);
            obj_DBAccess.closeConn();

            dataGridView1.Update();
            dataGridView1.Refresh();
        }
    }
}
