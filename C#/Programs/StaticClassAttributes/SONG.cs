using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StaticClassAttributes
{
    internal class SONG
    {
        public string title;
        public string artist;
        public int duration;
        public static int songCount = 0;

        public SONG(string atitle, string aartist, int aduration)
        {
            title = atitle;
            artist = aartist;
            duration = aduration;
            songCount++;
        }
    }
}
