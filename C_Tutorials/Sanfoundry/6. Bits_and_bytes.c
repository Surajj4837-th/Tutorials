//Bits & bytes
#include <stdio.h>

int main()
{
    //**************************************************************************//
    char c = 255;
    printf("for c = 255, value stored: %d\n", c);
    c = 128;
    printf("for c = 128, value stored: %d\n", c);
    c = -1;
    printf("for c = -1, value stored in hex: %x\n", c);     //printf converts char to int
    c = 256;
    printf("for c = 256, value stored: %d\n", c);
    
    //**************************************************************************//

    int i = 256;
    printf("Hex value for c = 256: %x\n", i);

    i = -256;
    printf("Hex value for c = -256: %x\n", i);

    //**************************************************************************//
}

/*****************************************OUTPUT***********************************
for c = 255, value stored: -1
for c = 128, value stored: -128
for c = -1, value stored in hex: ffffffff
for c = 256, value stored: 0
Hex value for c = 256: 100
Hex value for c = -256: ffffff00
***********************************************************************************/

/************************************Summary****************************************
1. Procedure to store negative number:
      - Take the number and invert the bits. //1's complement
      - Add 1 to it -> Answer.    //2's complement
      - Eg. -7 -> 7 -> 0000 0111 -> 1111 1000 (1's) -> 111 1001 (2's) -> Answer

2. In the signed number the MSB has sign bit whereas all bits are data in unsigned number.

3. Variables are signed by default.

4. Convert a 2's complement number to decimal:
      - Find the sign of the number by checking MSB.
      - Find the 2's complement of the number by considering all bits.
      - Convert the answer of above step to decimal and assign the sign to it.
************************************************************************************/
