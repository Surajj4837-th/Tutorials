// C++11/TypeCastingOperators.cpp
//Type casting operators in C++11
#include <iostream>

#define STATIC_CAST			0
#define DYNAMIC_CAST		0
#define CONST_CAST			0
#define REINTERPRET_CAST	0

using std::cout;
using std::endl;

#if STATIC_CAST


class Int
{
	int x;

public:
	Int(int x_in = 0)
		: x( x_in )
	{
		cout << "Conversion Ctor called" << endl;
	}
	operator string()
	{
		cout << "Conversion Operator" << endl;
		return to_string(x);
	}
};


class Base 
{
};

class Derived : public Base 
{
};


int main()
{
	//C type implicit casting
	float var1 = 9.2F;
	int var2 = var1;
	cout << var2 << endl;

	//static casting - similar to implicit casting in C.
	int var3 = static_cast<int>(var1);
	float var4 = static_cast<float>(var3);
	cout << var3 << endl;
	cout << var4 << endl;

	//-------------------type casting-------------------
	int a = 10;
    char c = 'a';
	int* q = (int*)&c;	
	//Possible to convert from a datatype to any other datatype but it is illigal.

	cout << *q << endl;

	//int* p = static_cast<int*>(&c);	
	//static cast - Casting from any datatype is not allowed as it might be a mistake by developer.



	//-------------------Converting object to and from a class-------------------
	Int obj(3);		//ctor is called

	string str = obj;		//Conversion Operator is called. No error as conversion operator is defined

	obj = 20;		//ctor is called

	string str2 = static_cast<string>(obj);		//Conversion Operator is called
	obj = static_cast<Int>(30);					//ctor is called


	//-------------------Inheritance casting-------------------
	Derived d1;

    Base* b1 = (Base*)(&d1);  //Address of d1 explicitly casted into Base and stored in b1.

    Base* b2 = static_cast<Base*>(&d1); //Address of d1, static_cast to cast into Base and stored in b2.

	

	//-------------------To and from void pointer-------------------
	int i = 10;

    void* v = static_cast<void*>(&i);
    
	int* ip = static_cast<int*>(v);
	
	cout << *ip << endl;


	std::cin.get();
	return 0;
}
#endif


#if DYNAMIC_CAST



// Base class declaration
class Base1 {
	void print()
	{
		cout << "Base" << endl;
	}
};

// Derived Class 1 declaration
class Derived1 : public Base1 {
	void print()
	{
		cout << "Derived1" << endl;
	}
};

// Derived class 2 declaration
class Derived2 : public Base1 {
	void print()
	{
		cout << "Derived2" << endl;
	}
};


// Base Class declaration
class Base2 {
    virtual void print()
    {
        cout << "Base" << endl;
    }
};
  
// Derived1 class declaration
class Derived3 : public Base2 {
    void print()
    {
        cout << "Derived1" << endl;
    }
};
  
// Derived2 class declaration
class Derived4 : public Base2 {
    void print()
    {
        cout << "Derived2" << endl;
    }
};


int main()
{
	Derived1 d1;

	//---------------------------------C++ program demonstrate if there is no virtual function used in the Base class---------------------------------
	// Base class pointer hold Derived1 class object
	Base1* bp1 = dynamic_cast<Base1*>(&d1);

	// Dynamic casting throws error
	//Derived2* dp2 = dynamic_cast<Derived2*>(bp1);


	//---------------------------------Dynamic_casting returning new_type---------------------------------

	Derived3 d3;
  
    // Base class pointer holding Derived3 Class object
    Base2* bp2 = dynamic_cast<Base2*>(&d3);

    Derived3* dp3 = dynamic_cast<Derived3*>(bp2);

    if (dp3 == nullptr)
        cout << "null" << endl;
    else
        cout << "not null" << endl;


	return 0;
}


#endif


#if CONST_CAST


class student
{

private:
	int roll;

public:
	// constructor
	student(int r):roll(r) {}

	// A const function that changes roll with the help of const_cast
	void fun() const
	{
		( const_cast <student*> (this) )->roll = 5;
	}

	/*
	void fun(int num) const
	{
		//error: cannot be modified because it is being accessed through a const object
		this->roll = 5;
	}*/

	int getRoll() { return roll; }
};

int fun(int* ptr)
{
    return (*ptr + 10);
}

