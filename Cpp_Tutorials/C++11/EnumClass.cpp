//EnumClass.cpp
//Demonstration of enum class in C++11

#include <iostream>

using std::cout;
using std::endl;

void main()
{
    // Defining enum1 Gender
    enum Gender {
        Male,
        Female
    };

    // Defining enum2 Gender2 with same values
    // This will throw compilation error
    /*enum Gender2 {
        Male,
        Female
    };*/


    //No variable can have a name which is already in some enumeration:
    //int Male = 90;    //ERROR


    //Enums are not type-safe
    enum Color {
        Red,
        Green
    };

    Gender gender = Male;
    Color color = Red;

    // Upon comparing gender and color it will return true as both have value 0
    // which should not be the case actually
    if (gender == color)
        cout << "Equal";


    //To solve above issues class enum is introduced
    enum class Gender3 {
        Male,
        Female
    };

    enum class Color2 {
        Red,
        Green
    };

    //enum class variables can be declared
    int Green = 90;

    // Instantiating the Enum Class
    Color2 x = Color2::Green;

    //Comparison now is completely type-safe, following comparison throws compilation error.
    /*if (x == Color::Red)
        out << "Equal";*/

    enum class People {
        Good,
        Bad
    };

    People p = People::Good;

    /*if (x == p)
        cout << "Equal"; */

    

}
/************************************Summary*****************************************
1. Enum is a collection of named integer constant means it’s each element is assigned 
   by integer value.

2. Two enumerations cannot share the same names.

3. No variable can have a name which is already in some enumeration.

4. Enums are not type-safe. Conventional enums implicitly convert to int, causing logical 
   errors. Comparing two different enums is possible.

5. Class enum doesn’t allow implicit conversion to int, and also doesn’t compare 
   enumerators from different enumerations. It is both strongly typed and strongly scoped.

6. enum type can be specified while declaration:
   enum name : type { enumerator = constexpr , enumerator = constexpr , ... }	
************************************************************************************/