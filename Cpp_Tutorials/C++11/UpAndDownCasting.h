// C++11/UpAndDownCasting.h
// Upcasting and Downcasting in C++11

#include <iostream>

class Employee
{
public:
	void DisplayTag();
	virtual void PrintDesignation();
};


class Engineer : public Employee
{
public:
	Engineer():Employee(){}

	void DisplayTag();
	void PrintDesignation();
};
