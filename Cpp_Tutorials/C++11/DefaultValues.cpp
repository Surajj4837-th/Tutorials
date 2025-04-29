#include <iostream>

using std::cout;
using std::endl;

/****************Function Declaration***********/

//void DoSomething(int x = 1);

void Function(int a, int b , int c = 1);

/********************************************/

void DoSomething(int x = 1)		//Declaration not needed as this definition 
								//is read before encountering function call.
{
	cout << x << endl;
}

int main()
{
	DoSomething(10);
	DoSomething();

	Function(10,20);

	cin.get();
	return 0;
}


void Function(int a, int b, int c)		//Declaration done in header file.
{
	cout << a << "\t" << b << "\t" << c << endl;
}

/************************************Summary*****************************************
1. C++ compiler will throw an error if it finds a function call before coming accross
   its declaration/definition, this error is not thrown by C compiler.
   The compiler throws an error because it does not know if the function call is
   correct or not. A C compiler will allow the function call and when it comes accross
   a definition, it will check the syntax of its call with the definition and will decide
   further action.

2. Default value to a function parameter: it is a default value given to an argument
   of the function parameter which is used in case the parameter is not passed.

3. Rules of Default Values:
	a. Use default values only in function declaration, if there is only function 
	   definition present then we can use default values there also but it should be 
	   placed before main function.
	b. Compiler assigns the values to parameters from left to right, thus default 
	   value parameters to be kept at the end of the parameter list i.e. to the right side.
	c. If developer wants to assign a default value to a parameter in the middle or
	   in the begining of the parameter list then the parameters to the right of it 
	   should also be provided with default values.

4. What is the use of default values?
   There are cases when the values remain same most of the times, for example parameters 
   like number of wheels of car, number of digits in a phone number, etc.
************************************************************************************/