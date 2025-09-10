//Requirement of = operator overloading
#include <iostream>
#include <cstring>

using namespace std;

class ToyCar			//PascalCase
{			
	int numOfWheels;	//camelCase	
	char *ptrColor;	

public:
	//Constructor
	ToyCar()
	{
		cout << "Default Constructor" << endl;
		numOfWheels = 4;
		ptrColor = new char[6];
		strcpy(ptrColor, "White");
	}

	//Parameterized constructor
	ToyCar(int num, const char* clr)
	{
		cout << "Parameterized Constructor" << endl;
		numOfWheels = num;
		ptrColor = new char [std::strlen(clr) + 1];
		strcpy(ptrColor, clr);
	}

	//Copy Constructor
	ToyCar(const ToyCar& Object)		//Reference
	{
		cout << "\nCopy Constructor" << endl;
		numOfWheels = Object.numOfWheels;
		ptrColor = new char [std::strlen(Object.ptrColor) + 1];
		strcpy(ptrColor, Object.ptrColor);
	}

	void DisplayAttributes() const
	{
		cout << numOfWheels << endl;
		cout << ptrColor << endl;
	}

	void ChangeColor(const char* clr)
	{
		strcpy(ptrColor, clr);
	}

	~ToyCar()
	{
		cout <<"Destructor " << ptrColor << endl;
		delete [] ptrColor;
	}

	ToyCar& operator=(const ToyCar& rhs)
	{
		cout << "Assignment operator" << std::endl;

		if (this == &rhs)
			return *this;

		// deep copy
		delete[] this->ptrColor;
		this->ptrColor = new char[std::strlen(rhs.ptrColor) + 1];
		strcpy(this->ptrColor, rhs.ptrColor);

		return *this;
	}

};	//End of class

int main()
{
	ToyCar mini(4, "White");

	ToyCar ambulance(4, "Red");

	mini.DisplayAttributes();		//4, White
	ambulance.DisplayAttributes();	//4, Red
	cout << endl;

	mini = ambulance;
	//Pointer address also copied(shallow copy), if no overloaded = operator
	//memory allocated to mini color is leaked in that caseS
	//Copy constructor is not involved, assignment operator

	mini.DisplayAttributes();		//4, Red
	ambulance.DisplayAttributes();	//4, Red
	cout << endl;

	mini.ChangeColor("Blue");

	mini.DisplayAttributes();
	ambulance.DisplayAttributes();

	cin.get();
	
	/*
	 In case the = is not overloaded then the mini and ambulance wll have same pointer.
	 Destructor for ambulance is called first.
	 Next the destructor of mini is called but the pointer pointed by the mini color is already destroyed.
	 Crash happens in this case along with memory leak.
	 To solve this operator overloading is required for '=' operator.
	 Assignment is a binary operator.
	 */

	return 0;
}

/************************************Summary*****************************************
1. C++ provides a default assignment operator used for assigning one object to
   another if there is no user defined.

2. Default assignment operator is fine if there are no raw pointers in the class.

3. The overloaded = operator returns a reference to a class operator (ToyCar&), this
   avoids creating a copy of the object.
   a = b = c;
   If operator= returned by value, b = c would create a temporary copy, and then 
   a = <temp> would be another copy. Returning by reference avoids these copies.

   It also enables operator chaining a = b = c;

4. Deep copy steps, to be done for each raw pointer:
   Delete the existing string.
   Assign the new string memory = length of new string + 1
   Copy the data
   Return the object
************************************************************************************/