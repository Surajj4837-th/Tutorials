namespace Arrays
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] arr1 = { 1, 2, 3 };       // Array declaration

            Console.WriteLine(arr1[0]);     // Access elements

            Console.WriteLine(arr1.Length);

            string[] arr2 = new string[4];  // Declaration without initialization
                                            // declare the size of array in []
            arr2[0] = "Suraj";
            arr2[1] = "Ashish";
            Console.WriteLine(arr2[0]);     // Access elements
        }
    }
}
