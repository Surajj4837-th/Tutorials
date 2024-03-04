namespace ForLoop
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int i = 0;
            while(i <= 5)
            {
                Console.WriteLine("Hello, World!");
                i++;
            }

            for(int j = 0; j < 5 ; j++)
            {
                Console.WriteLine("Hello, World!");
            }
        }
    }
}
