//C code for pointer to a constant
//Value cannot be changed by dereferencing pointer
#include <conio.h>
#include <stdio.h>

int main()
{
#if 0			//Basic understanding using integers
	const int * i;
	int a = 10;
	int b = 20;

	i = &a;
	//*i = 11;		//Invalid command
	a = 11;

	printf("%d",*i);

	i = &b;			//Pointer to a constant can point to any variable
	
	printf("\n%d",*i);
	*/
#else		//Understanding using char pointers

	const char * ptr;
	char var2[10] = "Hello";
	char *var1 = "MNPO";
	char *var = "XyZ";
	/*
		This statement copies data "XyZ" into text segment and thus cannot be updated.
		the address pointing to pointer can be updated.
	//Invalid cases
	// *var = "abc";	
	// var[0] = 'a';
	*/	

	ptr = var1;

	printf("%s",ptr);
	//*ptr = "XYZ";		//Updating value through pointer, not allowed

	ptr = var;				//Pointer can update its pointing address

	printf("\n%s",ptr);

	ptr = var2;

	printf("\n%s",ptr);

	*var2 = 'M';			//Updating value through variable is allowed
	*(var2 + 1) = 'i';

	printf("\n%s",ptr);

#endif	

}

/************************************Summary*****************************************
1. Pointer to a constant can be initialized to any pointer at any time.

2. Pointer to a constant does not allow to change the value pointed by it through its access.

3. The value pointed by pointer can be changed by accessing the variable.

4. When a char pointer is assigned a string, that string cannot be modified through the 
   normal pointer also.

5. When a char array is assigned a string, it can be modified by that accessing that variable.
*************************************************************************************/