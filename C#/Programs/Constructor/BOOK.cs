using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Constructor
{
    internal class BOOK
    {
        public string title;
        public string author;
        public int pages;

        public BOOK(string atitle, string aauthor, int apages)
        {
            title = atitle;
            author = aauthor;
            pages = apages;
        }

        public BOOK()
        {

        }
    }
}
