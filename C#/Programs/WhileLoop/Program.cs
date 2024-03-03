namespace WhileLoop
{
    internal class Program
    {
        static void Main(string[] args)
        {

            int idx = 0;

            while(idx <= 5)         // first check this condition and then enter in the loop
            {
                Console.WriteLine("Hello, World! " + idx++);        //increment index
            }

            do          //first execute the loop and then check the condition
            {
                Console.WriteLine("Hello, World! " + idx++);

            } while (idx <= 5);
        }
    }
}