int main(void)
{
	student s(3);
	cout << "Old roll number: " << s.getRoll() << endl;

	s.fun();

	cout << "New roll number: " << s.getRoll() << endl;

	//---------------------Passing const var to as non-const parameter---------------------
	//Passing const data to a function which receives non-const parameter
	const int val = 10;
    const int *ptr = &val;
    //cout << fun(ptr);		//error: Cannot convert parameter from const int to int

	//const cast will resolve this issue
    int *ptr1 = const_cast <int *>(ptr);
    cout << fun(ptr1) << endl;		
	//Updating the const declared variable will be undefined behavior.
	//It is fine to modify a value which is not initially declared as const.


	//---------------------Safe to use const---------------------
	char* c1 = (char *) (val); //Dangerous conversion
	//char* c1 = const_cast <char *> (val); 
	// compiler error: a const_cast can only adjust type qualifiers; 
	//it cannot change the underlying type.


	//---------------------Cast away volatile attribute---------------------
	int a1 = 40;
    const volatile int* b1 = &a1;
    cout << "typeid of b1 " << typeid(b1).name() << '\n';
    int* c1 = const_cast <int *> (b1);
    cout << "typeid of c1 " << typeid(c1).name() << '\n';


	return 0;
}

#endif

#if REINTERPRET_CAST

using namespace std;
 
struct mystruct {
	int x;
	int y;
	char c;
	bool b;
};

class A 
{
public:
    void fun_a()
    {
        cout << " In class A\n";
    }
};
 
class B 
{
public:
    void fun_b()
    {
        cout << " In class B\n";
    }
};
 
int main()
{
    int* p = new int(65);
    char* ch = reinterpret_cast<char*>(p);
    cout << *p << endl;		//Output: 65
    cout << *ch << endl;	//Output: A
    cout << p << endl;		//Output: address of p
    cout << ch << endl;		//Output: A


	//------------------------casting of structure------------------------
	mystruct s;

	// Assigning values
	s.x = 5;
	s.y = 10;
	s.c = 'a';
	s.b = true;

	// data type must be same during casting
	// as that of original

	// converting the pointer of 's' to,
	// pointer of int type in 'p'.
	int* p = reinterpret_cast<int*>(&s);	//&s points to first variable in structure

	cout << sizeof(s) << endl;

	// printing the value currently pointed by *p
	cout << *p << endl;

	// incrementing the pointer by 1
	p++;

	// printing the next integer value
	cout << *p << endl;

	p++;

	// we are casting back char * pointed
	// by p using char *ch.
	char* ch = reinterpret_cast<char*>(p);

	// printing the character value
	// pointed by (*ch)
	cout << *ch << endl;

	ch++;

	/* since, (*ch) now points to boolean value,
	so it is required to access the value using
	same type conversion.so, we have used
	data type of *n to be bool. */

	bool* n = reinterpret_cast<bool*>(ch);
	cout << *n << endl;

	// we can also use this line of code to
	// print the value pointed by (*ch).
	cout << *(reinterpret_cast<bool*>(ch));

	//------------------------casting of class------------------------

	// creating object of class B
    B* x = new B();
 
    // converting the pointer to object
    // referenced of class B to class A
    A* new_a = reinterpret_cast<A*>(x);
 
    // accessing the function of class A
    new_a->fun_a();		//Output: In class A

    return 0;
}

#endif

/************************************Summary*****************************************
1. A Cast operator is an unary operator which forces one data type to be converted into 
   another data type.

2. Static cast - Is is the simplest cast done at compile time. It performs tight type checking.

3. It is possible to convert from any datatype to any other data type but this is illigal.
   To avoid this the static_cast does not allow these kind of castings.

4. Dynamic casting is mainly used for safe downcasting at run time.

5. To work on dynamic_cast there must be one virtual function in the base class. A 
   dynamic_cast works only polymorphic base class because it uses this information to 
   decide safe downcasting. If there is no virtual function then the compiler throws an
   error: �Source type is not polymorphic�.

6. Downcasting: Casting a base class pointer (or reference) to a derived class pointer 
   (or reference) is known as downcasting.

7. Upcasting: Casting a derived class pointer (or reference) to a base class pointer 
   (or reference) is known as upcasting.

8. If dynamic_cast is successful, it returns a value of type new_type.

9. const_cast is used to cast away the constness of variables.

10. const_cast can be used to change non-const class members inside a const member function.

11. const_cast can be used to pass const data to a function that doesn�t receive const.
	
12.	It is fine to modify a value which is not initially declared as const. However 
	updating the variable that is declared as const will lead to undefined behavior.

13. const_cast is considered safer than simple type casting. It�s safer in the sense 
	that the casting won�t happen if the type of cast is not same as original object.

14. const_cast can also be used to cast away volatile attribute.

15. reinterpret_cast is used to convert a pointer of some data type into a pointer of 
	another data type, even if the data types before and after conversion are different.
	It does not check if the pointer type and data pointed by the pointer is same or not.

16. Reinterpret_cast takes on ly 1 parameter, the source pointer variable and returns 
	nothing. It simply converts the pointer type.

17. reinterpret_cast is a very special and dangerous type of casting operator. And is 
	suggested to use it using proper data type i.e. pointer data type should be same 
	as original data type.

18. reinterpret_cast is used when we want to work with bits.

19. reinterpret_cast creates non-portable codesince some machines use big endian and 
	other use little endian memory storage format.
************************************************************************************/