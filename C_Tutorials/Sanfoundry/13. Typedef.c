// Typedef
#include <stdio.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;

int main()
{
   //**************************************************************************//
   u8 R1;
   u16 R2;
   u32 R3;
   u64 R4;
   
   //**************************************************************************//
    
}

/*************************************OUTPUT***************************************

***********************************************************************************/

/************************************Summary****************************************
1. Typedef creates aliases for previously defined datatypes - no new datatype.

2. It is used as a good practice as it provides:
   - Readability
   - Portability

3. It is good practice to declare all typedefs in a separate header file.

4. size_t is a regularly typedef. All the inbuilt datatypes with "_t" in its end are 
   typedefs. FILE is a typedef.

5. Unsigned versions of datatype of datatype can be used for typedef: u8, u16, u32, etc.
   Similar typedefs can be declared for all groups of dats types.
************************************************************************************/
