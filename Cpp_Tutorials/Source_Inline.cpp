//Use of Inline
#include "Header_Constructor1.h"

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

	inline void DisplayAttributes();

};	//End of class

void ToyCar:: DisplayAttributes()
	{
		cout << numOfWheels << endl;
		cout << color << endl;
	}

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
1. When a function is called the compiler stores following information:
    a. The data of the variables in the present function.
	b. The next instruction to be executed after returning from the function.

2. Inline functions save time of CPU, thus increasing speed of program. It is similar 
   to a preprocessor directive.

3. When the compiler sees the declaration of an inline function, it replaces all the 
   instances of the function call with the fuction definition.

4. Care should be taken while declaring the function inline:
	a. If the number of lines of the function are more and it is called multiple times 
	   then it will result in increase in the size of code.
	b. If a function has more number of parameters then declaring it inline will cause
	   those paramaters to become local parameters of the parent function in which the 
	   inline function is called and these will remain present till the scope of the 
	   parent function.
	c. Inline recursive functions increase lot of object size and create lot of local
	   parameters.

5. Inline is not an order to the compiler but is a request. There are no guidelines 
   by which the function should be accepted as inline or not.

6. Whichever functions defined in the class are automatically made inline. Thus big
   functions should be defined outside to avoid automatically being declared inline.

7. How to verify if the function is made inline or not? By comparing the size of executable 
   generated when function is declared as inline and otherwise.
************************************************************************************/