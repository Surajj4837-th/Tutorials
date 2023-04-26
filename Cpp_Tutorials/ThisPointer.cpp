//Use of this pointer

#include"Header.h"

class Counter
{
protected:
	int numOfEvents;

public:
	//Default Constructor
	Counter()
	{
		numOfEvents = 0;
	}

	//Parameterized Constructor
	Counter(int numOfEvents)
	{
		//numOfEvents = numOfEvents;	//Compiler cannot differentiate here and no error is thrown
		this->numOfEvents = numOfEvents;
	}

	void CountUp()
	{
		++numOfEvents;
	}

	Counter CountDown()
	{
		++numOfEvents;

		return *this;
	}

	int  GetNumOfEvents()
	{
		return numOfEvents;
	}

};//End of class

int main()
{
	Counter C1;

	C1.CountUp();
	C1.CountUp();

	cout << C1.GetNumOfEvents()<< endl;

	Counter C2;
	cout << C2.GetNumOfEvents()<< endl;
	  
	Counter C3(10);		//Call parameterized constructor

	Counter C4;
	C4 = C1.CountDown();	//Use of tis pointer
							//Due to this pointer the command here become
							//C4 = C1 after decrementing the count of C1

	cout << C1.CountDown().GetNumOfEvents() << endl;	//this pointer makes this concatenation possible

	cin.get();
	return 0;
}

/************************************Summary*****************************************
1. How does the member function know which object has invoked it?
   When a function is invoked the address of the object is implicitly passed to the
   function. The address of the  object is stored in 'this' pointer.

2. We can use 'this' pointer explicitly as well.

3. Many developers keep the parameter name same as the name of data member, this creates 
   ambiguity, but the compiler does not throw any error. Here we can use this pointer 
   to differentiate between data member and the passed parameter.

4. Due to this pointer an invoking object can be returned from a member function.

5. this pointer allows use of function concatenation.
************************************************************************************/