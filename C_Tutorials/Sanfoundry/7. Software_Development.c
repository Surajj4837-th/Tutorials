// Software development practices
// Write a code to find the range of signed nad unsigned short int variable.
// short int - -31768 to 31767
// unsigned short int - 0 to 65535

#include <stdio.h>

void Find_Max_Method1();
void Find_Min_Method1();
void Find_Max_Method2();
void Find_Min_Method2();
void Find_Max_Method3();
void Find_Min_Method3();
void Find_Max_Method4();
void Find_Min_Method4();

int main()
{
    Find_Min_Method1();
    Find_Max_Method1();

    Find_Min_Method2();
    Find_Max_Method2();

    Find_Min_Method3();
    Find_Max_Method3();

    Find_Min_Method4();
    Find_Max_Method4();
}

void Find_Min_Method1()
{
    //*******************************Min value**********************************//

    short s1 = 0;
    short tmp1 = s1-1;

    while(s1 > tmp1)
    {
        --s1;
        --tmp1;
    }

    printf("Method 1 short min value: %d\n", s1);

    //**************************************************************************//
    
}

void Find_Max_Method1()
{
    //*******************************Max value**********************************//

    short s1 = 0;
    short tmp1 = s1 + 1;

    while (s1 < tmp1)
    {
        ++s1;
        ++tmp1;
    }

    printf("Method 1 short max value: %d\n", s1);

    //**************************************************************************//
}

void Find_Min_Method2()
{
    //*******************************Min value**********************************//

    short s1 = 0;
    short tmp1 = s1-1;

    while(--s1 > --tmp1);

    printf("Method 2 short min value: %d\n", s1);

    //**************************************************************************//\
    
}

void Find_Max_Method2()
{
    //*******************************Max value**********************************//

    short s1 = 0;
    short tmp1 = s1 + 1;

    while (++s1 < ++tmp1);

    printf("Method 2 short max value: %d\n", s1);

    //**************************************************************************//
}

void Find_Min_Method3()
{
    //*******************************Min value**********************************//

    short s1 = 0;

    while(--s1 < 0);

    printf("Method 3 short min value: %d\n", ++s1);

    //**************************************************************************//\
    
}

void Find_Max_Method3()
{
    //*******************************Max value**********************************//

    short s1 = 0;

    while (++s1 > 0);

    printf("Method 3 short max value: %d\n", --s1);

    //**************************************************************************//
}

void Find_Min_Method4()
{
    //*******************************Min value**********************************//
    /*
    short - 16 bits: 1 bit sign, 15 bit data.
    Min data in short in bits:  1000   0000    0000    0000
    In hex:                      8      0       0       0
    */
    short s1 = 0x8000;

    printf("Method 4 short min value: %d\n", s1);

    //**************************************************************************//\
    
}

void Find_Max_Method4()
{
    //*******************************Max value**********************************//
    /*
    short - 16 bits: 1 bit sign, 15 bit data.
    Max data in short in bits:  0111   1111    1111    1111
    In hex:                      7      F       F       F
    */

    short s1 = 0x7fff;

    printf("Method 4 short max value: %d\n", s1);

    //**************************************************************************//
}

/*****************************************OUTPUT***********************************
Method 1 short min value: -32768
Method 1 short max value: 32767
Method 2 short min value: -32768
Method 2 short max value: 32767
Method 3 short min value: -32768
Method 3 short max value: 32767
Method 4 short min value: -32768
Method 4 short max value: 32767
***********************************************************************************/

/************************************Summary****************************************
1. Method 1, 2 and 3 is inefficient when we go for higher bit data type as the loop
   runs for half the range in negative or positive region.
************************************************************************************/
