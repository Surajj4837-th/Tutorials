// Enum
#include <stdio.h>

enum day {
   Sunday = 1,
   Monday,
   Tuesday,
   Wednesday,
   Thursday,
   Friday,
   Saturday
};

enum denominations{
   Paisa,
   Rupee
};

int main()
{
   //**************************************************************************//
      
   //**************************************************************************//
    
}

/*************************************OUTPUT***************************************

***********************************************************************************/

/************************************Summary****************************************
1. Enum is a named integer constant.

2. It helps is code readability and maintainability.

3. The value assigned to 1st enum member is 0 by default. Next value is always previous + 1.

4. Enum vs MACRO
   - MACRO is a preprocessor directive that is replaced with the value before compile time.
   - The type of enum in C is an integer, but the type of macro can be of any type.
   - In Enum, if we do not assign the values to the enum names, then the compiler will 
      automatically assign the default value to the enum names. But, in the case of 
      macro, the values need to be explicitly assigned.
   - The enum type follows the scope rules while macro does not follow the scope rules.
   - In terms of readability, enumerations make better constants than macros, because 
      related values are grouped together.
************************************************************************************/
