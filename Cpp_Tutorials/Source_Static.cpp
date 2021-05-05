//Use of Static data members
//Static local variables in a function are initialised 
//only once and remain alive even after loop ends.
#include"Header.h"

#if 1		//Bank Alpplication

class BankCustomer{
private:
	int AcntNum;
	double amount;
	int time;
	static double ROI;

public:

	BankCustomer(int num = 0, double amt = 0, int tim = 0)
	{
		AcntNum = num;
		amount = amt;
		time = tim;
	}

	void CalculateSum()
	{
		cout << "Total Sum = " << amount + (amount*ROI*time/100) << endl;		
	}

	static void ChangeRate(double NewROI);
};

void BankCustomer::ChangeRate(double NewROI)
{
	ROI = NewROI;
}


double BankCustomer:: ROI = 8.5;

int main()
{
	BankCustomer	C1(1001, 10000, 2);
	BankCustomer	C2(1002, 20000, 3);

	C1.CalculateSum();
	C2.CalculateSum();

	BankCustomer::ChangeRate(9.0);

	C1.CalculateSum();
	C2.CalculateSum();

	cin.get();

	return 0;
}
#else			//Basic examples
class MyClass
{

public:
	//member declaration
	int a;
	static int b;
	
};//End of class

int MyClass ::b;

int main()
{
	MyClass Obj1;
	MyClass Obj2;

	cout << sizeof(Obj1) << "\t" <<sizeof(Obj2) <<endl;	
	//Each has 8 bytes of memory if b is not static

	Obj1.a = 1;
	Obj1.b = 2;

	Obj2.a = 3;
	Obj2.b = 4;

	cout << Obj1.b << "\t" << Obj2.b << endl;

	cin.get();

	return 0;
}
#endif
/************************************Summary*****************************************
1. If you declare a data member static, developer need to provide an explicit definition
   outside the class, if not done then compiler gives error.

2. Static data member's memory is not considered in the total size of the object.

3. Static data members is shared by all the objects of the class, if 1 object changes it,
   it is changed for all other objects of same class.

4. The data member which is static is created only once. It is not the part of object's 
   memory.

5. Static data is shared by objects but its memory is contributed by any of the objects.

6. Variable declaration does not allocate memory but definition does. It is the responsibility 
   of developer to define the static data member outside the class. Initial value is by
   default 0.

7. Static members are generally used as counters as it is shared and can be incremented
   when a new object is created and decremented when the object is destroyed.

8. What happens when a static data member is declared but not defined? 
   Linker error -> Unresolved external symbol.

9. Static data members can be accessed before creating any objects as the static data 
   members are independent of objects. Static data members are created even before objects.

10. Another use of static data member is to save a data which is common to all and when 
	changed should affect all ibjects, example interest of bank.

11. If there is a case where the objects of a class share a data, then that data member
	should be declared static.

12. In the case of bank application, ROI is a static member. It's value may change and 
	is not object dependent. Any functionwhich is independent of the obects should be 
	defined as static.

13. The function which changes the value of static variable should be a static function
	or the static data members should be operated only through static functions.

14. As the ststic function is object independent then how to call a static function?
	It can be called through scope resolution operator.

15. Since the static member functions are not called through an object, they do not
	receive any object pointer(this).

16. Since the static member function do not get any object address, they cannot access 
	any non-static member function.

17. A non-static member function can call a static member function inside it. But a 
	static member function cannot call a non-static member function as the static function 
	does not have any object reference.
************************************************************************************/