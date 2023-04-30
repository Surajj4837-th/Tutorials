//Use of Copy Constructor and Destructor
#include <string.h>
#include "Header.h"

/****************Macro Declaration***********/

#define LEN					(12)
#define ACTIVATE_COPY_CONSTRUCTOR					1
#define ACTIVATE_COMPILER_COPY_CONSTRUCTOR			0

/********************************************/

class ToyCar			//PascalCase
{			
	int numOfWheels;	//camelCase
	//char color[LEN];	//1 byte consumed by '/0' in the end
	
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
	

#if ACTIVATE_COMPILER_COPY_CONSTRUCTOR
	ToyCar(const ToyCar& Object) = delete;
	//Above statement can be used to avoid creation of default 
	//copy constructor created by compiler.
#endif


#if ACTIVATE_COPY_CONSTRUCTOR	//Copy constructor
	//Copy Constructor
	ToyCar(const ToyCar& Object)		//Reference is made constant to avoid any chages to it.
	{
		cout <<"\nCopy Constructor" << endl;
		numOfWheels = Object.numOfWheels;
		ptrColor = new char [strlen(Object.ptrColor) + 1];
		//strlen does not count '/0' present in the end of string
		strcpy(ptrColor, Object.ptrColor);		
		
		/*
		ptrColor = Object.ptrColor;
		This was done by compiler instead of above command.
		*/
	}
#endif

	void DisplayAttributes()
	{
		cout << numOfWheels << endl;
		cout << ptrColor << endl;
	}

	void ChangeColor(const char* clr)
	{
		strcpy(ptrColor, clr);
	}

	/*
	void ReleaseMemory()
	{
		delete [] ptrColor;
	}
	
	This function releases the allocated memory.
	But in this case developer has to know what all objects are
	defined in a funtion and call this function wherever the work ends.
	This can be solved by using destructor which is called
	automatically when an objects life ends.
	*/

	~ToyCar()
	{
		cout <<"Destructor" << endl;

		delete [] ptrColor;
	}

};	//End of class

void DoSomething()
{
	ToyCar	maruti3(4, "Blue");
	maruti3.DisplayAttributes();

	/*
	When the loop ends the object maruti3 is destroyed.
	But the memory allocated for color object on heap is not destroyed and
	remains out of control after the loop ends.
	If this function is called multiple times, it will result in large memory leak.
	*/

	/*
	delete [] maruti3.ptrColor;
	DoSomething is a global function and the object maruti3 is accessing a private
	data directly outside the class.
	*/

	//maruti3.ReleaseMemory();
}

int main()
{
	ToyCar maruti;				//Default constructor invoked
	ToyCar maruti2 = maruti;	//Copy constructor invoked
	//Another syntax for above statement
	//ToyCar maruti2(maruti);
	maruti2.DisplayAttributes();

	ToyCar maruti3;				//Default constructor invoked

	//Here all data is copied.
	//Compiler is not intelligent and it will copy all data
	//from maruti to maruti2 implicitly. It copies int and the pointer data as well.
	//Thus both objects point to same the location.
	//This problem is called as "shallow copy".
	//This can be resolved by having a copy constructor and deep copying the data explicitly.
	
	maruti.DisplayAttributes();		//4 White
	maruti2.DisplayAttributes();	//4 White

	maruti.ChangeColor("Red");

	cout << "\nAfter changing color:" << endl;

	maruti.DisplayAttributes();		//Changes done on maruti are		4 Red
	maruti2.DisplayAttributes();	//reflected on maruti2 as well		4 Red
									//if copy constructor is not used.

	maruti3 = maruti;				//Assignment command, does not call copy constructor
									//results in shallow copy unless operator overloading
									//is implemented with deep copy.
	maruti3.DisplayAttributes();

	//Call a function
	DoSomething();

	cin.get();
	return 0;
}	

/************************************Summary*****************************************
1. No constructor invoked for maruti2. Compiler writes a constructor of its own called
   as copy constructor and copies the content from maruti.

2. If objects involve pointer variables then not writing a copy constructor will result
   in shallow copy problem.

3. Developer should write copy constructor in case the object involves a pointer variable.

4. Defining a copy constructor explicitly introduces deep copy and care should be taken 
   while copying a data pointed by pointer.

5. To avoid any changes being done to the passed object as parameter of a copy constructor,
   the object reference should be made as constant.

6. If an object has dynamically allocated memory then it is compulsory to deallocate it,
   to avoid memory leaky.

7. Destructor is called whenever an object goes out of that scope.

8. Destructor does not take any parameters and has no return type.

9. There cannot be more than 1 destructor in the class.

10. Destructor cannot be inherited.

11. When a copy constructor is invoked?
	a. When an object is created and initialized by an existing object.
	b. When an object is passed by value to a function.
	c. When an object is returned from a function.
	d. When an object is inserted into a STL container.
	e. When a STL container is declared with more than one object.

12. Object passing by value is allowed but it should be avoided as it involves copy 
	constructor and data copy, which is costly task. Instead pass the object by reference.

13. Common misconception: Constructor is used for allocating and destructor is for
	deallocating memory. The task of both is not just to manage memory but other resources 
	as well for example: the files once opened can be closed by using destructor. Similarly
	other resources like shared memory, socket(unix), etc.

14. The objects in a function are saved in stack and thus while destroying also they
    are destroyed in FILO fashion.

15. To restrict compiler from creating default copy constructor, delete keyword is used.
	See Explicitly Defaulted and Deleted Functions in C++ 11.
	Note: Need to create a separate file for this.
	https://www.geeksforgeeks.org/explicitly-defaulted-deleted-functions-c-11/

************************************************************************************/