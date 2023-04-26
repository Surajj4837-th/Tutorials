#include "Header_Slicing.h"

Employee::Employee(int var1, int var2)
{
	emp_id = var1;
	salary = var2;
}

void Employee::show()
{
	std::cout << "Employee ID: " << emp_id << std::endl;
	std::cout << "Salary: " << salary << std::endl;
}

Engineer::Engineer(int var1, int var2, int var3): Employee(var1, var2)
{
	experience = var3;
}

void Engineer::show()
{
	std::cout << "Employee ID: " << emp_id << std::endl;
	std::cout << "Salary: " << salary << std::endl;
	std::cout << "Experience: " << experience << std::endl;
}


int main()
{
	Employee emp1(100, 10000);
	Engineer eng1(101, 10001, 3);

	std::cout << "Initialization: " << std::endl;
	emp1.show();
	std::cout << std::endl;
	eng1.show();

	std::cout << "After Slicing: " << std::endl;

	//Slicing
	emp1 = eng1;
	emp1.show();
	std::cout << std::endl;
	eng1.show();

	//eng1 = emp1;	//Not possible

	return 0;
}

/************************************Summary*****************************************
1. Object slicing: when derived classs object is assigned to base class object then extra
   attributes from derived class are not copied.
*************************************************************************************/