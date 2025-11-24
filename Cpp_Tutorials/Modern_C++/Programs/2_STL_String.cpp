// Modern_C++/Programs/2_STL_String.cpp
// Demonstration of string in C++17

#include <iostream>
#include <iomanip>
#include <string>   // important!

using namespace std;    // or use std:: 

int main() 
{    
    string s0;              // No garbage values.
    string s1 {"Apple"};    // Constructor style initialization
    string s2 {"Banana"};
    string s3 {"Kiwi"};
    string s4 {"apple"};
    string s5 {s1};         // Apple
    string s6 {s1, 0, 3};   // App
    string s7 (10, 'X');    // XXXXXXXXXX
    
    cout << s0 << endl;                  // No garbage
    cout << s0.length() << endl;     // empty string

    // Initialization
    cout << "\nInitialization" << "\n------------------------------------------" << endl;
    cout << "s0 is initialized to: " << s0 << endl;
    cout << "s1 is initialized to: " << s1 << endl;
    cout << "s2 is initialized to: " << s2 << endl;
    cout << "s3 is initialized to: " << s3 << endl;
    cout << "s4 is initialized to: " << s4 << endl;
    cout << "s5 is initialized to: " << s5 << endl;
    cout << "s6 is initialized to: " << s6 << endl;
    cout << "s7 is initialized to: " << s7 << endl;

    // Comparison using operators
    cout << "\nComparison" << "\n------------------------------------------" << endl;
    
    cout << boolalpha;          
    // The statement cout << boolalpha; tells the output stream to print 
    // boolean values as true or false instead of 1 or 0.

    cout << s1 << " == " << s5 << ": " << (s1 == s5) << endl; // True    Apple == Apple
    cout << s1 << " == " << s2 << ": " << (s1 == s2) << endl; // False   Apple != Banana
    cout << s1 << " != " << s2 << ": " << (s1 != s2) << endl; // True    Apple != Banana
    cout << s1 << " < " << s2 << ": " << (s1 < s2) << endl;
    ;                                                       // True         Apple < Banana
    cout << s2 << " > " << s1 << ": " << (s2 > s1) << endl; // True         Banana > Apple
    cout << s4 << " < " << s5 << ": " << (s4 < s5) << endl; // False        apple >Apple
    cout << s1 << " == " << "Apple" << ": " << (s1 == "Apple") << endl;
    ; // True Apple == Apple

    // Assignment
    cout << "\nAssignment" << "\n------------------------------------------" << endl;

    s1 = "Watermelon";
    cout << "s1 is now: " << s1 << endl; // Watermelon
    s2 = s1;
    cout << "s2 is now: " << s2 << endl; // Watermelon

    s3 = "Frank";
    cout << "s3 is now: " << s3 << endl; // Frank

    // Accessing characters [] and at() method
    s3[0] = 'C';                                             // Crank
    cout << "s3 change first letter to 'C': " << s3 << endl; // Crank
    s3.at(0) = 'P';
    // s3.at(110) = 'P';       //Bound checking is done, run time error
    cout << "s3 change first letter to 'P': " << s3 << endl; // Prank

    // Concatenation

    s3 = "Watermelon";
    cout << "\nConcatenation" << "\n------------------------------------------" << endl;

    s3 = s5 + " and " + s2 + " juice";   // Apple and Banana juice
    cout << "s3 is now: " << s3 << endl; // Apple and Banana Juice

    // Compiler error
    // s3 = "nice " + " cold " + s5 + "juice"; 

    //  for loop
    cout << "\nLooping" << "\n------------------------------------------" << endl;

    s1 = "Apple";
    for (size_t i{0}; i < s1.length(); ++i)
        cout << s1.at(i); //  or s1[i]    Apple
    cout << endl;

    // Range-based for loop
    for (char c : s1)
        cout << c; // Apple
    cout << endl;

    // Range-based for loop, displays the integer values representing the charachters
    for (int c : s1)
        cout << c << ", "; // Apple
    cout << endl;

    // string comparison

    cout << (s1 == s2) << endl;
    cout << (s1 != s2) << endl;
    cout << (s1 == s4) << endl;
    cout << (s1 < s4) << endl;
    cout << (s1 == "Apple") << endl;

    // The objects are compared charachter by charachter lexically
    string s9{"aA"};
    string s11{"Aa"};
    cout << (s9 > s11) << endl;

    // Substring
    cout << "\nSubstring" << "\n------------------------------------------" << endl;
    s1 = "This is a test";

    cout << s1.substr(0, 4) << endl;  // This
    cout << s1.substr(5, 2) << endl;  // is
    cout << s1.substr(10, 4) << endl; // test    

    // Erase deletes mentioned charachters, clear deletes the complete string
    cout << "\nErase" << "\n------------------------------------------" << endl;

    s1 = "This is a test";
    s1.erase(0, 5);                      // Erase This from s1 results in "is a test"
    cout << "s1 is now: " << s1 << endl; // is a test

    s1.clear();
    cout << "After clear() s1 is now: " << s1 << endl; // is a test

    // getline used to take complete input including spaces, 
    // cin ignores text after first space
    cout << "\ngetline" << "\n------------------------------------------" << endl;

    string full_name{};

    cout << "Enter your full name: ";
    getline(cin, full_name);

    cout << "Your full name is: " << full_name << endl;

    // Find
    cout << "\nfind" << "\n------------------------------------------" << endl;

    s1 = "The secret word is Boo";
    string word{};

    cout << "Enter the word to find: ";
    cin >> word;

    size_t position = s1.find(word); //Returns string::npos if the charachter is not found

    if (position != string::npos)
        cout << "Found '" << word << "' at position: " << position << endl;
    else
        cout << "Sorry, '" << word << "' not found" << endl;

    cout << endl;
    return 0;
}

/*****************************************************************************************
1. C style strings are fix in size, C++ strings (std::string) are dynamic in size.

2. These can work with string extraction and insertion operators.

3. Familiar operators can be used (+, = , < , <=, >, >=, +=, ==, !=, [], …)

4. It can be easily converted to C-style Strings if needed for some use cases.

5. C++ strings are always initialized, no garbage values are there in empty declaration.

6. In the C++ string, assignment "=" operator can be used to assign a string to another 
   variable, in case of C style string, we will need strcpy() instead.

7. The strcat() in C is used to concatenate strings, in C++ this is replaced by 
   '+' operator.

8. Two C style strings cannot be concatenated, eg: string str = "hello" + "world";
   However there can be a combination of strings and variable, 
   eg: string str = "hello" + str1 + "world";\

9. at() method to access the string values use bound check.

10. Comparing string operators: ==, !=, >, >=, <, <=.
    The objects are compared charachter by charachter lexically.
    Lexicographical comparison, the decision is made as soon as a difference is found 
    between corresponding characters i.e. whole string is not compared.
    A < Z, A < a since capital letters come before lower case in ASCII table.
    These cannot be used in case the comparison is between C style strings, at least 
    1 has to be C++ style string.

11. Find charachters in string using find() and rfind().

12. Remove charachters using erase() and clear().

13. length() tells the number of charachters in a string.

14. getline() used to take complete input including spaces, cin ignores text after first 
    space. There is a 3rd argument in getline which is a limiter, getline will read till 
    the limiter in the provided text.
*****************************************************************************************/