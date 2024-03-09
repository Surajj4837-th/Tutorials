using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DialogBox
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btn_Yes_Click(object sender, EventArgs e)
        {
            DialogResult dr = MessageBox.Show("1. To purchase press Yes. \n2. For trial version press 2. \n3. Cancel order.", "Purchase Software", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Information);

            if (dr == DialogResult.Yes)
            {
                lbl_YesNo.Text = "You have purchased software, congratulations.";
                lbl_Cancel.Text = ".....";
            }

            if (dr == DialogResult.No)
            {
                lbl_YesNo.Text = "Trial version starts, congratulations.";
                lbl_Cancel.Text = ".....";
            }

            if (dr == DialogResult.Cancel)
            {
                lbl_Cancel.Text = "You have cancelled the order.";
                lbl_YesNo.Text = ".....";
            }
        }
    }
}
