// C++11/VirtualFunction.h
// Virtual function in C++11

#include <iostream>

class Base
{
public:
	void show()
	{
		std::cout << "Base class show function called." << std::endl;
	}

	virtual void print()
	{
		std::cout << "Base class print function called." << std::endl;
	}
};

class Derived : public Base
{
public:
	void show()
	{
		std::cout << "Derived class show function called." << std::endl;
	}

	void print() override
	{
		std::cout << "Derived class print function called." << std::endl;
	}
};


//Abstract class
class Animal
{
public:
	virtual void sound() = 0;
};


class Dog : public Animal
{
	void sound() override
	{
		std::cout << "Dogs bark." << std::endl;
	}
};


class Human : public Animal
{
	//As virtual function from base classs is not
	//overriden this class also becomes abstract class.

};


class Cat : public Animal
{
	//Use of override keyword
	/*int sound() override
	{
		std::cout << "Cats meow." << std::endl;
	}*/
};
