//= operator overloading and string copy
#include <iostream>

using std::cout;
using std::endl;

/****************Macro Declaration***********/

#define LEN					(12)

/********************************************/

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

	void DisplayAttributes()
	{
		cout << numOfWheels << endl;
		cout << ptrColor << endl;
	}

	void ChangeColor(const char* clr)
	{
		//strcpy(ptrColor, clr);
		/*
		This will cause error if the memory available is less in ptrColor.
		Example if the earlier string was "Red", new string -> "White".
		More meory is required.
		To solve this deallocate the earlier memory and reallocate a new memory as per requirement.
		*/

		delete [] ptrColor;
		ptrColor = new char [strlen(clr) + 1];
		strcpy(this->ptrColor, clr);
	}

	~ToyCar()
	{
		cout <<"Destructor" << endl;
		delete [] ptrColor;
	}

	ToyCar operator=(const ToyCar& Ob)
	{
		if(this != &Ob)	//Why to copy data if both objects sre same
		{
			this->numOfWheels = Ob.numOfWheels;
			/*strcpy(this->ptrColor, Ob.ptrColor);

			This will cause error if the memory available is less in ptrColor.
			Example if the earlier string was "Red", new string -> "White".
			More meory is required.
			To solve this deallocate the earlier memory and reallocate a new memory as per requirement.
			*/

			delete [] ptrColor;
			ptrColor = new char [strlen(Ob.ptrColor) + 1];
			strcpy(this->ptrColor, Ob.ptrColor);
		}

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

	mini.DisplayAttributes();		//4, Red
	ambulance.DisplayAttributes();	//4, Red
	cout << endl;

	mini.ChangeColor("Blue");

	mini.DisplayAttributes();
	ambulance.DisplayAttributes();
	cout << endl;

	cin.get();
	return 0;
}

/************************************Summary*****************************************
1. When we copy a string to a class pointer variable then the memory should be deleted 
   first, after that a new memory should be created of the size of new string and then
   string copy can be done, otherwise there happens a crash.

2. In case of DMA following things should be defined:
   a. Copy constructor
   b. Destructor
   c. Assignment operator 
************************************************************************************/