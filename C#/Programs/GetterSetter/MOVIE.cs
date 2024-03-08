using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GetterSetter
{
    internal class MOVIE
    {
        private string name;
        private string director;
        private string rating;   // P, PG, PG-13, R, NR

        public MOVIE(string aname, string adirector, string arating)
        {
            name = aname;
            director = adirector;
            Rating= arating;        //Use setter function instead of direct assignment
        }

        public string Rating
        {
            get
            {
                return rating;

            }
            set
            {
                if(value == "G" || value == "PG" || value == "PG-13" || value == "R" || value == "NR")
                {
                    rating = value;
                }
                else
                {
                    rating = "NR";
                }
            }
        }
    }
}
