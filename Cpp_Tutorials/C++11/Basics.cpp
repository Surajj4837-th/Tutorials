//Basics.cpp
//Demonstration of basic input output in C++11

#include <iostream>

using std::cout;
using std::endl;
using std::cin;


int main()
{
	cout << "Hello World" << endl;
	//cout is an object of class ostream
	//ostream is an inbuilt classs
	//insertion operator '<<' inserts right hand side variable/string to left side object

	/*cout can be used to display:
	string
	charachter
	constant
	variable
	expression
	function
	example:
	cout << "Hello" << 'x' << 2018 << x << x*x << func() ;
	*/

	cout << "Enter a number : ";

	int num;
	//variable declaration in C++ can be done anywhere in code
	//before its first use

	cin >> num;
	//cin is a standard library of object istream
	//extraction operator '>>' extracts the entry done on keyboard and provides it to the 
	//program

	cout << "Square of "<< num <<" is "<< num*num << endl;
	//no need of format specifier

	for(int Counter = 0; Counter < 10; Counter++)
	{
		//'Counter' is local variable whose scope is upto end of the loop
	}

	cin.get();
	//Equivalent to getch()

	return 0;	
	//Return 0 to OS, value 0 indicates success
	//What is the need? There are chances of program terminating 
	//in between and it involves a non zero value being returned to the OS
	//OS understands there was something wrong with the code execution

}