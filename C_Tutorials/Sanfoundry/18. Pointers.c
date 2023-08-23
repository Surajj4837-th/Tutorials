// Pointers
#include <stdio.h>

int main()
{
   //*****************************Initialization*******************************//
   int var  = 100;

   int *ptr = var;
   ptr = &var;

   //**************************************************************************//

   printf("var = %d\n", var);
   printf("&var = %p\n", &var);
   printf("ptr = %p\n", ptr);
   printf("&ptr = %p\n", &ptr);
   printf("*ptr = %d\n", *ptr);

   // ERROR: invalid type argument of unary ‘*’ 
   // printf("**ptr = %d\n", **ptr);
   // printf("*var = %d\n", *var);

   // No error but segmentation fault is occured
   // printf("**ptr = %d\n", *(int *)*ptr);
   // printf("**var = %d\n", *(int *)var);
   
   //*****************************Double Pointer*******************************//

   int **ptrptr = &ptr;    //ptrptr - Pointer to an interger pointer

   printf("ptrptr = %p\n", ptrptr);
   printf("&ptrptr = %p\n", &ptrptr);
   printf("*ptrptr = %p\n", *ptrptr);
   printf("**ptrptr = %d\n", **ptrptr);
   printf("**(&ptrptr) = %p\n", **(&ptrptr));
   printf("***(&ptrptr) = %d\n", ***(&ptrptr));

   // ERROR:invalid type argument of unary ‘*’
   // printf("***ptrptr = %d\n", ***ptrptr);

   // No error but segmentation fault is occured
   // printf("***ptrptr = %d\n", *(int *)**ptrptr);

   //*****************************Pointer Arithmetic***************************//

   // var + 1 -> 101
   // ptr + 1 -> ptr value + sizeof(int)
   // ptrptr + 1 -> ptrptr + sizeof(int * )

   int *ptr2;
   ptr2 = ptr;

   ptr2++;

   printf("ptr = %p\n", ptr);
   printf("ptr2 = %p\n", ptr2);
   printf("ptr2 - ptr = %d\n", ptr2 - ptr);
   printf("(char *)ptr2 - (char *)ptr = %d\n", (char *)ptr2 - (char *)ptr);
   printf("(void *)ptr2 - (void *)ptr = %d\n", (void *)ptr2 - (void *)ptr);

   // error: invalid operands to binary + (have ‘int *’ and ‘int *’)
   // printf("ptr2 + ptr = %d\n", ptr2 + ptr);

   ptr = ptr - 100; // Jumping 100 posintions by scaling factor of int

   //**************************************************************************//
    
}

/*************************************OUTPUT***************************************

***********************************************************************************/

/************************************Summary****************************************
1. type *name; 
   name stores address.
   * is used to dereference the variable.
   & is used to get the address of a variable.

2. Pointer arithmetic include multiplication, deletion, addition and subtraction. Division
   is not a part of this.

3. Scaling factor: Pointers get incremented by the size of the data type of the variable 
   to which it is pointing to.

4. In pointer arithmetic the difference between 2 pointers will give the storage capacity 
   between them. The addition and multiplication of 2 pointers will not give anything.
   Hence the compiler gives an error.

5. Addition and subtraction of a pointer with a value will allow a jump from 1 locaiton 
   to another keeping scaling factor in calculation.
************************************************************************************/