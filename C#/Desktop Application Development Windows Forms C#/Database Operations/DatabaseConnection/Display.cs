using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DatabaseConnection
{
    public partial class Display : Form
    {
        public Display()
        {
            InitializeComponent();
        }

        private void Display_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'phoneDirectoryDataSet.Directory' table. You can move, or remove it, as needed.
            this.directoryTableAdapter.Fill(this.phoneDirectoryDataSet.Directory);

        }
    }
}
