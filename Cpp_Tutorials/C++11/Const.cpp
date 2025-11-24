//Use of const data members and const member functions in a class
//Also demonstration of static member variables and static member functions

#include <iostream>

using std::cout;
using std::endl;

class BankCustomer{

private:
	const int AcntNum;
	double amount;
	int time;
	static double ROI;

	/*
	When the member variables are declared with a static keyword in a class, then it is known 
	as static member variables. They can be accessed by all the instances of a class, not with 
	a specific instance.
	Static member variables are member variables that belong to the class rather than objects 
	of the class.
	*/

public:

	/*
	The constants which are used only by the class are called class specific constants
	and are not required to be declared global as they will be accessed by anyone.
	Class specific constants are declared under public specifier.
	Good alternative to global variable.
	Even though it is static, it is not required to define it outside the class.
	Making it const will not change its value and making it static will keep the variable shared.
	*/
	const static int LengthOfAcntNum = 4;

	//Constructor
	BankCustomer(int num = 0, double amt = 0, int tim = 0): AcntNum(num), amount(amt)
	{
		//AcntNum = num;
		/*Invalid command for const variables.
		 To initialize the const value using constructor, we have to use the initializer list.*/

		//amount = amt;			//non-const data member can be initialized anywhere
		time = tim;
	}

	void CalculateSum()
	{
		cout << "Total Sum = " << amount + (amount*ROI*time/100) << endl;		
	}

	static void ChangeRate(double NewROI);
	void Withdraw(double amt);
	void DisplayBalance()const;
};

void BankCustomer::Withdraw(double amt)
{
	amount -= amt;
}

void BankCustomer::DisplayBalance() const
{
	cout << "Your Balance" << amount << endl;

	//amount -= 100;//Mistake by developer
	//const functions do not allow data manipulation
}

void BankCustomer::ChangeRate(double NewROI)
{
	ROI = NewROI;
}

double BankCustomer:: ROI = 8.5;

//Another Class

class Trainee
{
	mutable int marks;
	int roll;

public:
	Trainee(int r, int m):roll(r), marks(m)
	{
		marks = m;
	}

	void display() const
	{
		cout << roll << "\t" << marks << endl;
	}

	void change_marks(int m);
};

void Trainee::change_marks(int m)
{
	marks = m;
}

int main()
{
	BankCustomer::ChangeRate(7.0);

	BankCustomer C1(1001, 10000, 2);

	C1.ChangeRate(2.0);

	C1.CalculateSum();

	const Trainee T1(1001, 30);

	T1.display();
	//T1.change_marks(4);		// Not allowed to update the values as the object is const



	int a = 10;
	const int b = 20;	//const is preferred before data type

	/*
	Invalid operations: const value has to be initialized during declaration.
	const int c;
	c = a;
	b = a;*/

	int d{10};	//compile time const
	int e = d + a;	//run time const

	constexpr int f = 11; //constexpr inform compiler to resolve this at compile time.
	

}
/************************************Summary*****************************************
1. const variables should be initialized in declaration itself and definition is compulsory.

2. const variables remain constant throughout its life time.

3. The data which remains constant throughout the life of an object can be assigned as
   const variable, example the account number of an object.

4. The data member which is const cannot be initialized in a normal way in a constructor.
   It will be initialized in a constructor definition before start of loop in initializer 
   list. This method of initialization can also be used by non-const members as well.

5. When a function is not expected to change the values of any data member then it 
   should be declared const function.

6. For a const function the keyword 'const' should be used in declaration as well as
   in definition.

7. When an object is declared as const, all its data becomes const automatically.

8. const object can invoke only const member functions because the data is already const
   and a member function is not allowed to change the data of a const object.

9. But in case there is a requirement of updating the value of a data member of a const 
   object, C++ alllows this exception by using a special keyword - mutable.

10. A mutable member function of a const object can be updated.

11. By declaring a function member as static, you make it independent of any particular 
	object of the class. A static member function can be called even if no objects of 
	the class exist and the static functions are accessed using only the class name and 
	the scope resolution operator ::.

12. static member functions can directly access other static members (variables or functions), 
	but not non-static members. This is because non-static members must belong to a class 
	object, and static member functions have no class object to work with.

13. static function of a class is not associated with any class object. So, THIS pointer 
	is not passed to a static function as an internal parameter. So, a static function 
	does not understand THIS pointer inside its body.

14. const variables are prefixed with k or written in caps.

15. constexpr is used to declare the const variables which are compile time constants.
	This helps in optimization.
************************************************************************************/