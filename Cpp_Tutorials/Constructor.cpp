//Use of constructor
#include "Header.h"

/****************Macro Declaration***********/

#define LEN					(12)

/********************************************/

class ToyCar
{						//PascalCase
	int numOfWheels;	//camelCase
	char color[LEN];

public:
	void InitializeCar(int num, const char* clr)
	{
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
	ToyCar mini;
	mini.InitializeCar(4, "White");

	ToyCar ambulance;
	ambulance.InitializeCar(4, "Red");

	ToyCar trailer;
	//trailer.InitializeCar(6, "Yellow");

	mini.DisplayAttributes();
	ambulance.DisplayAttributes();
	trailer.DisplayAttributes();
	
	cin.get();
	return 0;
}

/************************************Summary*****************************************
1. If we run this function we will get garbage values for the trailer object since 
   the developer forgot to initialise the attributes.

2. C++ provides a function which is called automatically when an object is created, 
   this does the work of initialization.
************************************************************************************/