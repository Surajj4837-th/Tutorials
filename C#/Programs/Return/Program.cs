namespace Return
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Print("Suraj"));
            Console.WriteLine(Print("Ashish"));
        }

        static int Print(string name)
        {
            Console.WriteLine("Hello " + name + "!");

            return (name.Length);
        }
    }
}
