// 1D Array
#include <stdio.h>

int main()
{
   //*******************************Initialization*****************************//

   char arr1[10] = {'S', 'U', 'R', 'A', 'J'}; // NULL is automatically appended.

   char arr2[] = {'J', 'A', 'D', 'H', 'A', 'V', '\0'};

   char arr3[6];
   arr3[0] = 'A';
   arr3[1] = 'r';
   arr3[2] = 'r';
   arr3[3] = 'a';
   arr3[4] = 'y';
   arr3[5] = '\0';

   //char string
   char arr4[] = "Suraj";  // NULL is automatically appended.
   char arr5[] = {"Jadhav"};  // NULL is automatically appended.

   //**************************************************************************//

   printf("String length of arr1: %lu\n", strlen(arr1));
   printf("Size of arr1: %lu\n", sizeof(arr1));

   //**************************************************************************//

   strcpy(arr2, arr1);
   printf("%s\n", arr1);
   printf("%s\n", arr2);

   //**************************************************************************//
   int arr6[9] = {};       //Bracket initialization assigns uninitialized values to 0
   int arr7[9] = {1,2,3};  //Bracket initialization assigns uninitialized values to 0
   int arr8[9];

   printf("arr6[4]: %d\n", arr6[4]);
   printf("arr7[4]: %d\n", arr7[4]);
   printf("arr8[4]: %d\n", arr8[4]);

   //**************************************************************************//
    
}

/*************************************OUTPUT***************************************
String length of arr1: 5
Size of arr1: 10
SURAJ
SURAJ
arr6[4]: 0
arr7[4]: 0
arr8[4]: -9690
***********************************************************************************/

/************************************Summary****************************************
1. Array: collection of same data type items.

2. Data storage is contiguous.

3. {} initialization assigns 0 to uninitialized places.
************************************************************************************/
