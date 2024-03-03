namespace UserInput
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello, World!");     // Print output and go to next line
            Console.Write("Hello");                 // Print output and remain on same line

            Console.Write("\nEnter your name: ");

            string name = Console.ReadLine();       // Get input from console

            Console.WriteLine("Hello " + name);

            Console.WriteLine("Enter your age: ");

            string age = Console.ReadLine();

            Console.WriteLine("Your age: " + age);
        }
    }
}
