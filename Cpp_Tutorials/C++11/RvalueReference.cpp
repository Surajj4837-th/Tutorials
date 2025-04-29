//Use of rvalue reference
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
	//a, b - lvalue
	//10, a++ - rvalue

	printNumber(a);
	printNumber(10);

	//int && ref1 {a};	//error:  cannot bind 'int' lvalue to 'int&&'
	const int&& ref1 {a};

	int&& ref2 {a};
	ref2 = 12;
	
	printNumber(ref2);	//calls the lvalue funciton as the passed parameter has an address.

	cin.get();
}

/************************************Summary*****************************************
1. Rvalue references allow programmers to avoid logically unnecessary copying of data.
   This makes the execution faster.

2. Rvalues are the objects which do not have any address.
************************************************************************************/