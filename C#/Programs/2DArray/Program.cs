namespace _2DArray
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[,] arr2d =      //Array initialization when values are known
            {
                {1,2},
                {3,4},
                {5,6}
            };

            int[,] arr = new int[2, 3]; // array initialization with values unknown
                                        // but size known, 2 rows, 3 columns

            Console.WriteLine(arr2d[0,1]);
        }
    }
}
