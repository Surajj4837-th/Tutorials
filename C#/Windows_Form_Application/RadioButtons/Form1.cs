using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RadioButtons
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(radioButton1.Checked ) 
            {
                string Name = radioButton1.Text;
                MessageBox.Show(Name);
            }

            if (radioButton2.Checked)
            {
                string Name = radioButton2.Text;
                MessageBox.Show(Name);
            }

            if (radioButton3.Checked)
            {
                string Name = radioButton3.Text;
                MessageBox.Show(Name);
            }
        }
    }
}
