using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace LicenseKeyGenerationAndActivation
{
    internal class ActivationStatus
    {
        private const string StatusFilePath = "activation_status.txt";

        public static void SaveActivationStatus(bool isActivated)
        {
            File.WriteAllText(StatusFilePath, isActivated ? "Activated" : "Not Activated");
        }

        public static bool IsActivated()
        {
            if (!File.Exists(StatusFilePath))
                return false;

            string status = File.ReadAllText(StatusFilePath);
            return status.Trim() == "Activated";
        }
    }
}
