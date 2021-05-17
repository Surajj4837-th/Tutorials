//Operator Overloading
#include "Header.h"

class MyClass
{
	int count;

public:
	//Default Constructor
	MyClass()
	{
	}

	MyClass(int cnt): count(cnt)
	{
	}

	int GetCount() const
	{
		return count;
	}

	//Operator function for prefix notation
	MyClass& operator++()
	{
		++count;
		cout << "Prefix Operator++()" << endl;

		return *this;
		/*
		 We have used this prefix operator to create an object in main function so
		 we are returning a reference to an object.
		*/
	}

	void operator++(int)		//x -> dummy argument just to differentiate the function definition
	{
		cout << "Postfix Operator++()" << endl;
		++count;
	}

};//End Of Class

int main()
{
	MyClass	Ob1(10);

	cout << Ob1.GetCount() << endl;

	//All following calls are valid
	++Ob1;		//compiler converts this command into a function call: Ob1.operator++();
	Ob1++;		//Gives warning/error if only prefix operator overloading is defined.
	Ob1.operator++();

	cout << Ob1.GetCount() << endl;
	
	MyClass Ob2;
	Ob2 = ++Ob1;
	/*
	Ob2 = Ob1.operator++()
	Here Ob1 calls the ++ operator hence 'this' pointer will point to Ob1 and the argument 
	members accessed in function will be of Ob1.	
	*/

	cout << Ob1.GetCount() << endl;
	cout << Ob2.GetCount() << endl;

	cin.get();
	return 0;
}

/************************************Summary*****************************************
1. Only existing operators like +, ++, /, etc. can be overloaded, no new operator can
   be created like +_, %$, etc and be used for overloading.

2. Number of operands an operators requires cannot be changed eg Ob1 ++ Ob2, not allowed.

3. Precedence of operators cannot be changed.

4. Some operators cannot be overloaded:
   - dot (.), this operator is already being used with class, so cannot be overloaded.
   - sizeof(), this also works with class
   - ::, already works with class
   - ->
   - Ternary operator(?:) cannot be overloaded.
   - typeid()

5. Type Casting Operators:
   C++ has 4 casting operators: reinterpret, static, const and dynamic cast are used 
   with classes and are not required to be overloaded.

6. Always define different functions for prefix and postfix notation.

7. C++ standard says that, the definition without the dummy parameter is used by prefix 
   notation and the definition with dummy parameter is used by postfix notation.

8. Operator functions are special fuction to whom the number of parameters to be passed
   cannot be user defined.

9. Unary operators are those which take only 1 variable/object as argument, example ++, --.

10. Binary operators are those which take 2 variable/object as argument, example +, -.

11. Prefix unary operator function takes no arguments whereas postfix unary operator 
	takes 1 argument i.e. dummy parameter to denote the function as postfix.

12. Operator new, new [], delete and delete[] can also be overloaded.

13. Why ternary operator cannot be overloaded?
	because it is a replacement for if else condition.

14. =, ->, [], () must be overloaded using non static member function of class. Why?
	Because when we try Obj1 = Obj2, it takes Obj2 as parameter but in case of static 
	functions, no parameters are passed.

15. () is called as function call operator.

16. Insertion (<<) and extraction (>>) operator must be overloaded as a friend because 
	it would be called without creating an object.

17. Operator overloading gives more flexibility to handle operations with user defined 
	data types.
************************************************************************************/