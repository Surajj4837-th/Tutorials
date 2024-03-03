namespace ifstatement
{
    internal class Program
    {
        static void Main(string[] args)
        {

            bool isMale = true;
            bool isTall = false;

            if (isMale && isTall)
            {
                Console.WriteLine("You are a tall male.");
            }
            else if (isMale && !isTall)
            {
                Console.WriteLine("You are a short male.");
            }
            else if (!isMale && isTall)
            {
                Console.WriteLine("You are a tall but nor a male.");
            }
            else
            {
                Console.WriteLine("You are neither tall not a male.");
            }

            if (isMale || isTall)
            {
                Console.WriteLine("You are a tall or male.");
            }
            else
            {
                Console.WriteLine("You are either not male and not tall.");
            }

            Console.WriteLine(getMax(10, 11));

        }

        static int getMax(int num1, int num2)
        {
            int result;

            if (num1 > num2)
            {
                result = num1;
            }
            else
            {
                result = num2;
            }

            return result;
        }
    }
}
