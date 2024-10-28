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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            foreach (Control ctrl in this.Controls)
            {
                if(ctrl is MdiClient)
                {
                    ctrl.BackColor = Color.FromArgb(0, 125, 200);
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void Savebtn_Click(object sender, EventArgs e)
        {
            DBConnect obj_DBConnect = new DBConnect();

            if (MaleRB.Checked)
            {
                obj_DBConnect.addUser(Nametxt.Text, Convert.ToInt64(Phonetxt.Text.ToString()), Convert.ToInt16(Agetxt.Text), true);
            }
            else
            {
                obj_DBConnect.addUser(Nametxt.Text, Convert.ToInt64(Phonetxt.Text.ToString()), Convert.ToInt16(Agetxt.Text), false);
            }
        }

        private void showbtn_Click(object sender, EventArgs e)
        {
            Display obj_disp = new Display();
            obj_disp.ShowDialog();
        }
    }
}
