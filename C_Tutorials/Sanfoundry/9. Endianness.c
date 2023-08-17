// Code to find the endianness of machine

#include <stdio.h>

union sf_un{
    int val;
    char ch[4];
};

int main()
{
   //*******************************Min value**********************************//
   union sf_un sf1;
   int i;

   sf1.val = 0xAABBCCDD;

   printf("Address of u     = %p\n", &sf1);
   printf("Address of u.val = %p\n", &sf1.val);
   printf("Address of u.ch  = %p\n", &sf1.ch);

   printf("values at address = %p, is %d\n", &sf1.val, sf1.val);

   for (i = 0; i < 4; i++)
   {
        printf("Value at address %p is 0x%x\n", &sf1.ch[i], (unsigned char)sf1.ch[i]);
   }
    //**************************************************************************//
    
}

/*************************************OUTPUT***************************************

***********************************************************************************/

/************************************Summary****************************************
1. What is Endianness?
   

2. Little Endian manufacturer: Intel
   Big endian manufacturer: ARM, PowerPC

3. LLL: Little endian stores the LSB to Lower address. eg, int x = 0xAABBCCDD

    memory storage: DD CC BB AA

4. BLH: Big endian stores the LSB to Higher address. eg, int x = 0xAABBCCDD

    memory storage: AA BB CC DD

5. Portability issues: 
   
************************************************************************************/
