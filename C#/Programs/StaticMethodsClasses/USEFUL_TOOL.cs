using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StaticMethodsClasses
{
    internal /*static*/ class USEFUL_TOOL       //Add static keyword to make class as static
    {
        public static void SayHi(string name)
        {
            Console.WriteLine("Hi " + name);
        }
    }
}
