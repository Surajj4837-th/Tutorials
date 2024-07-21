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

        public static byte[] EncryptData(string data1)
        {
            Aes encAlg = Aes.Create();
            encAlg.Key = [134, 23, 44, 252, 254, 197, 75, 88, 192, 144, 49, 24, 3, 137, 183, 37];
            encAlg.IV = [27, 233, 168, 94, 38, 210, 16, 203, 151, 134, 1, 161, 42, 20, 170, 198];

            // Encrypt the data.
            MemoryStream encryptionStream = new MemoryStream();
            CryptoStream encrypt = new CryptoStream(encryptionStream, encAlg.CreateEncryptor(), CryptoStreamMode.Write);
            byte[] utfD1 = new System.Text.UTF8Encoding(false).GetBytes(data1);

            encrypt.Write(utfD1, 0, utfD1.Length);
            encrypt.FlushFinalBlock();
            encrypt.Close();

            byte[] edata1 = encryptionStream.ToArray();

            return edata1;
        }

        public static string DecryptData(byte[] edata1)
        {
            // Try to decrypt, thus showing it can be round-tripped.
            Aes decAlg = Aes.Create();
            decAlg.Key = [134, 23, 44, 252, 254, 197, 75, 88, 192, 144, 49, 24, 3, 137, 183, 37];
            decAlg.IV = [27, 233, 168, 94, 38, 210, 16, 203, 151, 134, 1, 161, 42, 20, 170, 198];

            MemoryStream decryptionStreamBacking = new MemoryStream();
            CryptoStream decrypt = new CryptoStream(decryptionStreamBacking, decAlg.CreateDecryptor(), CryptoStreamMode.Write);
            decrypt.Write(edata1, 0, edata1.Length);
            decrypt.Flush();
            decrypt.Close();

            string data2 = new UTF8Encoding(false).GetString(decryptionStreamBacking.ToArray());

            return data2;
        }

        public static void Main(string[] args)
        {
            //data1 can be a string or contents of a file.
            string data1 = "Sample string.";

            try
            {
                byte[] edata1 = EncryptData(data1);

                string data2 = DecryptData(edata1);

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
