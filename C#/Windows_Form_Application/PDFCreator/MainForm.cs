using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Printing;
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

        Font fnt = new Font("Arial", 11, FontStyle.Regular);

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

        private void CreateHeader(PrintPageEventArgs e, int LeftBound, int RightBound)
        {
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(0, 240), new Point(700, 240));
        }
        private void ShowUsableArea(PrintPageEventArgs e)
        {
            e.Graphics.DrawRectangle(new Pen(Color.Yellow), e.PageBounds.Left + 40, e.PageBounds.Top + 20, e.PageBounds.Width - 80, e.PageBounds.Height - 60);
        }
        private void ShowPageNumber(PrintPageEventArgs e, string pageNumber)
        {
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(e.PageBounds.Left + 40, e.PageBounds.Height - 40), new Point(e.PageBounds.Width - 40, e.PageBounds.Height - 40));
            e.Graphics.DrawString(pageNumber, fnt, Brushes.Black, new Point(e.PageBounds.Width / 2, e.PageBounds.Height - 30));
        }
        private void CreateTable(PrintPageEventArgs e)
        {
            int LeftBound = e.PageBounds.Left + 40;
            int RightBound = e.PageBounds.Right - 10;

            //Header
            e.Graphics.FillRectangle(new SolidBrush(Color.Black), LeftBound, 370, e.PageBounds.Width - 80, 30);

            //Draw vertical lines
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(e.PageBounds.Left + 40, 370), new Point(e.PageBounds.Left + 40, e.PageBounds.Height - 60));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(e.PageBounds.Right - 40, 370), new Point(e.PageBounds.Right - 40, e.PageBounds.Height - 60));

            bool IsEven = true;

            for(int i = 400; i < e.PageBounds.Height - 60; i+=40)
            {
                if (IsEven)
                {
                    e.Graphics.FillRectangle(new SolidBrush(Color.White), LeftBound, i, e.PageBounds.Width - 80, 40);
                    IsEven = false;
                }
                else
                {
                    e.Graphics.FillRectangle(new SolidBrush(Color.LightGray), LeftBound, i, e.PageBounds.Width - 80, 40);
                    IsEven = true;
                }
            }

            e.Graphics.DrawLine(new Pen(Color.Black), new Point(e.PageBounds.Left + 110, 370), new Point(e.PageBounds.Left + 110, e.PageBounds.Height - 60));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(e.PageBounds.Left + 390, 370), new Point(e.PageBounds.Left + 390, e.PageBounds.Height - 60));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(e.PageBounds.Left + 460, 370), new Point(e.PageBounds.Left + 460, e.PageBounds.Height - 60));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(e.PageBounds.Left + 530, 370), new Point(e.PageBounds.Left + 530, e.PageBounds.Height - 60));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(e.PageBounds.Left + 600, 370), new Point(e.PageBounds.Left + 600, e.PageBounds.Height - 60));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(e.PageBounds.Left + 670, 370), new Point(e.PageBounds.Left + 670, e.PageBounds.Height - 60));

            e.Graphics.DrawLine(new Pen(Color.Black), new Point(e.PageBounds.Left + 40, e.PageBounds.Height - 60), new Point(e.PageBounds.Width - 40, e.PageBounds.Height - 60));
        }

        private void printDocument_PrintPage(object sender, System.Drawing.Printing.PrintPageEventArgs e)
        {
            int LeftBound = e.PageBounds.Left + 10;
            int RightBound = e.PageBounds.Right - 10;

            //Usable Area
            ShowUsableArea(e);

            //Show page number
            ShowPageNumber(e, "1");

            // Create Table
            CreateTable(e);

            //CreateHeader(e, LeftBound, RightBound);

            //Pen selPen = new Pen(Color.Blue);
            //e.Graphics.FillRectangle(new SolidBrush(Color.AliceBlue), e.MarginBounds.Left, e.MarginBounds.Top, e.MarginBounds.Width, e.MarginBounds.Height);


            /*
             1. Permanent items:
                - Page No.
                - Logo
                - Company Name, address
                - Note
                - Bill To
                - Invoice details: No, Date, Time
                - Table
                - Payment status
             */

            //e.Graphics.Clear(Color.LightGray);

            ////Show image
            //Bitmap image = Properties.Resources.Logo;
            //Image img = image;
            //e.Graphics.DrawImage(img, 10, 10, img.Width, img.Height);

            //// Show string
            //e.Graphics.DrawString("Customer Name: " + name.Text, new Font("Arial", 11, FontStyle.Regular), Brushes.Black, new Point(10, 100));
            //e.Graphics.DrawString("Date: " + DateTime.Now, new Font("Arial", 11, FontStyle.Regular), Brushes.Black, new Point(10, 130));
            //e.Graphics.DrawString("Customer Mobile No.: " + mobno.Text, new Font("Arial", 11, FontStyle.Regular), Brushes.Black, new Point(10, 150));

            //string dash = "--------------------------------------------------------------------------------------------------------------------------------------------";
            //e.Graphics.DrawString(dash, new Font("Arial", 11, FontStyle.Regular), Brushes.Black, new Point(0, 170));

        }

        private void print_Click(object sender, EventArgs e)
        {
            printDocument.Print();
        }
    }
}
