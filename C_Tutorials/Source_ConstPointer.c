//Constant Pointer
#include <conio.h>
#include <stdio.h>

int main()
{
#if 0		//const pointer and const pointer pointing to a const
	int var = 10;
	int var2 = 20;
	int var3 = 30;

	const int* const i = &var3;				//Const pointer pointing to a constant

	int* const ptr =  &var;					//Const pointer

	printf("\n%d",*ptr);
	printf("\n%d",*i);

	var = 20;				//Value can be changed for const pointer

	printf("\n%d",*ptr);

	*ptr = var2;			//data can be changed through pointer but not address

	/*
	Both below statements are invalid for a const pointer to a const
	i = &var;			//cannot update address
	*i = 18;			//cannot update value
	*/

	var3 = 90;			//data can be updated.

	printf("\n%d",*i);

#else	//pointer to a const

	int var1 = 10;
	int var2 = 30;

	const int* ptr;
	ptr = &var1;			//Allowed
	//*ptr = 50;			//Invalid
	var1 = 50;				//Allowed

	printf("\n%d", *ptr);

	
#endif	

}

/************************************Summary*****************************************
1. Constant pointer needs to be initialized during declaration itself. Data in the const
   pointer can be updated by any method. It points to an address for its life.

2. Pointer to a const, points to a constant value and its reference or the variable can 
   be changed or the value can be changed through the variable but not at all using the
   pointer.

3. const pointer to a const cannot update data or address through itself.

4. Constant pointer has to be assigned in declaration itself and this also implies to 
   const pointer to a const.
*************************************************************************************/