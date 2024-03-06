namespace Constructor
{
    internal class Program
    {
        static void Main(string[] args)
        {
            BOOK book1 = new BOOK("Maths", "RD Sharma", 1040);

            Console.WriteLine(book1.title);
            Console.WriteLine(book1.author);
            Console.WriteLine(book1.pages);

            BOOK book2 = new BOOK("Science", "NCERT", 100);

            Console.WriteLine(book2.title);
            Console.WriteLine(book2.author);
            Console.WriteLine(book2.pages);

            BOOK book3 = new BOOK();
        }
    }
}
