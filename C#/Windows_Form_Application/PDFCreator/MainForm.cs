using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
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
        private int MainPageItemCount = 20;
        private int SecondPageItemCount = 31;
        DataTable items = new DataTable();

        int FirstColumn;
        int SecondColumn;
        int ThirdColumn;
        int FourthColumn;
        int FifthColumn;
        int SixthColumn;
        int SeventhColumn;
        int EighthColumn;

        int TableStartY;
        int TableEndY;

        int currentpage = 1;
        int numofpages = 2;

        public MainForm()
        {
            InitializeComponent();

            //Fill datatable
            FillDatatable(items);
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
            var CentreFormat = new StringFormat() { Alignment = StringAlignment.Center, LineAlignment = StringAlignment.Center };

            FirstColumn = (int)e.PageSettings.PrintableArea.Left + 40;
            SecondColumn = FirstColumn + 70;
            ThirdColumn = SecondColumn + 280;
            FourthColumn = ThirdColumn + 85;
            FifthColumn = FourthColumn + 85;
            SixthColumn = FifthColumn + 85;
            SeventhColumn = SixthColumn + 85;
            EighthColumn = (int)e.PageSettings.PrintableArea.Right - 40;

            TableStartY = 330;
            TableEndY = (int)e.PageSettings.PrintableArea.Height - 50;

            //Table header
            e.Graphics.FillRectangle(new SolidBrush(Color.Black), FirstColumn, TableStartY, e.PageSettings.PrintableArea.Width - 80, 40);
            //e.Graphics.DrawString("Sr. No.", fnt, Brushes.White, (FirstColumn + SecondColumn) / 2 - 25, TableStartY + 6);
            e.Graphics.DrawString("Sr. No.", fnt, Brushes.White, new Rectangle(FirstColumn, TableStartY, SecondColumn - FirstColumn, 40), CentreFormat);

            //e.Graphics.DrawString("Item", fnt, Brushes.White, (SecondColumn + ThirdColumn) / 2 - 15, TableStartY + 6);
            e.Graphics.DrawString("Item", fnt, Brushes.White, new Rectangle(SecondColumn, TableStartY, ThirdColumn - SecondColumn, 40), CentreFormat);

            //e.Graphics.DrawString("Quantity", fnt, Brushes.White, (ThirdColumn + FourthColumn) / 2 - 30, TableStartY + 6);
            e.Graphics.DrawString("Quantity", fnt, Brushes.White, new Rectangle(ThirdColumn, TableStartY, FourthColumn - ThirdColumn, 40), CentreFormat);

            //e.Graphics.DrawString("Rate", fnt, Brushes.White, (FourthColumn + FifthColumn) / 2 - 20, TableStartY + 6);
            e.Graphics.DrawString("Rate", fnt, Brushes.White, new Rectangle(FourthColumn, TableStartY, FifthColumn - FourthColumn, 40), CentreFormat);

            //e.Graphics.DrawString("SGST", fnt, Brushes.White, (FifthColumn + SixthColumn) / 2 - 20, TableStartY + 6);
            e.Graphics.DrawString("SGST", fnt, Brushes.White, new Rectangle(FifthColumn, TableStartY, SixthColumn - FifthColumn, 40), CentreFormat);

            //e.Graphics.DrawString("CGST", fnt, Brushes.White, (SixthColumn + SeventhColumn) / 2 - 15, TableStartY + 6);
            e.Graphics.DrawString("CGST", fnt, Brushes.White, new Rectangle(SixthColumn, TableStartY, SeventhColumn - SixthColumn, 40), CentreFormat);

            //e.Graphics.DrawString("Amount", fnt, Brushes.White, (SeventhColumn + EighthColumn) / 2 - 30, TableStartY + 6);
            e.Graphics.DrawString("Amount", fnt, Brushes.White, new Rectangle(SeventhColumn, TableStartY, EighthColumn - SeventhColumn, 40), CentreFormat);

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

            //Draw vertical lines
            //e.Graphics.DrawLine(new Pen(Color.Black), new Point(FirstColumn, TableStartY), new Point(FirstColumn, (int)e.PageSettings.PrintableArea.Height - 50));
            //e.Graphics.DrawLine(new Pen(Color.Black), new Point(SecondColumn, TableStartY), new Point(SecondColumn, (int)e.PageSettings.PrintableArea.Height - 50));
            e.Graphics.DrawRectangle(new Pen(Color.Black), new Rectangle(FirstColumn, TableStartY + 1, SecondColumn - FirstColumn, TableEndY - TableStartY - 1));

            //e.Graphics.DrawLine(new Pen(Color.Black), new Point(ThirdColumn, TableStartY), new Point(ThirdColumn, (int)e.PageSettings.PrintableArea.Height - 50));
            //e.Graphics.DrawLine(new Pen(Color.Black), new Point(FourthColumn, TableStartY), new Point(FourthColumn, (int)e.PageSettings.PrintableArea.Height - 50));
            e.Graphics.DrawRectangle(new Pen(Color.Black), new Rectangle(ThirdColumn, TableStartY + 1, FourthColumn - ThirdColumn, TableEndY - TableStartY - 1));


            //e.Graphics.DrawLine(new Pen(Color.Black), new Point(FifthColumn, TableStartY), new Point(FifthColumn, (int)e.PageSettings.PrintableArea.Height - 50));
            //e.Graphics.DrawLine(new Pen(Color.Black), new Point(SixthColumn, TableStartY), new Point(SixthColumn, (int)e.PageSettings.PrintableArea.Height - 50));
            e.Graphics.DrawRectangle(new Pen(Color.Black), new Rectangle(FifthColumn, TableStartY + 1, SixthColumn - FifthColumn, TableEndY - TableStartY - 1));


            //e.Graphics.DrawLine(new Pen(Color.Black), new Point(SeventhColumn, TableStartY), new Point(SeventhColumn, (int)e.PageSettings.PrintableArea.Height - 50));
            //e.Graphics.DrawLine(new Pen(Color.Black), new Point(EighthColumn, TableStartY), new Point(EighthColumn, (int)e.PageSettings.PrintableArea.Height - 50));
            e.Graphics.DrawRectangle(new Pen(Color.Black), new Rectangle(SeventhColumn, TableStartY + 1, EighthColumn - SeventhColumn, TableEndY - TableStartY - 1));

            e.Graphics.DrawLine(new Pen(Color.Black), new Point(FirstColumn, TableEndY), new Point(EighthColumn, TableEndY));
        }
        private void AddVendorAddressSection(PrintPageEventArgs e)
        {
            var format = new StringFormat() { Alignment = StringAlignment.Far, LineAlignment = StringAlignment.Center };

            //var rect1 = new Rectangle((int)e.PageSettings.PrintableArea.Width / 2, 70 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            //e.Graphics.DrawString("ABC LTD", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect1, format);
            ////e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect1);

            //var rect2 = new Rectangle((int)e.PageSettings.PrintableArea.Width / 2, 90 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            //e.Graphics.DrawString("Address 1", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect2, format);
            ////e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect2);

            //var rect3 = new Rectangle((int)e.PageSettings.PrintableArea.Width / 2, 110 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            //e.Graphics.DrawString("Address 2", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect3, format);
            ////e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect3);

            //var rect4 = new Rectangle((int)e.PageSettings.PrintableArea.Width / 2, 130 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            //e.Graphics.DrawString("Maharashtra, India", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect4, format);
            ////e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect4);

            //var rect5 = new Rectangle((int)e.PageSettings.PrintableArea.Width / 2, 150 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            //e.Graphics.DrawString("GST: XXXXX XXXXX XXXXX", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect5, format);
            ////e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect5);

            var rect = new Rectangle((int)e.PageSettings.PrintableArea.Width / 2, 70 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 100);
            e.Graphics.DrawString("ABC LTD,\nAddress 1,\nAddress 2,\nMaharashtra, India,\nGST: XXXXX XXXXX XXXXX", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect, format);
        }
        private void AddCustomerAddressSection(PrintPageEventArgs e)
        {
            //var rect1 = new Rectangle((int)e.PageSettings.PrintableArea.Left + 40 + 2, 70 + 125 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            //e.Graphics.DrawString("Bill To:", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect1);
            ////e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect1);

            //var rect2 = new Rectangle((int)e.PageSettings.PrintableArea.Left + 40 + 2, 90 + 125 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            //e.Graphics.DrawString("XYZ LTD", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect2);
            ////e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect2);

            //var rect3 = new Rectangle((int)e.PageSettings.PrintableArea.Left + 40 + 2, 110 + 125 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            //e.Graphics.DrawString("Address 1", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect3);
            ////e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect3);

            //var rect4 = new Rectangle((int)e.PageSettings.PrintableArea.Left + 40 + 2, 130 + 125 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            //e.Graphics.DrawString("Address 2", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect4);
            ////e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect4);

            //var rect5 = new Rectangle((int)e.PageSettings.PrintableArea.Left + 40 + 2, 150 + 125 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 20);
            //e.Graphics.DrawString("Maharashtra, India", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect5);
            ////e.Graphics.DrawRectangle(new Pen(Brushes.Blue), rect5);

            var rect = new Rectangle((int)e.PageSettings.PrintableArea.Left + 40 + 2, 70 + 125 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 100);
            e.Graphics.DrawString("Bill To:\nXYZ LTD\nAddress 1\nAddress 2\nMaharashtra, India", new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect);

        }
        private void AddBillDetailsSection(PrintPageEventArgs e)
        {
            var format = new StringFormat() { Alignment = StringAlignment.Far, LineAlignment = StringAlignment.Center };

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
            items.Rows.Add("Name1", "Item2", "123", "10", "1.5", "1.5", "10000");
            items.Rows.Add("Name1", "Item3", "123", "10", "1.5", "1.5", "10000");
            items.Rows.Add("Name1", "Item4", "123", "10", "1.5", "1.5", "10000");
            items.Rows.Add("Name1", "Item5", "123", "10", "1.5", "1.5", "10000");
            items.Rows.Add("Name1", "Item6", "123", "10", "1.5", "1.5", "10000");
        }

        private int FillItemTable(PrintPageEventArgs e, DataTable items)
        {
            int StartRow = TableStartY + 30;
            int SrNo = 1;
            var NearFormat = new StringFormat() { Alignment = StringAlignment.Near, LineAlignment = StringAlignment.Center };
            var CentreFormat = new StringFormat() { Alignment = StringAlignment.Center, LineAlignment = StringAlignment.Center };
            var FarFormat = new StringFormat() { Alignment = StringAlignment.Far, LineAlignment = StringAlignment.Center };

            for (int item = 0; item < items.Rows.Count; item++)
            {
                var rect1 = new Rectangle(FirstColumn, StartRow, SecondColumn - FirstColumn - 1, 30);
                var rect2 = new Rectangle(SecondColumn, StartRow, ThirdColumn - SecondColumn - 1, 30);
                var rect3 = new Rectangle(ThirdColumn, StartRow, FourthColumn - ThirdColumn - 1, 30);
                var rect4 = new Rectangle(FourthColumn, StartRow, FifthColumn - FourthColumn - 1, 30);
                var rect5 = new Rectangle(FifthColumn, StartRow, SixthColumn - FifthColumn - 1, 30);
                var rect6 = new Rectangle(SixthColumn, StartRow, SeventhColumn - SixthColumn - 1, 30);
                var rect7 = new Rectangle(SeventhColumn, StartRow, EighthColumn - SeventhColumn - 1, 30);

                e.Graphics.DrawString(SrNo.ToString(), new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect1, CentreFormat);
                e.Graphics.DrawString(items.Rows[item]["Item"].ToString(), new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect2, NearFormat);
                e.Graphics.DrawString(items.Rows[item]["Quantity"].ToString(), new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect3, FarFormat);
                e.Graphics.DrawString(items.Rows[item]["Rate"].ToString(), new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect4, FarFormat);
                e.Graphics.DrawString(items.Rows[item]["SGST"].ToString(), new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect5, FarFormat);
                e.Graphics.DrawString(items.Rows[item]["CGST"].ToString(), new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect6, FarFormat);
                e.Graphics.DrawString(items.Rows[item]["Amount"].ToString(), new Font("Arial", 12, FontStyle.Regular), Brushes.Black, rect7, FarFormat);

                StartRow += 30;
                SrNo++;
            }
            return StartRow;
        }

        private string ComputeSubTotal()
        {
            return "1000";
        }

        private string ComputeSGST()
        {
            return "100";
        }

        private string ComputeCGST()
        {
            return "100";
        }

        private string ComputeTotalAmount()
        {
            return "1200";
        }
        private int FillFinalAmountTable(PrintPageEventArgs e, DataTable items, int StartRow)
        {
            StartRow += 30;

            var NearFormat = new StringFormat() { Alignment = StringAlignment.Near, LineAlignment = StringAlignment.Center };
            var FarFormat = new StringFormat() { Alignment = StringAlignment.Far, LineAlignment = StringAlignment.Center };

            var rect1 = new Rectangle(FourthColumn + 20 , StartRow, SixthColumn - FourthColumn - 20 - 1, 30);
            var rect2 = new Rectangle(SixthColumn, StartRow, EighthColumn - SixthColumn - 1, 30);
            StartRow += 30;
            var rect3 = new Rectangle(FourthColumn + 20 , StartRow, SixthColumn - FourthColumn - 20 - 1, 30);
            var rect4 = new Rectangle(SixthColumn, StartRow, EighthColumn - SixthColumn - 1, 30);
            StartRow += 30;
            var rect5 = new Rectangle(FourthColumn + 20, StartRow, SixthColumn - FourthColumn - 20 - 1, 30);
            var rect6 = new Rectangle(SixthColumn, StartRow, EighthColumn - SixthColumn - 1, 30);
            StartRow += 30;
            var rect7 = new Rectangle(FourthColumn + 20, StartRow, SixthColumn - FourthColumn - 20 - 1, 30);
            var rect8 = new Rectangle(SixthColumn, StartRow, EighthColumn - SixthColumn - 1, 30);

            e.Graphics.DrawString("Sub total", new Font("Arial", 14, FontStyle.Regular), Brushes.Black, rect1, NearFormat);
            e.Graphics.DrawString(ComputeSubTotal(), new Font("Arial", 14, FontStyle.Regular), Brushes.Black, rect2, FarFormat);

            e.Graphics.DrawString("SGST", new Font("Arial", 14, FontStyle.Regular), Brushes.Black, rect3, NearFormat);
            e.Graphics.DrawString(ComputeSGST(), new Font("Arial", 14, FontStyle.Regular), Brushes.Black, rect4, FarFormat);

            e.Graphics.DrawString("CGST", new Font("Arial", 14, FontStyle.Regular), Brushes.Black, rect5, NearFormat);
            e.Graphics.DrawString(ComputeCGST(), new Font("Arial", 14, FontStyle.Regular), Brushes.Black, rect6, FarFormat);

            e.Graphics.DrawString("Total Amount", new Font("Arial", 14, FontStyle.Bold), Brushes.Black, rect7, NearFormat);
            e.Graphics.DrawString(ComputeTotalAmount(), new Font("Arial", 14, FontStyle.Bold), Brushes.Black, rect8, FarFormat);

            return StartRow;
        }

        private int FindNumberOfPages(DataTable items)
        {
            int numOfPages = 0;

            //Count number of items in data table
            int quantity = items.Rows.Count;

            if(quantity <= MainPageItemCount)
            {
                numOfPages = 1;
            }
            else
            {
                decimal temp = quantity - MainPageItemCount; // Subtracting 1st page items.
                int remainingPages = (int)Math.Ceiling(temp / SecondPageItemCount);

                numOfPages = 1 + remainingPages;
            }

            return numOfPages;
        }

        private void printDocument_PrintPage(object sender, System.Drawing.Printing.PrintPageEventArgs e)
        {
            numofpages = FindNumberOfPages(items);
            var stopwatch = new Stopwatch();
            long totalTime = 0;

            if (currentpage == 1)
            {
                //Usable Area
                stopwatch.Start();
                ShowUsableArea(e);
                stopwatch.Stop();
                long elapsed_time = stopwatch.ElapsedMilliseconds;
                Console.WriteLine("ShowUsableArea time: " + elapsed_time.ToString() + "ms");
                totalTime += elapsed_time;

                stopwatch.Restart();
                CreateHeaderLine(e);
                stopwatch.Stop();
                elapsed_time = stopwatch.ElapsedMilliseconds;
                Console.WriteLine("CreateHeaderLine time: " + elapsed_time.ToString() + "ms");
                totalTime += elapsed_time;

                // Add logo
                stopwatch.Restart();
                AddLogo(e);
                stopwatch.Stop();
                elapsed_time = stopwatch.ElapsedMilliseconds;
                Console.WriteLine("AddLogo time: " + elapsed_time.ToString() + "ms");
                totalTime += elapsed_time;

                // Add vendor address
                stopwatch.Restart();
                AddVendorAddressSection(e);
                stopwatch.Stop();
                elapsed_time = stopwatch.ElapsedMilliseconds;
                Console.WriteLine("AddVendorAddressSection time: " + elapsed_time.ToString() + "ms");
                totalTime += elapsed_time;

                // Add customer address
                stopwatch.Restart();
                AddCustomerAddressSection(e);
                stopwatch.Stop();
                elapsed_time = stopwatch.ElapsedMilliseconds;
                Console.WriteLine("AddCustomerAddressSection time: " + elapsed_time.ToString() + "ms");
                totalTime += elapsed_time;

                // Add bill details
                stopwatch.Restart();
                AddBillDetailsSection(e);
                stopwatch.Stop();
                elapsed_time = stopwatch.ElapsedMilliseconds;
                Console.WriteLine("AddBillDetailsSection time: " + elapsed_time.ToString() + "ms");
                totalTime += elapsed_time;

                // Create Table
                stopwatch.Restart();
                CreateTable(e);
                stopwatch.Stop();
                elapsed_time = stopwatch.ElapsedMilliseconds;
                Console.WriteLine("CreateTable time: " + elapsed_time.ToString() + "ms");
                totalTime += elapsed_time;

                //Show page number
                stopwatch.Restart();
                ShowPageNumber(e, "1");
                stopwatch.Stop();
                elapsed_time = stopwatch.ElapsedMilliseconds;
                Console.WriteLine("ShowPageNumber time: " + elapsed_time.ToString() + "ms");
                totalTime += elapsed_time;

                //Fill table
                stopwatch.Restart();
                int TableEndRow = FillItemTable(e, items);
                stopwatch.Stop();
                elapsed_time = stopwatch.ElapsedMilliseconds;
                Console.WriteLine("FillItemTable time: " + elapsed_time.ToString() + "ms");
                totalTime += elapsed_time;

                //Fill final amount
                stopwatch.Restart();
                int NextItemStartRow = FillFinalAmountTable(e, items, TableEndRow);
                stopwatch.Stop();
                elapsed_time = stopwatch.ElapsedMilliseconds;
                Console.WriteLine("FillFinalAmountTable time: " + elapsed_time.ToString() + "ms");
                totalTime += elapsed_time;


                Console.WriteLine("Total Time time: " + totalTime.ToString() + "ms");
            }
            else if (currentpage == 2)
            {
                Bitmap bmp = Properties.Resources.Logo;
                Image newImage = bmp;
                e.Graphics.DrawImage(newImage, 20, 20);
                e.Graphics.DrawString(currentpage.ToString(), new Font("Verdana", 10, FontStyle.Bold), Brushes.Black, 600, 350);
            }

            //e.HasMorePages = currentpage < numofpages;
            //currentpage++;

        }

        private void print_Click(object sender, EventArgs e)
        {
            printDocument.Print();
        }
    }
}

/*
ShowUsableArea time: 657ms
CreateHeaderLine time: 161ms
AddLogo time: 1260ms
AddVendorAddressSection time: 1632ms
AddCustomerAddressSection time: 1637ms
AddBillDetailsSection time: 1350ms
CreateTable time: 6001ms
ShowPageNumber time: 933ms
FillItemTable time: 1ms
FillFinalAmountTable time: 1ms
Total Time time: 13633ms
*/