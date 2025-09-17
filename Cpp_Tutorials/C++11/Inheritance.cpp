#//Stack implementation using Class

#include"Class.h"

using std::cout;
using std::endl;

class Counter
{
protected:
	int count;

public:

	Counter()
	{
		cout << "Default Counter()" << endl;
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

	/*void InitializeCount(int cnt = 0)
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

	DownCounter()	//Default base class constructor is called
	{
		cout << "Default Downcounter()" << endl;
		Id = 0;
	}

	DownCounter(int id, int cnt) : Counter(cnt)		//syntax for calling base parameterized constructor
	{
		// First the base constructor is called.
		// Then the initializer list.
		// In the end this constructor body.

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

	//DownCounter.count = 1;		// compiler error: protected members cannot be accessed

	DownCounter D2;
	cout << D2.getCount() << endl;

#if 0
	cout << sizeof(D1) << endl;

	D1.InitializeId(1001);
	D1.InitializeCount(10);		//Cannot access count here to initialize it.

	cout << D1.getCount() << endl;

	D1.DoCountDown();
	cout << D1.getCount() << endl;
#endif

	return 0;
	std::cin.get();

}
/************************************Summary****************************************
1. Size of derived class includes memory for base class.

2. Private members cannot be accessed by derived class. Only protected and public 
   members can be accessed in derived class. Public members can be directly referred
   in code but protected members cannot be directly referred. So a protected member is
   a private member but it can be passed to the derived class.

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

12. Purppose of inheritance:
	Reuability - create new classes from existing classes.
	Sharing common functionalities between classes decreases development time.
	Clean code due to better readability.

13. Generalization - Combining similar classes into a single, more general class based 
	on common attributes.

14. Specialization - Creating new classes from existing classes with more specialized 
	attributes.

15. Friend class can access public, protected and private members of the base class.

16. The constructor of base class is invoked first and then the derived class.

17. The destructor of derived class is called first and then base class.

18. A derived class does not inherit:
	Base class constructor.
	Base class destructor.
	Base class overloaded assignment operator.
	Base class friend function.
	However the derived class constructor, destructor and overloaded assignment operator
	can invokr the base class version.

19. Base class constructor is called using the initializer list in the derived class 
	constructor. First the base constructor is called. Then the initializer list. In 
	the end this constructor body. If there is no base constructor called then the 
	defaultconstructor is invoked.

20. Base part of the derived class must be initialized before the derived part. When
	a derived class object is created, the base class constructor is called first, and
	then the derived class constructor is called. 

21. Similarly, when a derived class object is destroyed, the derived class destructor
   	is called first, followed by the base class destructor.
***********************************************************************************/