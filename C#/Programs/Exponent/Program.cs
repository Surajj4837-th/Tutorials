namespace Exponent
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(GetPow(3,3));
        }

        static int GetPow(int basenum, int pownum)
        {
            int result = 1;

            for (int i = 0; i < pownum; i++)
            {
                result *= basenum;
            }

            return result;
        }
    }
}
