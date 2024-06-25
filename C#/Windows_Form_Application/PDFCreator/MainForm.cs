using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PDFCreator
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void close_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void addcustomer_Click(object sender, EventArgs e)
        {
            name.Clear();
            mobno.Clear();
            productlist.SelectedIndex = 0;
            quantitycb.SelectedIndex = 0;
            price.Clear();
            totalamount.Clear();
        }

        private void price_TextChanged(object sender, EventArgs e)
        {
            if (!price.Text.Equals("") && !quantitycb.Text.Equals(""))
            {
                decimal amount = Convert.ToDecimal(price.Text) * Convert.ToInt32(quantitycb.Text);
                totalamount.Text = amount.ToString();
            }
        }

        private void quantitycb_TextChanged(object sender, EventArgs e)
        {
            if (!price.Text.Equals("") && !quantitycb.Text.Equals(""))
            {
                decimal amount = Convert.ToDecimal(price.Text) * Convert.ToInt32(quantitycb.Text);
                totalamount.Text = amount.ToString();
            }
        }

        private void preview_Click(object sender, EventArgs e)
        {
            printPreviewDialog.Document = printDocument;
            printPreviewDialog.ShowDialog();
        }

        private void printDocument_PrintPage(object sender, System.Drawing.Printing.PrintPageEventArgs e)
        {
            //Show image
            Bitmap image = Properties.Resources.Logo;
            Image img = image;
            e.Graphics.DrawImage(img, 10, 10, img.Width, img.Height);

            // Show string
            e.Graphics.DrawString("Customer Name: " + name.Text, new Font("Arial", 11, FontStyle.Regular), Brushes.Black, new Point(10, 100));
            e.Graphics.DrawString("Date: " + DateTime.Now, new Font("Arial", 11, FontStyle.Regular), Brushes.Black, new Point(10, 130));
            e.Graphics.DrawString("Customer Mobile No.: " + mobno.Text, new Font("Arial", 11, FontStyle.Regular), Brushes.Black, new Point(10, 150));

            string dash = "--------------------------------------------------------------------------------------------------------------------------------------------";
            e.Graphics.DrawString(dash, new Font("Arial", 11, FontStyle.Regular), Brushes.Black, new Point(0, 170));
            
        }

        private void print_Click(object sender, EventArgs e)
        {
            printDocument.Print();
        }
    }
}
