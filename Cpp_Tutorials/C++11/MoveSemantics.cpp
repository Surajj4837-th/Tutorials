#if 0
//Move semantics

#include <iostream>
#include <string.h>

using namespace std;

class String
{

	int size;
	char *name;

public:
	//Parameterized Constructor
	String (char *Name)
	{
		cout <<"\nParameterized Constructor" << endl;
		name = new char[strlen(Name) + 1];
		strcpy(name, Name);
	}

	//Default Constructor
	String()
	{
		cout <<"\nDefault Constructor" << endl;
		strcpy(name, "Default");
	}


	//Move constructor
	String(String&& obj)
	{
		cout <<"\nMove Constructor" << endl;
		name = new char[strlen(obj.name) + 1];
		name = obj.name;

		obj.name = nullptr;		//This is necessary step, as the address is copid to new object
	}

	//Copy constructor: allocate and 
	String(const String& obj)
	{
		cout <<"\nCopy Constructor" << endl;
		name = new char[strlen(obj.name) + 1];
		strcpy(name, obj.name);
	}


	//Destructor
	~String()
	{
		name = nullptr;
		size = 0;
	}

	printName()
	{
		cout << name << endl;
	}

};


class Class1
{	
	string name;

public:

	//Parameterized ctor
	Class1(string nm): name(nm)
	{
		cout <<"\nClass1 Parameterized Constructor" << endl;
	}

	//move ctor
	Class1(string&& other): name(std::move(other))
	{
		cout <<"\nClass1 Move Constructor" << endl;
	}

	//copy ctor
	Class1(string& other): name(other)
	{
		cout <<"\nClass1 Copy Constructor" << endl;
	}
	
};


class Class2
{
	
public:

	Class1 class1_obj;

	//Parameterized ctor
	Class2(Class1 param): class1_obj(param)
	{
		cout <<"\nClass2 Parameterized Constructor" << endl;
	}

	//move ctor
	Class2(Class1&& param): class1_obj(std::move(param))
	{
		cout <<"\nClass2 Move Constructor" << endl;
	}

	//Copy ctor
	Class2(Class1& param): class1_obj(param)
	{
		cout <<"\nClass2 Copy Constructor" << endl;
	}
	
};


int main()
{
	//char name[6] = "Suraj";
	//String obj1;				//Default ctor
	//String obj2(name);			//Parameterized ctor
	//String obj3(obj2);			//Copy ctor
	//String obj4(move(obj2));	//Move ctor

	//obj1.printName();
	//obj2.printName();
	//obj3.printName();
	//obj4.printName();

	cout << endl << "Object calling object example:" << endl;
	string obj7("Suraj");
	Class1 obj6(obj7);
	//Class2 obj5(move(obj6));

	return 0;
}

#endif

//Move semantics

#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
using std::string;


class Class1
{	
	string name;

public:

	//Parameterized ctor
	Class1(string& nm): name(nm)
	{
		cout <<"\nClass1 Parameterized Constructor" << endl;
	}

	//move ctor
	Class1(string&& other): name(std::move(other))
	{
		cout <<"\nClass1 Move Constructor" << endl;
	}

	
};


class Class2
{

	Class1 class1_obj;

public:

	//parameterized ctor
	/*Class2(Class1 param): class1_obj(std::move(param))
	{
		cout <<"\nParameterized Constructor" << endl;
	}
	//This is illigal since the compiler cannot dishtinguish between this and the move ctor.
	*/

	//copy ctor
	Class2(Class1& param): class1_obj(param)
	{
		cout <<"\nClass2 copy Constructor" << endl;
	}

	//move ctor
	Class2(Class1&& param): class1_obj(std::move(param))
	{
		cout <<"\nClass2 Move Constructor" << endl;
	}
	
};


int main()
{
	string obj7("Suraj");
	Class1 obj6(obj7);
	Class2 obj5(move(obj6));

	return 0;
}

/************************************Summary*****************************************
1. Move semantics relies on rvalue references.

2. A move constructor, unlike a copy constructor, can avoid memory reallocation, so 
   rather than copying the fields of the object, we will move them.

3. If the field is a primitive type, like int, we just copy it. If the field is a pointer,
   rather than allocate and initialize new memory, we can simply move the pointer and 
   null out the pointer in the temporary object.

4. The pointers in the object to be moved are assigned NULL after moving so it is neccesary
   to not declare the pointers or the object as const.

5. std::move does not, in and of itself, move anything; it just turns an lvalue into an 
   rvalue, so that you can invoke the move constructor.

6. If a class uses other class and initializes it in a constructor then use std::move in
   move ctor to initialize other class else it will call the copy ctor.

7. According to the rules the class function declaration with same parameters in a 
   parameterized ctor and a rvalue-reference (move) ctor is illigal. Compiler cannot 
   dishtinguish between same parameters for following cases:
		int and int &&
		int and const int &&
   datatypes can be anything.
   Between int&& and const int& declaration the int&& is better.

8. Returning a value from a function is not rvalue return, the value is copied while returning.

9. rvalue reference can also be returned from a function provided it should not be a 
   local variable.

10. If you enable move semantics in your own objects by creating move assignment operators 
	and move constructors, when you store those objects in a container, the STL will 
	automatically use std::move, automatically taking advantage of move-enabled classes 
	to eliminate inefficient copies.
************************************************************************************/