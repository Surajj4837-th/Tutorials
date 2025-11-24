//FunctionOverriding.cpp
//Demonstration of function overriding in C++11

#include "FunctionOverriding.h"

using std::cout;
using std::endl;

void animal::Sound()
{
	std::cout << "Animal Sound" << std::endl;
}

void cat::Sound()
{
	std::cout << "Meow" << std::endl;
}

void dog::Sound()
{
	std::cout << "Bark" << std::endl;
}

void human::Sound()
{
	animal::Sound();
}

int main()
{
	animal animal1;
	animal1.Sound();

	cat cat1;
	cat1.Sound();

	dog dog1;
	dog1.Sound();

	//Call base class function
	human human1;
	human1.Sound();

	return 0;
}
/************************************Summary*****************************************
1. Function overriding is redefinition of base class function in its derived class with 
   same signature i.e return type and parameters.
2. By default the derived class function is called but in case the base class function 
   needs to be called then either do not overrride it or call it explicitely in derived 
   class function.
*************************************************************************************/