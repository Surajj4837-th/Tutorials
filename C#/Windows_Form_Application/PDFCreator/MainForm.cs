﻿using System;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Printing;
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

        Font font_Arial_12 = new Font("Arial", 12, FontStyle.Regular);
        Font font_Arial_13 = new Font("Arial", 13, FontStyle.Regular);
        Font font_Arial_14 = new Font("Arial", 14, FontStyle.Regular);
        Font font_Arial_15 = new Font("Arial", 15, FontStyle.Regular);

        Pen pen_Black = new Pen(Color.Black);

        SolidBrush solidbrush_black = new SolidBrush(Color.Black);
        SolidBrush solidbrush_white = new SolidBrush(Color.White);
        SolidBrush solidbrush_LightGray = new SolidBrush(Color.LightGray);

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

            e.Graphics.DrawString("TAX INVOICE", font_Arial_15, Brushes.Black, new Point(40, 40));
            e.Graphics.DrawLine(pen_Black, new Point(180, 50), new Point(RightBound, 50));
        }
        private void ShowUsableArea(PrintPageEventArgs e)
        {
            e.Graphics.DrawRectangle(new Pen(Color.Yellow), e.PageSettings.PrintableArea.Left + 40, e.PageSettings.PrintableArea.Top + 40, e.PageSettings.PrintableArea.Width - 80, e.PageSettings.PrintableArea.Height - 80);
        }
        private void ShowPageNumber(PrintPageEventArgs e, string pageNumber)
        {
            Point point1 = new Point((int)e.PageSettings.PrintableArea.Left + 40, (int)e.PageSettings.PrintableArea.Height - 40);
            Point point2 = new Point((int)e.PageSettings.PrintableArea.Width - 40, (int)e.PageSettings.PrintableArea.Height - 40);
            Point point3 = new Point((int)e.PageSettings.PrintableArea.Width / 2, (int)e.PageSettings.PrintableArea.Height - 30);

            e.Graphics.DrawLine(pen_Black, point1, point2);
            e.Graphics.DrawString(pageNumber, font_Arial_13, Brushes.Black, point3);
        }
        private void AddLogo(PrintPageEventArgs e)
        {
            e.Graphics.DrawRectangle(pen_Black, e.PageSettings.PrintableArea.Left + 40, 70, e.PageSettings.PrintableArea.Width/2 - 40, 125);
            e.Graphics.DrawRectangle(pen_Black, e.PageSettings.PrintableArea.Left + 40, 70 + 125, e.PageSettings.PrintableArea.Width/2 - 40, 125);

            e.Graphics.DrawRectangle(pen_Black, e.PageSettings.PrintableArea.Width / 2, 70, e.PageSettings.PrintableArea.Width / 2 - 40, 125);
            e.Graphics.DrawRectangle(pen_Black, e.PageSettings.PrintableArea.Width / 2, 70 + 125, e.PageSettings.PrintableArea.Width / 2 - 40, 125);

            // Add Logo
            var img = new Bitmap(Resources.Resource1.SampleLogo72);
            e.Graphics.DrawImage(img, new Rectangle(60, 75, img.Width / 2, img.Height / 2));
            e.Graphics.DrawRectangle(pen_Black, new Rectangle(60, 75, img.Width / 2, img.Height / 2));

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
            e.Graphics.FillRectangle(solidbrush_black, FirstColumn, TableStartY, e.PageSettings.PrintableArea.Width - 80, 40);

            e.Graphics.DrawString("Sr. No.", font_Arial_13, Brushes.White, new Rectangle(FirstColumn, TableStartY, SecondColumn - FirstColumn, 40), CentreFormat);

            e.Graphics.DrawString("Item", font_Arial_13, Brushes.White, new Rectangle(SecondColumn, TableStartY, ThirdColumn - SecondColumn, 40), CentreFormat);

            e.Graphics.DrawString("Quantity", font_Arial_13, Brushes.White, new Rectangle(ThirdColumn, TableStartY, FourthColumn - ThirdColumn, 40), CentreFormat);

            e.Graphics.DrawString("Rate", font_Arial_13, Brushes.White, new Rectangle(FourthColumn, TableStartY, FifthColumn - FourthColumn, 40), CentreFormat);

            e.Graphics.DrawString("SGST", font_Arial_13, Brushes.White, new Rectangle(FifthColumn, TableStartY, SixthColumn - FifthColumn, 40), CentreFormat);

            e.Graphics.DrawString("CGST", font_Arial_13, Brushes.White, new Rectangle(SixthColumn, TableStartY, SeventhColumn - SixthColumn, 40), CentreFormat);

            e.Graphics.DrawString("Amount", font_Arial_13, Brushes.White, new Rectangle(SeventhColumn, TableStartY, EighthColumn - SeventhColumn, 40), CentreFormat);

            bool IsEven = true;

            //Table rows
            int i = 0;
            for(i = TableStartY + 30; i < TableEndY; i+=30)
            {
                if (IsEven)
                {
                    e.Graphics.FillRectangle(solidbrush_white, FirstColumn, i, e.PageSettings.PrintableArea.Width - 80, 40);
                    IsEven = false;
                }
                else
                {
                    e.Graphics.FillRectangle(solidbrush_LightGray, FirstColumn, i, e.PageSettings.PrintableArea.Width - 80, 40);
                    IsEven = true;
                }
            }

            //Draw vertical lines of table using DrawRectangle()
            e.Graphics.DrawRectangle(pen_Black, new Rectangle(FirstColumn, TableStartY + 1, SecondColumn - FirstColumn, TableEndY - TableStartY - 1));

            e.Graphics.DrawRectangle(pen_Black, new Rectangle(ThirdColumn, TableStartY + 1, FourthColumn - ThirdColumn, TableEndY - TableStartY - 1));

            e.Graphics.DrawRectangle(pen_Black, new Rectangle(FifthColumn, TableStartY + 1, SixthColumn - FifthColumn, TableEndY - TableStartY - 1));

            e.Graphics.DrawRectangle(pen_Black, new Rectangle(SeventhColumn, TableStartY + 1, EighthColumn - SeventhColumn, TableEndY - TableStartY - 1));

            e.Graphics.DrawLine(pen_Black, new Point(FirstColumn, TableEndY), new Point(EighthColumn, TableEndY));
        }
        private void AddVendorAddressSection(PrintPageEventArgs e)
        {
            var format = new StringFormat() { Alignment = StringAlignment.Far, LineAlignment = StringAlignment.Center };

            var rect = new Rectangle((int)e.PageSettings.PrintableArea.Width / 2, 70 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 100);
            e.Graphics.DrawString("ABC LTD,\nAddress 1,\nAddress 2,\nMaharashtra, India,\nGST: XXXXX XXXXX XXXXX", font_Arial_12, Brushes.Black, rect, format);
        }
        private void AddCustomerAddressSection(PrintPageEventArgs e)
        {
            var rect = new Rectangle((int)e.PageSettings.PrintableArea.Left + 40 + 2, 70 + 125 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 100);
            e.Graphics.DrawString("Bill To:\nXYZ LTD\nAddress 1\nAddress 2\nMaharashtra, India", font_Arial_12, Brushes.Black, rect);
        }
        private void AddBillDetailsSection(PrintPageEventArgs e)
        {
            var format = new StringFormat() { Alignment = StringAlignment.Far, LineAlignment = StringAlignment.Center };

            var rect = new Rectangle((int)e.PageSettings.PrintableArea.Width / 2, 70 + 125 + 4, (int)e.PageSettings.PrintableArea.Width / 2 - 40, 80);
            e.Graphics.DrawString("Invoice ID: XXXXXXXXXXXX\nAdmin: XXXX XXXX\nDate: XX/XX/XXXX\nTime: XX:XX:XX", font_Arial_12, Brushes.Black, rect, format);
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

                e.Graphics.DrawString(SrNo.ToString(), font_Arial_12, Brushes.Black, rect1, CentreFormat);
                e.Graphics.DrawString(items.Rows[item]["Item"].ToString(), font_Arial_12, Brushes.Black, rect2, NearFormat);
                e.Graphics.DrawString(items.Rows[item]["Quantity"].ToString(), font_Arial_12, Brushes.Black, rect3, FarFormat);
                e.Graphics.DrawString(items.Rows[item]["Rate"].ToString(), font_Arial_12, Brushes.Black, rect4, FarFormat);
                e.Graphics.DrawString(items.Rows[item]["SGST"].ToString(), font_Arial_12, Brushes.Black, rect5, FarFormat);
                e.Graphics.DrawString(items.Rows[item]["CGST"].ToString(), font_Arial_12, Brushes.Black, rect6, FarFormat);
                e.Graphics.DrawString(items.Rows[item]["Amount"].ToString(), font_Arial_12, Brushes.Black, rect7, FarFormat);

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

            e.Graphics.DrawString("Sub total", font_Arial_14, Brushes.Black, rect1, NearFormat);
            e.Graphics.DrawString(ComputeSubTotal(), font_Arial_14, Brushes.Black, rect2, FarFormat);

            e.Graphics.DrawString("SGST", font_Arial_14, Brushes.Black, rect3, NearFormat);
            e.Graphics.DrawString(ComputeSGST(), font_Arial_14, Brushes.Black, rect4, FarFormat);

            e.Graphics.DrawString("CGST", font_Arial_14, Brushes.Black, rect5, NearFormat);
            e.Graphics.DrawString(ComputeCGST(), font_Arial_14, Brushes.Black, rect6, FarFormat);

            e.Graphics.DrawString("Total Amount", font_Arial_14, Brushes.Black, rect7, NearFormat);
            e.Graphics.DrawString(ComputeTotalAmount(), font_Arial_14, Brushes.Black, rect8, FarFormat);

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
            long elapsed_time = 0;

            if (currentpage == 1)
            {
                //Usable Area
                //stopwatch.Start();
                //ShowUsableArea(e);
                //stopwatch.Stop();
                //elapsed_time = stopwatch.ElapsedMilliseconds;
                //Console.WriteLine("ShowUsableArea time: " + elapsed_time.ToString() + "ms");
                //totalTime += elapsed_time;

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
CreateHeaderLine time: 160ms
AddLogo time: 1377ms
AddVendorAddressSection time: 308ms
AddCustomerAddressSection time: 318ms
AddBillDetailsSection time: 312ms
CreateTable time: 4552ms
ShowPageNumber time: 941ms
FillItemTable time: 1ms
FillFinalAmountTable time: 0ms
Total Time time: 7969ms
*/