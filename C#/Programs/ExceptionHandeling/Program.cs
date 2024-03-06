namespace ExceptionHandeling
{
    internal class Program
    {
        static void Main(string[] args)
        {
            try
            {
                Console.Write("Enter a number: ");
                int a = Convert.ToInt16(Console.ReadLine());
                Console.Write("Enter another number: ");
                int b = Convert.ToInt16(Console.ReadLine());
                Console.WriteLine(a / b);
            }
            catch (DivideByZeroException e)
            {
                Console.WriteLine(e.Message);
            }
            catch (FormatException e)
            {
                Console.WriteLine(e.Message);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            finally
            {
                Console.WriteLine("finally block");

            }
        }
    }
}
/*
 * 1. Any code that is expected to give an exception, we put that in try block.
 * 
 * 2. If there is any exception detectedin try block then instead of terminating, the program will
 *    execute catach block.
 *    
 * 3. We can specify the exception to catch in catch block and execute a specific task.
 * 
 * 4. finally block is used to execute a set of commands regardless of exceptions occurred or not.
 * 
 */