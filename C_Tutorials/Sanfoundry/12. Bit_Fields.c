// Bit field
#include <stdio.h>

struct bits{
   unsigned char Ch1 : 1,
                 unused1:1,
                 Ch2 : 2,
                 unused2:1,
                 Ch3 : 3;
};    //Structure with 3 bit fields with gap in between (unused bits).


struct bits2{
   unsigned int f1:1;
   unsigned int f2:1;
   int f3;
};


struct bits3{
   unsigned int f1:1;
   unsigned int f2:2;
   unsigned int f3:3;
   int f4:3;
};


struct bits4{
   char f1:1;
   char f2:2;
   char f3:3;
};

struct bits5{
   int f1:3;
   unsigned int f2:1;
};

int main()
{
   //**************************************************************************//
   struct bits B1;
   B1.Ch1 = 1;
   B1.Ch2 = 2;
   B1.Ch3 = 3;

   printf("%d, %d, %d\n", B1.Ch1, B1.Ch2, B1.Ch3);
   printf("size of B1: %d bytes\n", sizeof(B1));

   //**************************************************************************//
   struct bits2 B2;

   printf("size of B2: %d bytes\n", sizeof(B2));
   //B2.f1 and B2.f2 are combined in a memory structure of unsigned int

   //**************************************************************************//
   struct bits3 B3;

   printf("size of B3: %d bytes\n", sizeof(B3));
   //All members are combined in a memory structure of unsigned int

   //**************************************************************************//

   struct bits4 B4;

   B4.f1 = 1;
   B4.f2 = 2;
   B4.f3 = 5;
   printf("B4 members: %d, %d, %d\n", B4.f1, B4.f2, B4.f3);
   // Printed values: -1, -2, -3
   // The printed output will not be 1,2&5 as the data type used is signed and 
   // there will be 1 bit considered for the sign in the allocated memory.
   //**************************************************************************//

   struct bits5 B5 = {5,1};

   printf("B5 members: %d, %d\n", B5.f1, B5.f2);
   // Printed values: -3, 1. Due to signed datatype used f1 has changed.
   //**************************************************************************//
    
}

/*************************************OUTPUT***************************************
1, 2, 3
size of B1: 1 bytes
size of B2: 8 bytes
size of B3: 4 bytes
B4 members: -1, -2, -3
B5 members: -3, 1
***********************************************************************************/

/************************************Summary****************************************
1. The width of bit field is measured in bits.

2. These are useful for packaging data in structure where there are memory restrictions.

3. Generally bit fields are used to denote some status so negative value is not used 
   hence the bit fields are generally used with unsigned data type.

4. Take care while using the signed data types as the insigned values are not read as 
   it is. Examples are given above.

5. Applications:
   - Hardware representations
   - Protocols, e.g. TCP protocol.
************************************************************************************/
