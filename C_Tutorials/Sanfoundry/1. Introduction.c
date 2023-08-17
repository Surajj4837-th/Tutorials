//Introductory C examples

#include <stdio.h>


int main()
{
    //**************************************************************************//

    printf("sizeof(unsigned long) = %d\n", sizeof(unsigned long));

	if (sizeof(int) > -1)
        printf("True\n");
    else
        printf("False\n");

    //False as -1 is converted to unsigned long that comes out to 18,446,744,073,709,551,615

    //**************************************************************************//

    float f = 0.1;

    printf("%f\n", f);
    printf("%lf\n", 0.1);

    if (f == 0.1)   //float compared with double
        printf("True\n");
    else
        printf("False\n");

    //Due to difference in degree of precision they will have different values

    if (f == 0.1f)   //float compared with float
        printf("True\n");
    else
        printf("False\n");

    //**************************************************************************//

    int a, b = 1, c = 1;

    a = sizeof(c = ++b + 1);
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    /*
    Expected output : a = 4, b = 2, c = 3
    Printed output:   a = 4, b = 1, c = 1
    sizeof() operator is going to deduce value in compile time and hence a = 4,
    this line will be replaced by 'a = 4;' in runtime, hence the operator is not 
    deduced in run time the values of b and c are unchanged.
    */

    //**************************************************************************//

    char *p = 0; //This statement does not assign 0 value to *p, here 0 is NULL.

    // *p = 'A';   //p points to NULL and that location cannot be written, core dump error.

    // printf("Value of p = %c\n", *p);
   
    //**************************************************************************//

    int d = 1, e = 3, g = 2;
 
    if (d > e)
        if (e > g)
            printf("d > e > g\n");

    else
        printf("e < g\n");

    /* 
    Nothing is printed on screen. Although the indentation of if and else conditions
    are correct, the else belongs to 2nd if. It is necessary to write else condition
    even if empty to get correct output.
    */
    //**************************************************************************// 
}

/************************************Summary****************************************
1. sizeof() returns long unsigned integer datatype.

2. When comparing signed with unsigned, the compiler converts the signed value to unsigned.

3. Many binary operators that expect operands of arithmetic type cause conversions and 
   yield result types in a similar way. The conversion sequence is as follows:
   - If either operand is of type long double, the other shall be converted to long 
        double.
   - Else, if either operand is double, the other shall be converted to double.
   - Else, if either operand is float, the other shall be converted to float.
   - Else, if either operand is unsigned long the other shall be converted to unsigned 
        long.
   - Else, if either operand is long, the other shall be converted to long.
   - Else, if either operand is unsigned, the other shall be converted to unsigned.

3. By default C language converts decimals to double data type. Append 'f' to decimal
   to represent float number.

4. Core Dump Error: Whenever we do illegal access to memory or whenever we have access
   to memory but we are not supposed to write that then this error occurs. Whenever we
   do illegal access in Linux then we get error: SIGSEGV.

5. Give else conditions to all ifs.

************************************************************************************/
