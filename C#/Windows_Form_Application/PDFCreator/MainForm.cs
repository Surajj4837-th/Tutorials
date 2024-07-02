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

        Font fnt = new Font("Arial", 13, FontStyle.Regular);

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

        private void CreateHeaderLine(PrintPageEventArgs e, int LeftBound, int RightBound)
        {
            e.Graphics.DrawString("TAX INVOICE", new Font("Arial", 15, FontStyle.Regular), Brushes.Black, new Point(40, 40));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(180, 50), new Point(RightBound - 40, 50));
        }
        private void ShowUsableArea(PrintPageEventArgs e)
        {
            e.Graphics.DrawRectangle(new Pen(Color.Yellow), e.PageBounds.Left + 40, e.PageBounds.Top + 40, e.PageBounds.Width - 80, e.PageBounds.Height - 80);
        }
        private void ShowPageNumber(PrintPageEventArgs e, string pageNumber)
        {
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(e.PageBounds.Left + 40, e.PageBounds.Height - 40), new Point(e.PageBounds.Width - 40, e.PageBounds.Height - 40));
            e.Graphics.DrawString(pageNumber, fnt, Brushes.Black, new Point(e.PageBounds.Width / 2, e.PageBounds.Height - 30));
        }
        private void AddLogo(PrintPageEventArgs e)
        {
            e.Graphics.DrawRectangle(new Pen(Color.Black), e.PageBounds.Left + 40, 70, e.PageBounds.Width/2 - 40, 125);
            e.Graphics.DrawRectangle(new Pen(Color.Black), e.PageBounds.Left + 40, 70 + 125, e.PageBounds.Width/2 - 40, 125);

            e.Graphics.DrawRectangle(new Pen(Color.Black), e.PageBounds.Width / 2, 70, e.PageBounds.Width / 2 - 40, 125);
            e.Graphics.DrawRectangle(new Pen(Color.Black), e.PageBounds.Width / 2, 70 + 125, e.PageBounds.Width / 2 - 40, 125);

            // Add Logo
            var img = new Bitmap("C:\\Users\\admin\\source\\repos\\Tutorials\\C#\\Windows_Form_Application\\PDFCreator\\Resources\\Logo.png");
            e.Graphics.DrawImage(img, new Rectangle(60, 75, 284, 61));

            // Add vendor address

        }
        private void CreateTable(PrintPageEventArgs e)
        {
            int FirstColumn = e.PageBounds.Left + 40;
            int SecondColumn = FirstColumn + 70;
            int ThirdColumn = SecondColumn + 280;
            int FourthColumn = ThirdColumn + 85;
            int FifthColumn = FourthColumn + 85;
            int SixthColumn = FifthColumn + 85;
            int SeventhColumn = SixthColumn + 85;
            int EighthColumn = e.PageBounds.Right - 40;

            int TableStartY = 330;
            int TableEndY = 1010;

            //Table header
            e.Graphics.FillRectangle(new SolidBrush(Color.Black), FirstColumn, TableStartY, e.PageBounds.Width - 80, 40);
            e.Graphics.DrawString("Sr. No.", fnt, Brushes.White, (FirstColumn + SecondColumn)/2 - 25, TableStartY + 6);
            e.Graphics.DrawString("Item", fnt, Brushes.White, (SecondColumn + ThirdColumn) / 2 - 15, TableStartY + 6);
            e.Graphics.DrawString("Quantity", fnt, Brushes.White, (ThirdColumn + FourthColumn) / 2 - 30, TableStartY + 6);
            e.Graphics.DrawString("Rate", fnt, Brushes.White, (FourthColumn + FifthColumn) / 2 - 20, TableStartY + 6);
            e.Graphics.DrawString("SGST", fnt, Brushes.White, (FifthColumn + SixthColumn) / 2 - 20, TableStartY + 6);
            e.Graphics.DrawString("CGST", fnt, Brushes.White, (SixthColumn + SeventhColumn) / 2 - 15, TableStartY + 6);
            e.Graphics.DrawString("Amount", fnt, Brushes.White, (SeventhColumn + EighthColumn) / 2 - 30, TableStartY + 6);

            bool IsEven = true;

            //Table rows
            for(int i = TableStartY + 40; i < TableEndY; i+=40)
            {
                if (IsEven)
                {
                    e.Graphics.FillRectangle(new SolidBrush(Color.White), FirstColumn, i, e.PageBounds.Width - 80, 40);
                    IsEven = false;
                }
                else
                {
                    e.Graphics.FillRectangle(new SolidBrush(Color.LightGray), FirstColumn, i, e.PageBounds.Width - 80, 40);
                    IsEven = true;
                }
            }

            //Draw vertical lines
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(FirstColumn, TableStartY), new Point(FirstColumn, e.PageBounds.Height - 60));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(SecondColumn, TableStartY), new Point(SecondColumn, e.PageBounds.Height - 60));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(ThirdColumn, TableStartY), new Point(ThirdColumn, e.PageBounds.Height - 60));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(FourthColumn, TableStartY), new Point(FourthColumn, e.PageBounds.Height - 60));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(FifthColumn, TableStartY), new Point(FifthColumn, e.PageBounds.Height - 60));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(SixthColumn, TableStartY), new Point(SixthColumn, e.PageBounds.Height - 60));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(SeventhColumn, TableStartY), new Point(SeventhColumn, e.PageBounds.Height - 60));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(EighthColumn, TableStartY), new Point(EighthColumn, e.PageBounds.Height - 60));

            e.Graphics.DrawLine(new Pen(Color.Black), new Point(FirstColumn, e.PageBounds.Height - 60), new Point(EighthColumn, e.PageBounds.Height - 60));
        }

        private void printDocument_PrintPage(object sender, System.Drawing.Printing.PrintPageEventArgs e)
        {
            int LeftBound = e.PageBounds.Left + 10;
            int RightBound = e.PageBounds.Right - 10;

            //Usable Area
            ShowUsableArea(e);

            CreateHeaderLine(e, LeftBound, RightBound);

            //Show page number
            ShowPageNumber(e, "1");

            // Create Table
            CreateTable(e);

            // Add logo
            AddLogo(e);

        }

        private void print_Click(object sender, EventArgs e)
        {
            printDocument.Print();
        }
    }
}
