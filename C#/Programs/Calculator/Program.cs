using System.Transactions;

namespace Calculator
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int num = Convert.ToInt32("45");    //convert string to integer

            Console.WriteLine("Enter a number: ");
            double num1 = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine("Enter another number: ");
            double num2 = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine(num1 + num2);

        }
    }
}
/*
 * 1. If there is an input of decimal and the convert menthod selected is of integer then
 *    there is an runtime error. So to work with decimal numbers we use double and convert the
 *    input to the same.
 */