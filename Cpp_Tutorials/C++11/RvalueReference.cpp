//C++11/RvalueReference.cpp
//Use of rvalue reference and move semantics in C++11

#include <iostream>

using std::cout;
using std::endl;

void printNumber(int& number)
{
	cout << "Printing in lvalue reference function: " << number << endl;
}

void printNumber(int&& number)
{
	cout << "Printing in rvalue reference function: " << number << endl;
}

int main()
{
	int a = 10;
	int b = a++;
	// a, b - lvalue
	// 10, a++ - rvalue

	printNumber(a);
	printNumber(10);

	// int && ref1 {a};		//compile error:  cannot bind 'int' lvalue to 'int&&'
	// const int&& ref1 {a};	//error: an rvalue reference cannot be bound to an lvalue

	int&& ref2 = 12;	//Declare r value reference
	ref2 = 13;			//Update the value
	
	printNumber(a);	//calls the lvalue function as the passed parameter has an address.
	
	printNumber(ref2);	//calls the rvalue function as the passed parameter is a value.

	std::cin.get();
}

/************************************Summary*****************************************
1. Rvalue references allow programmers to avoid unnecessary copying of data. This makes
   the execution faster.

2. Rvalues are the objects which do not have any address.

3. When objects are passed around, especially large containers or dynamically allocated 
   resources, copying them can be expensive in terms of time and memory. Rvalue references
   allow moving these objects instead of copying them, which is faster and more efficient.
************************************************************************************/