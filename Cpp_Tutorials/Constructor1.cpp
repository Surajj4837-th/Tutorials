//Use of constructor continued
#include <iostream>

using std::cout;
using std::endl;

/****************Macro Declaration***********/

#define LEN					(12)

/********************************************/

class ToyCar			//PascalCase
{			
	int numOfWheels;	//camelCase
	char color[LEN];

public:
	//Constructor
	ToyCar()
	{
		cout <<"Default Constructor" << endl;
		numOfWheels = 4;
		strcpy(color, "White");
	}

	ToyCar(int num, const char* clr)
	{
		cout <<"Parameterized Constructor" << endl;
		numOfWheels = num;
		strcpy(color, clr);
	}

	void DisplayAttributes()
	{
		cout << numOfWheels << endl;
		cout << color << endl;
	}
};	//End of class

int main()
{
	ToyCar maruti;			//Calls default constructor function

	ToyCar toyota(4, "Blue");

	ToyCar ferrari(4, "Red");

	maruti.DisplayAttributes();
	toyota.DisplayAttributes();
	ferrari.DisplayAttributes();

	cin.get();
	return 0;
}

/************************************Summary*****************************************
1. Whenever a new object is created its corresponding constructor is called.

2. Constructor is called for every object which is created from that class.

3. Constructor is a special member function and its name is same as class name.

4. No return type used for constructor.

5. Constructors are not inherited by the child class.

6. By default the default constructor is called.

7. C does not allow function overloading as well as operator overloading.

8. It is not compulsory to initialize all data members but it is good practice to do so.

9. Macros improves readability.

10. Macros are replaced during compile time with their values. This avoids the time
	consumed by variables to access their memory during runtime.
************************************************************************************/