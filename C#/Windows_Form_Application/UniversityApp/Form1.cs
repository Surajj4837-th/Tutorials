using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.ProgressBar;

namespace UniversityApp
{
    public partial class Form1 : Form
    {
        private DataTable dt_Courses = new DataTable();
        private DataTable dt_SelectedCourses = new DataTable();

        private void fillCoursesTable()
        {
            dt_Courses.Columns.Add("CourseID", typeof(int));
            dt_Courses.Columns.Add("CourseName");
            dt_Courses.Columns.Add("CourseDuration");

            dt_Courses.Rows.Add(1, "Advance OOP", "4 Months");
            dt_Courses.Rows.Add(2, "Maths", "1 Months");
            dt_Courses.Rows.Add(3, "Science", "1 Months");
            dt_Courses.Rows.Add(4, "Geography", "2 Months");
            dt_Courses.Rows.Add(5, "Web Designing", "6 Months");
        }

        private void SelectedCoursesTable()
        {
            dt_SelectedCourses.Columns.Add("CourseID", typeof(int));
            dt_SelectedCourses.Columns.Add("CourseName");
            dt_SelectedCourses.Columns.Add("CourseDuration");
        }
        public Form1()
        {
            InitializeComponent();
        }



        private void Form1_Load(object sender, EventArgs e)
        {
            fillCoursesTable();
            SelectedCoursesTable();

            listBox1.DataSource = dt_Courses;
            listBox1.DisplayMember = "CourseName";

            listBox2.DataSource = dt_SelectedCourses;
            listBox2.DisplayMember = "CourseName";
        }

        private void btn_Add_Click(object sender, EventArgs e)
        {
            if(listBox1.Items.Count > 0)
            {
                dt_SelectedCourses.ImportRow(dt_Courses.Rows[listBox1.SelectedIndex]);
                dt_Courses.Rows[listBox1.SelectedIndex].Delete();
            }
        }

        private void btn_Addall_Click(object sender, EventArgs e)
        {
            if (listBox1.Items.Count > 0)
            {
                int count = dt_Courses.Rows.Count;

                for(int i = count - 1; i >= 0; i--)
                {
                    dt_SelectedCourses.ImportRow(dt_Courses.Rows[listBox1.SelectedIndex]);
                    dt_Courses.Rows[listBox1.SelectedIndex].Delete();
                }
            }
        }

        private void btn_Rmvall_Click(object sender, EventArgs e)
        {
            int count = dt_SelectedCourses.Rows.Count;

            if (listBox2.Items.Count > 0)
            {
                for (int i = count - 1; i >= 0; i--)
                {
                    dt_Courses.ImportRow(dt_SelectedCourses.Rows[listBox2.SelectedIndex]);
                    dt_SelectedCourses.Rows[listBox2.SelectedIndex].Delete();
                }
            }
        }

        private void btn_Rmv_Click(object sender, EventArgs e)
        {
            if (listBox2.Items.Count > 0)
            {
                dt_Courses.ImportRow(dt_SelectedCourses.Rows[listBox2.SelectedIndex]);
                dt_SelectedCourses.Rows[listBox2.SelectedIndex].Delete();
            }
        }

        private void btn_finalize_Click(object sender, EventArgs e)
        {
            DialogResult result = MessageBox.Show("Are you sure to finalize selected courses?", "Confirmation Message", MessageBoxButtons.YesNo, MessageBoxIcon.Information);

            if (result == DialogResult.Yes && dt_SelectedCourses.Rows.Count > 0)
            {
                dataGridView1.DataSource = dt_SelectedCourses;

                dataGridView1.Enabled = false;  //Avoid editing of table by user

                dataGridView1.Columns[0].Visible = false;   // Avoid showing this column on screen

                dataGridView1.RowHeadersVisible = false;    // Avoid showing this header on screen

                dataGridView1.Columns[1].Width = 400;
                dataGridView1.Columns[2].Width = 400;
            }
            else
            {
                MessageBox.Show("Please select at least 1 course.", "Information", MessageBoxButtons.OK, MessageBoxIcon.Question);
            }
        }
    }
}
