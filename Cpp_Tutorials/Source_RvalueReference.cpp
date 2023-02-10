//Use of rvalue reference
#include "Header_Reference.h"

int main()
{
	int a = 10;
	int b = a++;
	//a, b - lvalue
	//10, a++ - rvalue

	cin.get();
}

/************************************Summary*****************************************
1. Rvalue references allow programmers to avoid logically unnecessary copying of data.
   This makes the execution faster.

2. Rvalues are the objects which do not have any address.

3. 

4. 

5. 

6. 

7. 

8. 

9. 
************************************************************************************/