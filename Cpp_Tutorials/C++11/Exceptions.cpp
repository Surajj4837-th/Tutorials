// Exceptions
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;


//A function which throws an exception
double mySqrt(double x)
{
    // If the user entered a negative number, this is an error condition
    if (x < 0.0)
        throw "Can not take sqrt of negative number"; // throw exception of type const char*

    return std::sqrt(x);
}


int main()
{
    try
    {
        // Statements that may throw exceptions you want to handle go here
        
        throw -1; // here's a trivial example
    }
    catch (int x)
    {
        // Any exceptions of type int thrown within the above try block get sent here
        std::cerr << "We caught an int exception with value: " << x << '\n';
    }
    catch (double) // no variable name since we don't use the exception itself in the catch block below
    {
        // Any exceptions of type double thrown within the above try block get sent here
        std::cerr << "We caught an exception of type double" << '\n';
    }
    catch (const std::string&) // catch classes by const reference
    {
        // Any exceptions of type std::string thrown within the above try block get sent here
        std::cerr << "We caught an exception of type std::string" << '\n';
    }


    std::cout << "Continuing on ....\n";


    try // Look for exceptions that occur within try block and route to attached catch block(s)
    {
        int x = -1;

        // If the user entered a negative number, this is an error condition
        if (x < 0.0)
            throw "Can not take sqrt of negative number"; // throw exception of type const char*

        // Otherwise, print the answer
        std::cout << "The sqrt of " << x << " is " << std::sqrt(x) << '\n';
    }
    catch (const char* exception) // catch exceptions of type const char*
    {
        std::cerr << "Error: " << exception << '\n';
    }


    //----------------------------------Exception from a called function-----------------------------------
    try // Look for exceptions that occur within try block and route to attached catch block(s)
    {
        int x = -1;
        double d = mySqrt(x);
        std::cout << "The sqrt of " << x << " is " << d << '\n';
    }
    catch (const char* exception) // catch exceptions of type const char*
    {
        std::cerr << "Error: " << exception << std::endl;
    }


    //----------------------------------catch-all handler-----------------------------------
    
    try
	{
		throw 5; // throw an int exception
	}
	catch (double x)
	{
		std::cout << "We caught an exception of type double: " << x << '\n';
	}
	catch (...) // catch-all handler
	{
		std::cout << "We caught an exception of an undetermined type\n";
	}

    //------------------------------------------------------------------------

    return 0;
}
/************************************Summary*****************************************
1. When writing reusable code, error handling is a necessity.

2. Exceptions in C++ are implemented using three keywords that work in conjunction with 
   each other: throw, try, and catch.

3. A throw statement is used to signal that an exception or error case has occurred.
   Commonly called raising an exception.

4. The try keyword is used to define a block of statements called a try block. The try 
   block acts as an observer, looking for any exceptions that are thrown by any of the 
   statements within the try block.

5. Handling exceptions is the job of the catch block(s). The catch keyword is used to 
   define a block of code (called a catch block) that handles exceptions for a single 
   data type.

6. A try block must have at least one catch block immediately following it and may 
   have multiple catch blocks listed in sequence.

7. No type conversion is done for exceptions (so an int exception will not be converted 
   to match a catch block with a double parameter).

8. Throw statement do not have to be placed inside try block directly. It can be inside 
   a function in a try block the caller try block will detect the exception when thrown 
   by the called function.

9. Catch-all handler: a mechanism to catch all types of exceptions. 
************************************************************************************/