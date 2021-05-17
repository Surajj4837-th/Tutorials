#include <iostream>

class Employee
{
public:
	int emp_id;
	int salary;

	Employee(int var1, int var2);
	void show();
};

class Engineer : public Employee
{
private:
	int experience;

public:
	Engineer(int var1, int var2, int var3);
	void show();
};
