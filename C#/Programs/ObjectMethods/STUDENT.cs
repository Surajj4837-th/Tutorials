using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ObjectMethods
{
    internal class STUDENT
    {
        public string name;
        public string major;
        public double gpa;
        public STUDENT(string aname, string amajor, double agpa) 
        {
            name = aname;
            major = amajor;
            gpa = agpa;
        }

        public bool HasHonours()
        {
            if(gpa >= 3.5)
            {
                return true;
            }
            return false;
        }
    }
}
