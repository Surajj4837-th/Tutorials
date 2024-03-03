namespace Numbers
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(1 + 2);
            Console.WriteLine(1 / 2);
            Console.WriteLine(1 / 2.0);     // answer in decimal
            Console.WriteLine(1 * 2);
            Console.WriteLine(1 % 2);     //remainder

            //Short hand notations
            int num = 3;
            Console.WriteLine(num++);
            Console.WriteLine(++num);

            // Math methods
            Console.WriteLine(Math.Abs(-40));
            Console.WriteLine(Math.Pow(3, 2));
            
        }
    }
}
// Explore math methods for more funcitons.