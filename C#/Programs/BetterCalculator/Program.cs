namespace BetterCalculator
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter a number: ");
            double num1 = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine("Enter a number: ");
            double num2 = Convert.ToDouble(Console.ReadLine());

            char oper;
            Console.WriteLine("Enter an operator (+,-,*,/): ");
            oper = Convert.ToChar(Console.Read());

            if(oper == '+')
            {
                Console.WriteLine(num1 + num2);
            }
            else if (oper == '-')
            {
                Console.WriteLine(num1 - num2);
            }
            else if (oper == '/')
            {
                Console.WriteLine(num1 / num2);
            }
            else if (oper == '*')
            {
                Console.WriteLine(num1 * num2);
            }
            else 
            {
                Console.WriteLine("Invalid operator");
            }
        }
    }
}
