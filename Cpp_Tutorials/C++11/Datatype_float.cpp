//Datatype_float.cpp
// Data types: unsigned and float in C++11

#include <iostream>
#include <cstdint>  //For fixed size integers
#include <iomanip>  //For steprecision()


using std::cout;
using std::endl;

int main()
{

    //----------------------------------fixed size ints----------------------------------

    std::int16_t int32_a;
    std::int64_t int64_a;
    
    //----------------------------------fast and least ints------------------------------

    std::int_least8_t least8_a;
    std::int_least16_t least16_a;
    std::int_least32_t least32_a;

    std::int_fast8_t fast8_a;
    std::int_fast16_t fast16_a;
    std::int_fast32_t fast32_a;

    std::cout << "least 8:  " << sizeof(least8_a) * 8 << " bits\n";
	std::cout << "least 16: " << sizeof(least16_a) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(least32_a) * 8 << " bits\n";
	std::cout << '\n';
	std::cout << "fast 8:  " << sizeof(fast8_a) * 8 << " bits\n";
	std::cout << "fast 16: " << sizeof(fast16_a) * 8 << " bits\n";
	std::cout << "fast 32: " << sizeof(fast32_a) * 8 << " bits\n";


    //Issues
    std::uint_fast16_t sometype { 0 };
    --sometype; // This code will produce different results depending on 
                // whether std::uint_fast16_t is 16, 32, or 64 bits.

    //----------------------------------Unsigned numbers---------------------------------

    unsigned int a = 20;
    int b = 30;

    unsigned int c = a - b;  //LOGICAL ERROR!!! : c cannot store negative numbers.
    cout << c << endl;

    cout << a-b << endl;    //LOGICAL ERROR!!! : b is converted to unsigned integer.
    

    //----------------------------------size_t----------------------------------

    std::cout << sizeof(int) << '\n';
    //Returns 4 but what is the data type of the returnd value: int or short.
    //The size or length returns of anything is of type: size_t.



    //----------------------------------decimal----------------------------------
    int x{5}; // 5 means integer
    double y{5.0}; // 5.0 is a floating point literal 
    // (no suffix 'f' means double type by default)

    float z{5.0f}; // 5.0 is a floating point literal, 'f' suffix means float type
    double electronCharge { 1.6e-19 };  //scientific notation
    
    
    std::cout << 5.0 << '\n';           //does not print decimal and trailing values.
	std::cout << 6.7f << '\n';          //prints 6.7
	std::cout << 98765493.21 << '\n';    //prints scientific notation
    
    //When outputting floating point numbers, std::cout has a default precision of 6.
    //This can be overridden by using std::setprecision()
    std::cout << std::setprecision(16);                    // show 16 digits of precision
    std::cout << 3.33333333333333333333333333333333333333f <<'\n'; // f suffix means float



    //Rounding error
    float f { 123456789.0f };           // f has 10 significant digits
    std::cout << std::setprecision(9);  // to show 9 digits in f
    std::cout << f << '\n';             //prints 123456792, losing some precision
    //Favor double over float unless space is at a premium, as the lack of precision 
    //in a float will often lead to inaccuracies.

    //Rounding errors may make a number either slightly smaller or slightly larger, 
    //depending on where the truncation happens.
    double d{0.1};
    std::cout << d << '\n'; // prints 0.1
    std::cout << std::setprecision(17);
    std::cout << d << '\n'; //prints 0.10000000000000001

    //Comparison issues
    std::cout << std::setprecision(17);
    double d1{ 1.0 };
    double d2{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 }; 
    std::cout << d2 << '\n'; // should print 1.0 but prints 0.99999999999999989

    if (d1==d2)     //prints unequal
        cout << "Equal" << endl;
    else
        cout << "Unequal" << endl;  



    //----------------------------------nan and inf----------------------------------

    double zero {0.0};
    double posinf { 5.0 / zero }; // positive infinity
    std::cout << posinf << '\n';

    double neginf { -5.0 / zero }; // negative infinity
    std::cout << neginf << '\n';

    double nan { zero / zero }; // not a number (mathematically invalid)
    std::cout << nan << '\n';

    //------------------------------------------------------------------------
}
/************************************Summary*****************************************
1. Storing values beyond the storage range causes wrap around in both directions.

2. Unsigned integers are avoided because subtraction of 2 unsigned numbers can lead to 
   negative answer which cannot be saved by the datatype.

3. Another wraparound issues with unsigned integer happens when the value is repeatedly 
   decremented to go beyond 0.

4. if one signed and one unsigned integer are used, the signed integer will be converted 
   to unsigned.

5. To avoid wrap around errors use correct data types or type casting operators. Best 
   practice:
        - Favor signed numbers over unsigned numbers for holding quantities (even 
            quantities that should be non-negative) and mathematical operations. 
        - Avoid mixing signed and unsigned numbers.

6. Unsigned numbers are required when dealing with bit manipulation and in some specific 
   algorithms where wrap around behavior is required.

7. Why isn’t the size of the integer variables fixed?
   The short answer is that this goes back to C, when computers were slow and performance 
   was of the utmost concern. C opted to intentionally leave the size of an integer open 
   so that the compiler implementers could pick a size for int that performs best on the 
   target computer architecture.

8. Fixed width integers were introduced to guarantee same size integers on any 
   architecture.
   
9. But fixed width integers can be slow on some architectures which are designed to 
   work fast on wider types. To solve this least and fast integers were introduced which 
   provided least and fastest integer types based on width on any architecture.

10. Not many programmers use this as the program may cause different behavior on different
    architectures. It is recommended to use correct data types instead of fast and least.

11. Floating point representation almost always follows IEEE 754 binary format. There 
    are three different floating point data types: float, double, and long double of 4, 
    8 and 16 bytes respectively.

12. An f suffix is used to denote a literal of type float.

13. The precision of a floating point number defines how many significant digits it 
    can represent without information loss.

14. When outputting floating point numbers, std::cout has a default precision of 6. 
    We can override the default precision that std::cout shows by using an output 
    manipulator function named std::setprecision().

15. Favor double over float unless space is at a premium, as the lack of precision in 
    a float will often lead to inaccuracies.

16. Comparison should be avoided in decimal numbers due to rounding issues.

17. Special cases of float:
    - Inf: represents infinity. Inf can be positive or negative.
    - NaN: Not a Number.
    Avoid division by 0 altogether, even if your compiler supports it.
************************************************************************************/