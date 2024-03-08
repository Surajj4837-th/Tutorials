using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance
{
    internal class Chef
    {
        public void MakeChicken()
        {
            Console.WriteLine("The chef makes chicken.");
        }
        public void MakeSalad()
        {
            Console.WriteLine("The chef makes salad.");
        }
        public virtual void MakeSpecialDish()       // virtual methods can be overridden in subclasses
        {
            Console.WriteLine("The chef makes special dish.");
        }
    }
}
