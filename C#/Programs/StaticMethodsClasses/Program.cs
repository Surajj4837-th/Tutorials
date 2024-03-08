namespace StaticMethodsClasses
{
    internal class Program
    {
        static void Main(string[] args)
        {

            USEFUL_TOOL.SayHi("Suraj");

            USEFUL_TOOL tool = new USEFUL_TOOL();

            //tool.SayHi("Suraj"); //error

            Console.WriteLine(Math.Sqrt(144));      //static class: Math

            //Math myMath = new Math();       //illegal

        }
    }
}
/*
 * 1. static method is the method that belongs to the class itself.
 * 
 * 2. Objects cannot call static methods.
 * 
 * 3. Similarly there are static classes. These can be used directly and objects cannot be created 
 *    from it. Example is Math class in C#, 
 *    
 * 4. Declaring a class as static will create a static class.
 */