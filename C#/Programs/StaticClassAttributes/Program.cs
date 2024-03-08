namespace StaticClassAttributes
{
    internal class Program
    {
        static void Main(string[] args)
        {
            SONG holiday = new SONG("Holiday", "Green Day", 200);
            Console.WriteLine(SONG.songCount);
            SONG Kashmir = new SONG("Kashmir", "Led Zeppelin", 150);
            Console.WriteLine(SONG.songCount);

            //Console.WriteLine(Kashmir.songCount);     //error
        }
    }
}
/*
 * 1. Static attributes are special attributes which are shared by all objects of the class.
 * 
 * 2. static attributes can be accessed using class and not by using any class object.
 * 
 * 3. To access a static attribute using object we can use a method which returns the attribute.
 */