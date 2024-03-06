namespace Classes
{
    internal class Program
    {
        static void Main(string[] args)
        {
            BOOK  book1 = new BOOK();

            book1.title = "Maths";
            book1.author = "RD Sharma";
            book1.pages = 1040;

            Console.WriteLine(book1.title);
            Console.WriteLine(book1.author);
            Console.WriteLine(book1.pages);

            BOOK book2 = new BOOK();

            book2.title = "Science";
            book2.author = "NCERT";
            book2.pages = 100;

            Console.WriteLine(book2.title);
            Console.WriteLine(book2.author);
            Console.WriteLine(book2.pages);
        }
    }
}
