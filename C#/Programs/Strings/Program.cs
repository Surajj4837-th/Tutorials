namespace Strings
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello,\nWorld!");
            Console.WriteLine("Hello,\"World\"!");    //print "

            string str1 = "first";
            Console.WriteLine(str1);

            //Conctenate
            string str2 = str1 + " program";
            Console.WriteLine(str2);
            Console.WriteLine(str2.Length); // Print length of string 

            //Case change
            string str3 = str2.ToUpper();
            Console.WriteLine(str3);

            string str4 = str2.ToLower();
            Console.WriteLine(str4);

            //contains
            Console.WriteLine(str4.Contains("program"));
            Console.WriteLine(str4.Contains("Program"));

            // Access elements of string, index starts from 0
            Console.WriteLine(str4[0]);

            //Find index of char or string value
            Console.WriteLine(str4.IndexOf("program"));
            Console.WriteLine(str4.IndexOf("Program"));     //-1, item is not in the string
            Console.WriteLine(str4.Substring(6));           // Print substring after a location
            Console.WriteLine(str4.Substring(6,3));         // Print 3 substrings from 6

            //Google for c# string methods and practice.

        }
    }
}
/*
 String methods:
C# String LastIndexOf()
Returns index of the last occurrence of substring

C# String ToUpper()
Converts characters in the string to uppercase

C# String Compare()
Compares two strings in the alphabetical order

C# String Concat()
Concatenates (joins) strings

C# String Contains()
Checks whether the string contains a substring

C# String EndsWith()
Checks if the string ends with the given string

C# String Equals()
Checks whether two strings have the same value

C# String Format()
Returns a formatted string

C# String IndexOf()
Returns the index of the string

C# String Join()
Joins the given strings using a separator

C# String PadLeft()
Returns a new string with left padding

C# String PadRight()
Returns new string with right padding

C# String Remove()
Removes a specified number of characters

C# String Replace()
Replace all matching characters/text in the string

C# String Split()
Returns substrings of a string

C# String StartsWith()
Checks if string starts with the specified string

C# String Substring()
Returns a substring from the given string

C# String ToCharArray()
Copies characters in string to a character array

C# String ToLower()
Converts all characters in the string to lowercase

C# String Trim()
Removes any leading and trailing whitespaces
 */