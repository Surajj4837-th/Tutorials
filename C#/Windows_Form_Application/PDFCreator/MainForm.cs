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
        private int MainPageItemCount = 16;
        private int SecondPageItemCount = 16;
        DataTable items = new DataTable();

        int currentpage = 1;
        int numofpages = 1;

        public MainForm()
        {
            InitializeComponent();

            //Fill datatable
            FillDatatable(items);

            //if(items.Rows.Count > 16)
            //{
            //    numofpages = 2;
            //}
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
            printPreviewDialog.Document.DefaultPageSettings.PaperSize = new System.Drawing.Printing.PaperSize("PaperA4", 840, 1180);
            printPreviewDialog.ShowDialog();
        }

        private void CreateHeaderLine(PrintPageEventArgs e)
        {
            int RightBound = (int)e.PageSettings.PrintableArea.Right - 40;

            e.Graphics.DrawString("TAX INVOICE", new Font("Arial", 15, FontStyle.Regular), Brushes.Black, new Point(40, 40));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(180, 50), new Point(RightBound, 50));
        }
        private void ShowUsableArea(PrintPageEventArgs e)
        {
            e.Graphics.DrawRectangle(new Pen(Color.Yellow), e.PageSettings.PrintableArea.Left + 40, e.PageSettings.PrintableArea.Top + 40, e.PageSettings.PrintableArea.Width - 80, e.PageSettings.PrintableArea.Height - 80);
        }
        private void ShowPageNumber(PrintPageEventArgs e, string pageNumber)
        {
            e.Graphics.DrawLine(new Pen(Color.Black), new Point((int)e.PageSettings.PrintableArea.Left + 40, (int)e.PageSettings.PrintableArea.Height - 40), new Point((int)e.PageSettings.PrintableArea.Width - 40, (int)e.PageSettings.PrintableArea.Height - 40));
            e.Graphics.DrawString(pageNumber, fnt, Brushes.Black, new Point((int)e.PageSettings.PrintableArea.Width / 2, (int)e.PageSettings.PrintableArea.Height - 30));
        }
        private void AddLogo(PrintPageEventArgs e)
        {
            e.Graphics.DrawRectangle(new Pen(Color.Black), e.PageSettings.PrintableArea.Left + 40, 70, e.PageSettings.PrintableArea.Width/2 - 40, 125);
            e.Graphics.DrawRectangle(new Pen(Color.Black), e.PageSettings.PrintableArea.Left + 40, 70 + 125, e.PageSettings.PrintableArea.Width/2 - 40, 125);

            e.Graphics.DrawRectangle(new Pen(Color.Black), e.PageSettings.PrintableArea.Width / 2, 70, e.PageSettings.PrintableArea.Width / 2 - 40, 125);
            e.Graphics.DrawRectangle(new Pen(Color.Black), e.PageSettings.PrintableArea.Width / 2, 70 + 125, e.PageSettings.PrintableArea.Width / 2 - 40, 125);

            // Add Logo
            var img = new Bitmap("C:\\Users\\admin\\source\\repos\\Tutorials\\C#\\Windows_Form_Application\\PDFCreator\\Resources\\SampleLogo72.png");
            e.Graphics.DrawImage(img, new Rectangle(60, 75, img.Width / 2, img.Height / 2));
            e.Graphics.DrawRectangle(new Pen(Brushes.Black), new Rectangle(60, 75, img.Width / 2, img.Height / 2));

        }
        private void CreateTable(PrintPageEventArgs e)
        {
            int FirstColumn = (int)e.PageSettings.PrintableArea.Left + 40;
            int SecondColumn = FirstColumn + 70;
            int ThirdColumn = SecondColumn + 280;
            int FourthColumn = ThirdColumn + 85;
            int FifthColumn = FourthColumn + 85;
            int SixthColumn = FifthColumn + 85;
            int SeventhColumn = SixthColumn + 85;
            int EighthColumn = (int)e.PageSettings.PrintableArea.Right - 40;

            int TableStartY = 330;
            int TableEndY = 1040;

            //Table header
            e.Graphics.FillRectangle(new SolidBrush(Color.Black), FirstColumn, TableStartY, e.PageSettings.PrintableArea.Width - 80, 40);
            e.Graphics.DrawString("Sr. No.", fnt, Brushes.White, (FirstColumn + SecondColumn)/2 - 25, TableStartY + 6);
            e.Graphics.DrawString("Item", fnt, Brushes.White, (SecondColumn + ThirdColumn) / 2 - 15, TableStartY + 6);
            e.Graphics.DrawString("Quantity", fnt, Brushes.White, (ThirdColumn + FourthColumn) / 2 - 30, TableStartY + 6);
            e.Graphics.DrawString("Rate", fnt, Brushes.White, (FourthColumn + FifthColumn) / 2 - 20, TableStartY + 6);
            e.Graphics.DrawString("SGST", fnt, Brushes.White, (FifthColumn + SixthColumn) / 2 - 20, TableStartY + 6);
            e.Graphics.DrawString("CGST", fnt, Brushes.White, (SixthColumn + SeventhColumn) / 2 - 15, TableStartY + 6);
            e.Graphics.DrawString("Amount", fnt, Brushes.White, (SeventhColumn + EighthColumn) / 2 - 30, TableStartY + 6);

            bool IsEven = true;

            //Table rows
            int i = 0;
            for(i = TableStartY + 30; i < TableEndY; i+=30)
            {
                if (IsEven)
                {
                    e.Graphics.FillRectangle(new SolidBrush(Color.White), FirstColumn, i, e.PageSettings.PrintableArea.Width - 80, 40);
                    IsEven = false;
                }
                else
                {
                    e.Graphics.FillRectangle(new SolidBrush(Color.LightGray), FirstColumn, i, e.PageSettings.PrintableArea.Width - 80, 40);
                    IsEven = true;
                }
            }

            //for(i = TableStartY + 40; i < (int)e.PageSettings.PrintableArea.Height; i += 40)
            //{
            //    e.Graphics.DrawString(i.ToString(), fnt, Brushes.Black, new Point(FirstColumn, i));
            //}

            //Draw vertical lines
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(FirstColumn, TableStartY), new Point(FirstColumn, (int)e.PageSettings.PrintableArea.Height - 50));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(SecondColumn, TableStartY), new Point(SecondColumn, (int)e.PageSettings.PrintableArea.Height - 50));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(ThirdColumn, TableStartY), new Point(ThirdColumn, (int)e.PageSettings.PrintableArea.Height - 50));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(FourthColumn, TableStartY), new Point(FourthColumn, (int)e.PageSettings.PrintableArea.Height - 50));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(FifthColumn, TableStartY), new Point(FifthColumn, (int)e.PageSettings.PrintableArea.Height - 50));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(SixthColumn, TableStartY), new Point(SixthColumn, (int)e.PageSettings.PrintableArea.Height - 50));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(SeventhColumn, TableStartY), new Point(SeventhColumn, (int)e.PageSettings.PrintableArea.Height - 50));
            e.Graphics.DrawLine(new Pen(Color.Black), new Point(EighthColumn, TableStartY), new Point(EighthColumn, (int)e.PageSettings.PrintableArea.Height - 50));

            e.Graphics.DrawLine(new Pen(Color.Black), new Point(FirstColumn, (int)e.PageSettings.PrintableArea.Height - 50), new Point(EighthColumn, (int)e.PageSettings.PrintableArea.Height - 50));
        }
        private void AddVendorAddressSection(PrintPageEventArgs e)
        {
            var format = new StringFormat() { Alignment = StringAlignment.Far };

            var rect1 = new Rectangle((int)e.PageSettings.PrintableArea.Width / 2, 70 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            e.Graphics.DrawString("ABC LTD", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect1, format);
            //e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect1);

            var rect2 = new Rectangle((int)e.PageSettings.PrintableArea.Width / 2, 90 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            e.Graphics.DrawString("Address 1", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect2, format);
            //e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect2);

            var rect3 = new Rectangle((int)e.PageSettings.PrintableArea.Width / 2, 110 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            e.Graphics.DrawString("Address 2", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect3, format);
            //e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect3);

            var rect4 = new Rectangle((int)e.PageSettings.PrintableArea.Width / 2, 130 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            e.Graphics.DrawString("Maharashtra, India", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect4, format);
            //e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect4);

            var rect5 = new Rectangle((int)e.PageSettings.PrintableArea.Width / 2, 150 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            e.Graphics.DrawString("GST: XXXXX XXXXX XXXXX", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect5, format);
            //e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect5);
        }
        private void AddCustomerAddressSection(PrintPageEventArgs e)
        {
            var rect1 = new Rectangle((int)e.PageSettings.PrintableArea.Left + 40 + 2, 70 + 125 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            e.Graphics.DrawString("Bill To:", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect1);
            //e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect1);

            var rect2 = new Rectangle((int)e.PageSettings.PrintableArea.Left + 40 + 2, 90 + 125 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            e.Graphics.DrawString("XYZ LTD", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect2);
            //e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect2);

            var rect3 = new Rectangle((int)e.PageSettings.PrintableArea.Left + 40 + 2, 110 + 125 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            e.Graphics.DrawString("Address 1", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect3);
            //e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect3);

            var rect4 = new Rectangle((int)e.PageSettings.PrintableArea.Left + 40 + 2, 130 + 125 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            e.Graphics.DrawString("Address 2", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect4);
            //e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect4);

            var rect5 = new Rectangle((int)e.PageSettings.PrintableArea.Left + 40 + 2, 150 + 125 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            e.Graphics.DrawString("Maharashtra, India", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect5);
            //e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect5);
        }
        private void AddBillDetailsSection(PrintPageEventArgs e)
        {
            var format = new StringFormat() { Alignment = StringAlignment.Far };

            var rect1 = new Rectangle((int)e.PageSettings.PrintableArea.Width / 2, 70 + 125 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            e.Graphics.DrawString("Invoice ID: XXXXXXXXXXXX", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect1, format);
            //e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect1);

            var rect2 = new Rectangle((int)e.PageSettings.PrintableArea.Width / 2, 90 + 125 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            e.Graphics.DrawString("Admin: XXXX XXXX", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect2, format);
            //e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect2);

            var rect3 = new Rectangle((int)e.PageSettings.PrintableArea.Width / 2, 110 + 125 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            e.Graphics.DrawString("Date: XX/XX/XXXX", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect3, format);
            //e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect3);

            var rect4 = new Rectangle((int)e.PageSettings.PrintableArea.Width / 2, 130 + 125 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            e.Graphics.DrawString("Time: XX:XX:XX", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect4, format);
            //e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect4);
        }

        void FillDatatable(DataTable items)
        {
            items.Columns.Add("Sr. No.");
            items.Columns.Add("Item");
            items.Columns.Add("Quantity");
            items.Columns.Add("Rate");
            items.Columns.Add("SGST");
            items.Columns.Add("CGST");
            items.Columns.Add("Amount");

            DataRow row = items.NewRow();
            row["Sr. No."] = "Name1";
            row["Item"] = "Item1";
            row["Quantity"] = "123";
            row["Rate"] = "10";
            row["SGST"] = "1.5";
            row["CGST"] = "1.5";
            row["Amount"] = "10000";

            items.Rows.Add(row);
            items.Rows.Add("Name1", "Item1", "123", "10", "1.5", "1.5", "10000");
            items.Rows.Add("Name1", "Item1", "123", "10", "1.5", "1.5", "10000");
            items.Rows.Add("Name1", "Item1", "123", "10", "1.5", "1.5", "10000");
            items.Rows.Add("Name1", "Item1", "123", "10", "1.5", "1.5", "10000");
            items.Rows.Add("Name1", "Item1", "123", "10", "1.5", "1.5", "10000");
        }


        private void printDocument_PrintPage(object sender, System.Drawing.Printing.PrintPageEventArgs e)
        {
            //currentpage++;

            if (currentpage == 1)
            {
                //Usable Area
                ShowUsableArea(e);

                CreateHeaderLine(e);

                // Add logo
                AddLogo(e);

                // Add vendor address
                AddVendorAddressSection(e);

                // Add customer address
                AddCustomerAddressSection(e);

                // Add bill details
                AddBillDetailsSection(e);

                // Create Table
                CreateTable(e);

                //Show page number
                ShowPageNumber(e, "1");
            }
            //else if (currentpage == 2)
            //{
            //    Bitmap bmp = Properties.Resources.Logo;
            //    Image newImage = bmp;
            //    e.Graphics.DrawImage(newImage, 20, 20);
            //    e.Graphics.DrawString(currentpage.ToString(), new Font("Verdana", 10, FontStyle.Bold), Brushes.Black, 600, 350);
            //}

            //e.HasMorePages = currentpage < numofpages;

        }

        private void print_Click(object sender, EventArgs e)
        {
            printDocument.Print();
        }
    }
}
