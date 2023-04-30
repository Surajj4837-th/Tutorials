#include "UpAndDownCasting.h"


void Employee::DisplayTag()
{
	std::cout << "Employee" << std::endl;
}

void Employee::PrintDesignation()
{
	std::cout << "Employee" << std::endl;
}

void Engineer::DisplayTag()
{
	std::cout << "Engineer" << std::endl;
}

void Engineer::PrintDesignation()
{
	std::cout << "Engineer" << std::endl;
}

int main()
{
	Employee *emp1_ptr = new Employee;
	Engineer *eng1_ptr = new Engineer;

	emp1_ptr->DisplayTag();
	eng1_ptr->DisplayTag();

	//Upcasting
	std::cout << "Upcasting:" << std::endl;
	Employee* emp2_ptr = eng1_ptr;
	emp2_ptr->DisplayTag();

	//Downcasting is not allowed without an explicit type cast.
	//Engineer eng2_ptr = emp1_ptr;

	return 0;
}

/************************************Summary*****************************************
1. C++ provides a special explicit cast called dynamic_cast that performs downcasting.
*************************************************************************************/
