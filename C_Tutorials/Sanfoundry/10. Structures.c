// Structure

#include <stdio.h>

struct emp
{
   int ID;
   char name[30];
   // char designation[90];
   // float salary;
};

struct emp E2;

int main()
{
   //**************************************************************************//
   struct emp E1 = {1, "Suraj"};

   printf("Employee ID: %d\n", E1.ID);
   printf("Employee ID: %s\n", E1.name);
   printf("Address of Employee : %p\n", &E1);
   printf("Address of Employee ID: %p\n", &E1.ID);
   printf("Address of Employee name: %p\n", E1.name);



   printf("Enter Employee ID:\n");
   scanf("%d", &E2.ID);
   printf("Enter Employee Name:\n");
   scanf("%s", E2.name);

   printf("Employee ID: %d\n", E2.ID);
   printf("Employee ID: %s\n", E2.name);
   printf("Address of Employee : %p\n", &E2);
   printf("Address of Employee ID: %p\n", &E2.ID);
   printf("Address of Employee name: %p\n", E2.name);

   // The addresses printed for both employees are far away since 1 is in stack 
   // and another is data segment.

   printf("Size of Employee ID: %d bytes.\n", sizeof(E2.ID));
   printf("Size of Employee name: %d bytes.\n", sizeof(E2.name));
   printf("Size of Employee : %d bytes.\n", sizeof(E2));

   // There is a difference between the number of bytes of memory of each member
   // and the size of a structure object. This happens due to padding.
   
   //**************************************************************************//
    
}

/*************************************OUTPUT***************************************
Employee ID: 1
Employee ID: Suraj
Address of Employee : 0x7fffffffda10
Address of Employee ID: 0x7fffffffda10
Address of Employee name: 0x7fffffffda14
Enter Employee ID:
2
Enter Employee Name:
Ashish
Employee ID: 2
Employee ID: Ashish
Address of Employee : 0x555555558040
Address of Employee ID: 0x555555558040
Address of Employee name: 0x555555558044
Size of Employee ID: 4 bytes.
Size of Employee name: 30 bytes.
Size of Employee : 36 bytes.
***********************************************************************************/

/************************************Summary****************************************
1. It is a user defined data type. It is a collection of homogeneous or heterogeneous 
   data types.
   
************************************************************************************/
