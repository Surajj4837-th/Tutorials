using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance
{
    internal class ItalianChef: Chef        //Inherit funcionality from chef class
    {
        public void MakePasta()
        {
            Console.WriteLine("The chef makes pasta.");
        }

        public override void MakeSpecialDish()       //Override inherited function
        {
            Console.WriteLine("The chef makes special Italian dish.");
        }
    }
}
