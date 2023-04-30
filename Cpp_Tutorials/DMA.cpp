//Use of DMA

#include "Header.h"

/****************Macro Declaration***********/

#define LEN					(12)

/********************************************/

class ToyCar			//PascalCase
{			
	int numOfWheels;	//camelCase
	char color[LEN];	//1 byte consumed by '/0' in the end
	/*
	char *ptrColor;
	*/

public:
	//Constructor
	ToyCar()
	{
		cout <<"Default Constructor" << endl;
		numOfWheels = 4;
		//ptrColor = new char[6];
		strcpy(color, "White");
	}

	ToyCar(int num, const char* clr)
	{
		cout <<"Parameterized Constructor" << endl;
		numOfWheels = num;
		//ptrColor = new char [strlen(clr) + 1];
		strcpy(color, clr);
	}

	void DisplayAttributes()
	{
		cout << numOfWheels << endl;
		cout << color << endl;
	}

};	//End of class

int main()
{
	int arr[5];									//Local variable created on Stack
	int *ptr = (int *)malloc(5 * sizeof(int));	//ptr is created on Stack as it is a local variable
												//and malloc allocates memory on Heap.
	ptr[1] = 10;
	cout << *(ptr+1) << endl;
	free(ptr);						//delete the allocated memory, ptr remains till EOF

	int *ptr1 = new int(123);
	cout << *ptr1 << endl;
	delete ptr1;					//delete the allocated memory, ptr1 remains till EOF

	int *ptr2 = new int [5];		//For multiple element memory allocation
	*ptr2 = 200;
	ptr2++;
	*ptr2 = 201;
	
	/*
	delete [] ptr2;
	Compiler tries to deallocate the entire block of memory but we have shifted the pointer
	from its initial pointing location, it will try to delete 5 memory locations from current
	position which is a logical error. This is detected by some compiler and warning is given in runtime.
	*/
	
	/* 
	delete ptr2;
	This is a logical error and some compilers do not give this error.
	At this point the compiler returns to the first element of memory and then deallocates
	only the first block and returns.
	The remaining blocks are still allocated and now are not in control of the	pointer.
	This creates 'memory leak'.
	This when done multiple times may result in crash or out of memory scenario.
	free(ptr) deallocates whole block of memory.
	*/

	ptr2--;
	delete[] ptr2;


	//Application of DMA
	ToyCar maruti;				//color - White, 6 bytes wasted

	ToyCar toyota(4, "Blue");	//color - Blue,  7 bytes wasted

	ToyCar ferrari(4, "Red");	//color - Red, 8 bytes wasted

	//color can be replaced by pointer for DMA
	
	maruti.DisplayAttributes();
	toyota.DisplayAttributes();
	ferrari.DisplayAttributes();

	cin.get();
	return 0;
}	

/************************************Summary*****************************************
1. Why malloc or calloc returns pointer?
   As the memory is created in heap segment and it is used by a global or local variable
   stored on stack, to refer to the allocated memory malloc or calloc returns pointer.

2. malloc returns void pointer and calloc allocates memory and makes all content 0.
   
3. realloc is used to increase the already allocated memory.

4. use of sizeof operator - It makes the memory allocation system independent, if the 
   developer writes 2 instead of 'sizeof(int)' and the code is made to run on a 64 bit 
   system then it will create issues.

5. free() is used to delete the the memory allocated using malloc or calloc.

6. C++ introduced keyword 'new' to allocate and 'delete' to deallocate memory. Simple 
   syntax as compared to malloc and calloc. It is also system independent.

7. new allows to store the value in memory during memory allocation (initialization)
   in case of single element.

8. malloc is a function whereas new is an operator and is faster than malloc.

9. As a pointer only contains an address, can we allocate an int pointer and store
   char values into it? We can do that but when we operate on the address like ++adr,
   the compiler will move forward by 4 bytes which will skip 3 char elements.

10. Placement new is a variation of new, where we can choose memory location to store
	the new memory. Due to this DMA can be done on stack also.
************************************************************************************/