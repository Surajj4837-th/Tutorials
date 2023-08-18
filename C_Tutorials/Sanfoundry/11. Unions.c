// Union

#include <stdio.h>

union TimeOfDay{

 int morning;
 int afternoon;
 int evening;
 int night;

};

union un{
   short val;
   char ch;
};

int main()
{
   //**************************************************************************//
   
   union un un1;

   un1.val = 258;
   un1.ch = 1;

   printf("Union value: %d\n", un1.val);
   printf("Union char: %d\n", un1.ch);
   
   //**************************************************************************//
    
}

/*************************************OUTPUT***************************************
Union value: 257
Union char: 1
***********************************************************************************/

/************************************Summary****************************************
1. All members of union share a common memory space.

2. Data stored in memory is valid for only 1 member and garbage for other members.

3. Applications of union:
   - Protocol
   - Hardware (CPU registers)
   - Device drivers
   - Product revisions
   - Linux kernel

4. We cannot modify a code written using structure to use union.
************************************************************************************/
