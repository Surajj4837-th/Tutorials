using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Drawing;
using System.Diagnostics;

namespace LicenseKeyGenerationAndActivation
{
    internal class Activationmanager
    {
        public static string GenerateActivationKey(string userId)
        {
            // Create a unique key using userId and some other data
            string rawKey = userId + DateTime.Now.ToString("yyyyMMdd");

            // Hash the key using SHA256
            using (SHA256 sha256 = SHA256.Create())
            {
                byte[] text = Encoding.UTF8.GetBytes(rawKey);
                byte[] bytes = sha256.ComputeHash(Encoding.UTF8.GetBytes(rawKey));
                StringBuilder builder = new StringBuilder();

                foreach (byte b in bytes)
                {
                    String temp = b.ToString("x2");
                    builder.Append(temp);
                    //byte value = Convert.ToByte(temp, 16);
                }

                Debug.WriteLine("Activation Key: ", builder.ToString());

                return builder.ToString();
            }
        }
    }
}
