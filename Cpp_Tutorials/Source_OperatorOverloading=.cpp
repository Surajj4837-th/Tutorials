//Requirement of = operator overloading
#include "Header_Constructor.h"

class ToyCar			//PascalCase
{			
	int numOfWheels;	//camelCase	
	char *ptrColor;	

public:
	//Constructor
	ToyCar()
	{
		cout <<"\nDefault Constructor" << endl;
		numOfWheels = 4;
		ptrColor = new char[6];
		strcpy(ptrColor, "White");
	}

	//Parameterized constructor
	ToyCar(int num, const char* clr)
	{
		cout <<"\nParameterized Constructor" << endl;
		numOfWheels = num;
		ptrColor = new char [strlen(clr) + 1];
		strcpy(ptrColor, clr);
	}

	//Copy Constructor
	ToyCar(const ToyCar& Object)		//Reference
	{
		cout <<"\nCopy Constructor" << endl;
		numOfWheels = Object.numOfWheels;
		ptrColor = new char [strlen(Object.ptrColor) + 1];
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
		cout <<"Destructor" << endl;
		delete [] ptrColor;
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
	//Pointer address also copied
	//memory allocated to mini color is leaked
	//Copy constructor is not involved, assignment operator

	mini.DisplayAttributes();		//4, Red
	ambulance.DisplayAttributes();	//4, Red
	cout << endl;

	mini.ChangeColor("Blue");

	mini.DisplayAttributes();
	ambulance.DisplayAttributes();
	cout << endl;

	cin.get();
	return 0;
	
	/*
	 Destructor for ambulance is first called
	 Next the destructor of mini is called but the pointer pointed by the mini color is already destroyed.
	 Crash happens in this case along with memory leak.
	 To solve this operator overloading is required for '=' operator.
	 Assignment is a binary operator.
	*/	
}

/************************************Summary*****************************************
1. 
************************************************************************************/