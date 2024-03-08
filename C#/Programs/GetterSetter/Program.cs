namespace GetterSetter
{
    internal class Program
    {
        static void Main(string[] args)
        {
            MOVIE avengers = new MOVIE("The Avengers", "Joss", "Dog");
            MOVIE shrek = new MOVIE("Shrek", "Adam", "PG");

            shrek.Rating = "Cat";

            Console.WriteLine(avengers.Rating);
            Console.WriteLine(shrek.Rating);
        }
    }
}

/*
 * 1. Set and get are C# provided functions for each class attributes.
 * 
 * 2. Set and get are declared inside a block in class.
 * 
 * 3. It is better to call set() in constructor for checking valid input.
 */
