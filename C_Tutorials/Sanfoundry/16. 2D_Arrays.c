// 2D Arrays
#include <stdio.h>

int main()
{
   //********************************Initialization****************************//

   int arr1[3][3] = {1,2,3,4,5,6,7,8,9};

   int arr2[3][3] = {{1,2,3},
                     {4,5,6},
                     {7,8,9}};      //More readable

   //**************************************************************************//
   char city[][20] = {"Banglore", "Chennai", "Mumbai", "Kolkata", "Mysore", 
                     "Raipur", "Delhi", "Hyderabad", "Pune", "Indore"};

   printf("city[0][9] = %c\n", city[0][9]);  //Null value at this location

   printf("city[0][15] = %c\n", city[0][15]);  //Null value at this location

   printf("city = %s\n", city);  // city represents the starting location of the
                                 // array, printing will stop at Null

   printf("city[1] = %s\n", city[1]);

   printf("city[2][0] = %c\n", city[2][0]);

   printf("city[2] = %s\n", city[2]);     // Mumbai is printed
   // printf("city[2][0] = %s\n", city[2][0]);  // RUNTIME ERROR: Segmentation Fault
   // %s takes the address to read as ASCII value of 'M': 77

   //****************************Faster loop***********************************//

   int a[10][10], i, j;

   for(i = 0; i < 10; i++)
   {
      for (j = 0; j < 10; j++)
      {
         a[i][j] = i+j;
      }
   }

   for(i = 0; i < 10; i++)
   {
      for (j = 0; j < 10; j++)
      {
         a[j][i] = i+j;
      }
   }

   // Locality of Reference:
   // 1st loop will be faster as the OS will fetch the subsequent data in cache.
   // Due to that the time for fetching data from main memory is reduced.
   //**************************************************************************//
    
}

/*************************************OUTPUT***************************************
city[0][9] = 
city[0][15] = 
city = Banglore
city[1] = Chennai
city[2][0] = M
city[2] = Mumbai
***********************************************************************************/

/************************************Summary****************************************
1. syntax: type array_name[row_size][col_size];

2. C follows row-major storage i.e. the rows are stored one after the other.

3. Declaration of a multidimensional array must have bounds for all dimensions except 
   the first.
************************************************************************************/
