using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LicenseKeyGenerationAndActivation
{
    internal class ActivationValidator
    {
        public static bool ValidateActivationKey(string activationKey, string userId)
        {
            // This is a stub function - in a real scenario, you would check the key against a server or database.
            string expectedKey = Activationmanager.GenerateActivationKey(userId);

            // Simple comparison, but in practice, you might use more sophisticated validation
            return activationKey == expectedKey;
        }
    }
}
