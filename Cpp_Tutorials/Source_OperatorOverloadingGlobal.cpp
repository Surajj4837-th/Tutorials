//Global operator function
#include "Header.h"

class MyClass
{
	int count;

public:
	//Default Constructor
	MyClass():count(0)
	{
		//count = 0;
	}

	explicit MyClass(int cnt): count(cnt)
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
	}

	MyClass& operator++(int x)		//x -> dummy argument just to differentiate the function definition
	{
		cout << "Postfix Operator++()" << endl;
		++count;

		return *this;
	}

	friend MyClass& operator--(MyClass &ob);				//Prefix declaration
	friend MyClass& operator--(MyClass &ob, int dummy);		//Postfix declaration

};//End Of Class

//Global prefix operator function as a friend
MyClass& operator--(MyClass &ob)
{
	cout << "Prefix Operator--()" << endl;
	--ob.count;

	return ob;
}

//Global postfix operator function as a friend
MyClass& operator--(MyClass &ob, int dummy)
{
	cout << "Postfix Operator--()" << endl;
	--ob.count;

	return ob;
}

int main()
{
	MyClass Ob1(10);

	--Ob1;
	/*
		If the operator function was declared as a member function then the call would have been converted as
		Ob1.operator--();

		But now as the operator is a global funtion then the call will be converted as
		operator--(Ob1);
	*/

	cout<< Ob1.GetCount() << endl;

	MyClass Ob2;
	 
	Ob2 = --Ob1;

	cin.get();
	return 0;
}
/************************************Summary*****************************************
1. 
************************************************************************************/