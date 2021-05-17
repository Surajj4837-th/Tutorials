#//Stack implementation using Class

#include"Header_Class.h"

class Counter
{
protected:
	int count;

public:

	Counter()
	{
		cout << "Counter()" << endl;
		count = 0;
	}

	Counter(int c)
	{
		cout << "Parameterized Counter()" << endl;
		count = c;
	}

	~Counter()
	{
		cout << "~Counter()" << endl;
	}

	/*void initializer(int cnt = 0)
	{
		count = cnt;
	}*/

	void DoCountUp()
	{
		++count;
	}

	int getCount() const
	{
		return count;
	}

}; //End of Class

class DownCounter : public Counter		//mode of inheritance
{
	int Id;

public:

	DownCounter()
	{
		cout << "Downcounter()" << endl;
		Id = 0;
	}

	DownCounter(int id, int cnt) : Counter(cnt)		//syntax for calling base parameterized constructor
	{
		cout << "Parameterized Downcounter()" << endl;
		Id = Id;
		//count = cnt;
		//Better practice here is to call the parameterized constructor of base class
		//because anyhow constructor of base is going to be called.
	}

	~DownCounter()
	{
		cout << "~Downcounter()" << endl;
	}

	void DoCountDown()
	{
		--count;
	}

	/*void InitializeId(int i)
	{
		Id = i;
	}*/

	void Display() const
	{
		cout << Id << " - " << count << endl;
	}
};	//End of class

int main()
{
	DownCounter D1(1001, 100);
	cout << D1.getCount() << endl;

#if 0
	cout << sizeof(D1) << endl;

	D1.InitializeId(1001);
	D1.initializer(10);		//Cannot access count here to initialize it.

	cout << D1.getCount() << endl;

	D1.DoCountDown();
	cout << D1.getCount() << endl;
#endif

	return 0;
	cin.get();

}
/************************************Summary****************************************
1. Size of derived class includes memory for base class.

2. Private members cannot be accessed by derived class. Only protected and public data
   members and functions can be accessed in derived class.

3. Base class cannot access the data and functions of derived class. It is unaware of the
   properties of derived class.

4. A derived class can have multiple base classes.

5. Effect of mode of inheritance:
												Modes of Inheritance
										private		public		protected
	Accesss			|	private			  NA		  NA			NA
	Specifiers		|	public			private		public		protected
	of Base	Class	|	protected		private		protected	protected

6. For any mode of inheritance, the derived class can access the public and protected
   data of base class in the class itself.

7. Role of mode of inheritance:
	It determines what happens the members of base class when they are inherited in
	the derived class.

8. When there is a base class and derived class then the construtor of base is called
   first and then the constructor of derived is called. At the end, the destructor of
   derived is called first then the destructor of base is called.

9. If the constructor and destructor cannot be inherited then how they are called during
   derived class creation and destruction?
   C++ says that if an object is created of derived class then the members which are
   inherited from base should be initialized using the base constructor. Same is for
   destructor.

10. Invoke base parameterized constructor for initialising the base class members instead
	of updating them in the parameterized constructor of derived class.

11. If you do not choose an inheritance type, C++ defaults to private inheritance.
************************************************************************************/