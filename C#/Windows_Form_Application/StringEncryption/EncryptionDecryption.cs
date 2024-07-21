using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace StringEncryption
{
    internal class EncryptionDecryption
    {
        // Source - https://learn.microsoft.com/en-us/dotnet/api/system.security.cryptography.rfc2898derivebytes?view=net-8.0&redirectedfrom=MSDN

        // Generate a key k1 with password pwd1 and salt salt1.
        // Generate a key k2 with password pwd1 and salt salt1.
        // Encrypt data1 with key k1 using symmetric encryption, creating edata1.
        // Decrypt edata1 with key k2 using symmetric decryption, creating data2.
        // data2 should equal data1.

        public static byte[] EncryptData(string pwd1, byte[] salt1, string data1, ref Aes encAlg, int myIterations)
        {
            Rfc2898DeriveBytes k1 = new Rfc2898DeriveBytes(pwd1, salt1, myIterations);
            encAlg.Key = k1.GetBytes(16);

            // Encrypt the data.
            MemoryStream encryptionStream = new MemoryStream();
            CryptoStream encrypt = new CryptoStream(encryptionStream, encAlg.CreateEncryptor(), CryptoStreamMode.Write);
            byte[] utfD1 = new System.Text.UTF8Encoding(false).GetBytes(data1);

            encrypt.Write(utfD1, 0, utfD1.Length);
            encrypt.FlushFinalBlock();
            encrypt.Close();
            byte[] edata1 = encryptionStream.ToArray();
            k1.Reset();

            return edata1;
        }

        public static string DecryptData(Aes encAlg, byte[] edata1, string pwd1, byte[] salt1)
        {
            Rfc2898DeriveBytes k2 = new Rfc2898DeriveBytes(pwd1, salt1);

            // Try to decrypt, thus showing it can be round-tripped.
            Aes decAlg = Aes.Create();
            decAlg.Key = k2.GetBytes(16);
            decAlg.IV = encAlg.IV;
            MemoryStream decryptionStreamBacking = new MemoryStream();
            CryptoStream decrypt = new CryptoStream(decryptionStreamBacking, decAlg.CreateDecryptor(), CryptoStreamMode.Write);
            decrypt.Write(edata1, 0, edata1.Length);
            decrypt.Flush();
            decrypt.Close();
            k2.Reset();
            string data2 = new UTF8Encoding(false).GetString(decryptionStreamBacking.ToArray());

            return data2;
        }

        public static void Main(string[] args)
        {
            string password = "Sample";

            //If no file name is specified, write usage text.
            if (password.Equals(""))
            {
                Console.WriteLine("Specify a string");
            }
            else
            {
                string pwd1 = password;

                // Create a byte array to hold the random value.
                byte[] salt1 = new byte[8];
                using (RNGCryptoServiceProvider rngCsp = new RNGCryptoServiceProvider())
                {
                    // Fill the array with a random value.
                    rngCsp.GetBytes(salt1);
                }

                //data1 can be a string or contents of a file.
                string data1 = "Some test data";

                //The default iteration count is 1000 so the two methods use the same iteration count.
                int myIterations = 1000;

                try
                {
                    Aes encAlg = Aes.Create();

                    byte[] edata1 = EncryptData(pwd1, salt1, data1, ref encAlg, myIterations);

                    string data2 = DecryptData(encAlg, edata1, pwd1, salt1);

                    if (!data1.Equals(data2))
                    {
                        Console.WriteLine("Error: The two values are not equal.");
                    }
                    else
                    {
                        Console.WriteLine("The two values are equal.");
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine("Error: {0}", e);
                }
            }
        }
    }
}
