//Memory Allocation
#include <stdio.h>

int main()
{
    //**************************************************************************//
    char *charp, charv;
    int *intp, intv;
    long *longp, longv;
    long long *llongp, llongv;
    float *floatp, floatv;
    double *doublep, doublev;

    printf("char pointer size: %lu\n", sizeof(charp));
    printf("char variable size: %lu\n", sizeof(charv));
    printf("int pointer size: %lu\n", sizeof(intp));
    printf("int variable size: %lu\n", sizeof(intv));
    printf("long pointer size: %lu\n", sizeof(longp));
    printf("long variable size: %lu\n", sizeof(longv));
    printf("long long pointer size: %lu\n", sizeof(llongp));
    printf("long long variable size: %lu\n", sizeof(llongv));
    printf("float pointer size: %lu\n", sizeof(floatp));
    printf("float variable size: %lu\n", sizeof(floatv));
    printf("double pointer size: %lu\n", sizeof(doublep));
    printf("double variable size: %lu\n", sizeof(doublev));

    //**************************************************************************//
 
    void *voidp;  //void variables cannot be declared
    printf("void size: %lu\n", sizeof(void));
    printf("void pointer size: %lu\n", sizeof(voidp));

    printf("100 size: %lu\n", sizeof(100));  //memory upgraded to fitting datattype
    printf("0x ff ff size: %lu\n", sizeof(0xffff));  //memory upgraded to fitting datattype
    printf("0x ff ff 11 11 size: %lu\n", sizeof(0xffff1111));
    printf("0x ff ff 11 11 EE EE size: %lu\n", sizeof(0xffff1111EEEE));  //memory upgraded to fitting datattype

    //**************************************************************************//
}

/*****************************************OUTPUT***********************************
char pointer size: 8
char variable size: 1
int pointer size: 8
int variable size: 4
long pointer size: 8
long variable size: 8
long long pointer size: 8
long long variable size: 8
float pointer size: 8
float variable size: 4
double pointer size: 8
double variable size: 8
void size: 1
void pointer size: 8
100 size: 4
0x ff ff size: 4
0x ff ff 11 11 size: 4
0x ff ff 11 11 EE EE size: 8
***********************************************************************************/

/************************************Summary****************************************
1. Memory allocation is necessary for:
      - user sapce debugging
      - kernel space debugging
      - crash analysis
      - memory dumps

2. Data type sizes for 32bit machine:
      char, uchar, schar - 1B
      int, sint, uint - 4B
      short int, ushort int, sshort int - 2B c
      long int, ulong int, slong int - 4B
      long long, ulong long - 8B
      float - 4B     //6 digit representation
      double - 8B    //10 digit representation

3. Data type sizes for 32bit machine. Everything is same as 32bit machine except:
   - long is updated to 8B.
   - long long is same as long.

************************************************************************************/
