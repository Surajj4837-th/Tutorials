//Use of Reference/alias
#include "Header_Reference.h"

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void SwapUsingAlias(int& ra, int& rb)
{
	//No 
	int temp = ra;
	ra = rb;
	rb = temp;
}

//Return type for a refernce
int& getSquare(int & x)
{
	x *= x;
	return (x);
}

/*
int& getSquare(int & x)
{
	int b = x*x;
	return (b);
}

This is a faulty code as the reference of b is being returned
from the function. As the life of b ends after the end of function
the passed reference does not contain intended data.
*/

int main()
{
	int x = 10;
	//variable x occupies some memory

	/*
	 Syntax:
	 Datatype variable = value; value is optional
	 Datatype &alias = variable;
	*/

	int &y = x;		//y is an alias to x

	++y;

	cout << x << endl;

	int a = 10;
	int b = 20;

	//swap(&a, &b);
	SwapUsingAlias(a,b);

	cout << a << "\t" << b<< endl;

	b = getSquare(a);
	cout << a << "\t" << b<< endl;

	getSquare(b) = 1000;
	//This command works and b gets value 1000.
	//This works but should not be used as it confuses and may create unintended results.

	//b = getSquare(10);
	//This results in an error because function getSquare is expecting a refernce
	//to an existing variable and not a constant parameter.

	cout << a << "\t" << b<< endl;

	cin.get();
}

/************************************Summary*****************************************
1. C++ gives the feature to refer already existing variable by an alias.

2. Internally this alias is considered as a constant pointer, whatever happens to the 
   content of alias same happens to the content of variable.

3. Use of alias: When a reference is passed to a function, the operation looks like a 
   pass by value but the changes done to the reference are reflected to the passed 
   parameters.

4. Although it is a pointer, referenceing(&) and dereferncing(*) is done implicitly, 
   it increases code readability.

5. Change in return type in case of returning a reference.

6. One cannot pass a constant value instead of a variable to a function whose parameter
   is a refernce.

7. One cannot assign an expression to a reference.

8. Never return a reference of a local variable.

9. Do not use the function with refernce as parameter on the left side of the assignment
   operator.
************************************************************************************/