//using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;
//using System.Threading.Tasks;
using System;
using System.Diagnostics;

namespace LicenseKeyGenerationAndActivation
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // Simulate user input and activation process
            Debug.WriteLine("Enter your user ID: ");
            string userId = Console.ReadLine();

            Console.Write("Enter your activation key: ");
            string UserActivationKey = Console.ReadLine();

            // Validate activation key
            if (ActivationValidator.ValidateActivationKey(UserActivationKey, userId))
            {
                ActivationStatus.SaveActivationStatus(true);
                Console.WriteLine("Activation successful!");
            }
            else
            {
                ActivationStatus.SaveActivationStatus(false);
                Console.WriteLine("Invalid activation key.");
            }

            // Check activation status
            if (ActivationStatus.IsActivated())
            {
                Console.WriteLine("Product is activated.");
            }
            else
            {
                Console.WriteLine("Product is not activated.");
            }
        }
    }
}
