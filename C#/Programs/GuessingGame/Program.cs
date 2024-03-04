namespace GuessingGame
{
    internal class Program
    {
        static void Main(string[] args)
        {

            // Guess the secret word within 3 times.

            string secretWord = "CSharp";
            string guess = "";

            int count = 0;
            int guessLimit = 3;
            bool outOfGuesses = false;

            while(guess != secretWord && !outOfGuesses)
            {
                if (count < guessLimit)
                {
                    Console.WriteLine("Enter guess: ");
                    guess = Console.ReadLine();
                    count++;
                }
                else
                {
                    outOfGuesses = true;
                }
            }

            if(outOfGuesses)
            {
                Console.WriteLine("You lose!");
            }
            else
            {
                Console.WriteLine("You win!");
            }
        }
    }
}
