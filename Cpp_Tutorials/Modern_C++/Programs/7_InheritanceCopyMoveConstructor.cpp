// Copy constructor and operator=
#include <iostream>

using namespace std;

class Base 
{

private:
	int value;

public:
	Base() : value{ 0 }
	{
		cout << "Base no-args constructor" << endl;
	}

	Base(int x)	: value{ x }
	{
		cout << "Base parameterized constructor" << endl;
	}
	Base(const Base& other) : value{ other.value }
	{
		// other will be provided by the derived class copy constructor
		// The data has to be copied from the base part of the derived object as done below
		// Slicing happens here, the other is a derived object but once it is passed 
		// to the base class, the derived part is sliced off and only the base part remains

		cout << "Base copy constructor" << endl;
	}

	Base& operator=(const Base& rhs)	//Base class copy constructor
	{
		// rhs will be provided by the derived class copy constructor
		// The data has to be copied from the base part of the derived object as done below
		// Slicing happens here, the rhs is a derived object but once it is passed to the base class
		// the derived part is sliced off and only the base part remains

		cout << "Base operator=" << endl;
		if (this == &rhs)
			return *this;

		value = rhs.value;
		return *this;
	}

	~Base() 
	{ 
		cout << "Base destructor" << endl; 
	}
};

class Derived : public Base 
{

private:
	int doubled_value;

public:
	Derived() :	Base{} 
	{
		cout << "Derived no-args constructor " << endl;
	}

	Derived(int x) : Base{ x }, doubled_value{ x * 2 } 
	{
		cout << "Derived parameterized constructor" << endl;
	}

	Derived(const Derived& other)			//Derived class copy constructor
		: Base(other), doubled_value{ other.doubled_value }		// Base class copy constructor is invoked
	{
		cout << "Derived copy constructor" << endl;
	}

	Derived& operator=(const Derived& rhs) 
	{
		cout << "Derived operator=" << endl;
		if (this == &rhs)
			return *this;

		Base::operator=(rhs);
		//Slicing: Invoke the base class copy assignment operator with the derived object

		doubled_value = rhs.doubled_value;
		return *this;
	}

	~Derived() 
	{ 
		cout << "Derived destructor " << endl; 
	}
};


int main() 
{
	Base b {100};   	// Overloaded constructor
	Base b1 {b};    	// Copy constructor
	b = b1;         	// Copy assignment

	Derived d{ 100 };    // Overloaded constructor
	Derived d1{ d };     // Copy constructor
	d = d1;              // Copy assignment

	return 0;
}

/************************************Summary****************************************
1. Copy and move constructors are not inherited from base class. We can explicitly
   invoke the Base class versions from the Derived class

2. If there is a need of derived object copy constructor then there will be need of
   base class copy constructor as well to copy the base object.

3. When a derived class copy constructor is invoked the same object has to be passed
   to the base class copy constructor. Then in the base class copy constructor the base
   part of the derived object is to be copied.

4. In case of the copy assignment operator, the base class version can be invoked
   from the derived class version.

5. The derived class copy assignment operator will be invoked when a derived
   object is assigned to another derived object.

6. The derived class copy assignment operator will invoke the base class copy assignment
   operator to copy the base part of the derived object. This is called slicing.

7. Often we do not need to write copy and move constructors and assignment operators.
   If we do not write them the compiler will generate default versions for us.

8. The compiler generated versions will perform a shallow copy or move of the
   object. This is often sufficient. If the class has raw pointers or other resources
   that need to be deep copied or moved then we need to write our own versions.

9. If the derived class has copy/move constructors or assignment operators then
   the base class must have them as well.

10. If the base class does not have copy/move constructors or assignment operators
	then the derived class cannot have them as well.

11. If the base class versions are deleted or private then the derived class
	versions will be deleted as well.

12. If the base class versions are defaulted then the derived class versions will be
	defaulted as well.

13. A derived class object can be assigned or copied to a base class object, but object 
 	slicing will occur. Only the base part of the derived object is copied; any additional 
	members in the derived class object are lost.
***********************************************************************************/