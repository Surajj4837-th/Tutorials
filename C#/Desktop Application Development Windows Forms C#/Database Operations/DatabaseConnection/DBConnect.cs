using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DatabaseConnection
{
    internal class DBConnect
    {
        private static string ConnectionString = "Data Source = (localdb)\\MSSQLLocalDB; AttachDbFilename=|DataDirectory|\\Data\\PhoneDirectory.mdf; Initial Catalog=PhoneDirectory; Integrated Security=True;";
        // Install localdb server to the target machine.
        //private static string ConnectionString = "Data Source = (localdb)\\BillingAppLocalDbServer; Initial Catalog=PhoneDirectory;User ID=sa;Password=billingsw";

        public static SqlConnection conn = new SqlConnection(ConnectionString);

        public void addUser(string name, long phone, int age, bool gender)
        {
            try
            {
                SqlCommand cmd = new SqlCommand("sp_insertData", conn);
                cmd.CommandType = System.Data.CommandType.StoredProcedure;
                cmd.Parameters.AddWithValue("@name", name);
                cmd.Parameters.AddWithValue("@phone", phone);
                cmd.Parameters.AddWithValue("@age", age);
                cmd.Parameters.AddWithValue("@gender", gender);

                conn.Open();
                int RecordsInserted = cmd.ExecuteNonQuery();  //Used for create, update and delete query. Separate query for select query.

                if (RecordsInserted > 0)
                {
                    MessageBox.Show("Data added successfully.");
                }
                else
                {
                    MessageBox.Show("Data addition failed!!!!");
                }
                conn.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}