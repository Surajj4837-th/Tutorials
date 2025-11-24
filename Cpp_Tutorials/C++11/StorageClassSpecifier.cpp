// C++11/StorageClassSpecifier.cpp
// Storage class specifier in C++11

#include "StorageClassSpecifier.h"

using std::cout;
using std::endl;

extern int var;

#define AUTO		0
#define EXTERN		0
#define STATIC		0
#define REGISTER	0
#define MUTABLE		0


void autoStorageClass()
{

	cout << "Demonstrating auto class\n";

	// Declaring an auto variable
	// No data-type declaration needed
	auto a = 32;
	auto b = 3.2;
	auto c = "GeeksforGeeks";
	auto d = 'G';

	// printing the auto variables
	cout << a << " \n";
	cout << b << " \n";
	cout << c << " \n";
	cout << d << " \n";
}


// Function containing static variables
// memory is retained during execution
int staticFun()
{
	cout << "For static variables: ";
	static int count = 0;
	count++;
	return count;
}


// Function containing non-static variables
// memory is destroyed
int nonStaticFun()
{
	cout << "For Non-Static variables: ";

	int count = 0;
	count++;
	return count;
}


void registerStorageClass()
{
	cout << "Demonstrating register class\n";

	// declaring a register variable
	register char b = 'G';

	// printing the register variable 'b'
	cout << "Value of the variable 'b' declared as register: " << b;

	cout << &b << endl;
}

class Test {
public:
	int x;

	// defining mutable variable y
	// now this can be modified
	mutable int y;

	Test()
	{
		x = 4;
		y = 10;
	}
};


int main()
{

#if AUTO

	// To demonstrate auto Storage Class
	autoStorageClass();

#endif

#if EXTERN

	cout << var << endl;

	//var = 11;

#endif

#if STATIC

	// Calling the static parts
	cout << staticFun() << "\n";
	cout << staticFun() << "\n";
	

	// Calling the non-static parts
	cout << nonStaticFun() << "\n";
	cout << nonStaticFun() << "\n";

#endif

#if REGISTER

	// To demonstrate register Storage Class
	registerStorageClass();

#endif


#if MUTABLE

	// t1 is set to constant
	const Test t1;

	// trying to change the value
	t1.y = 20;
	cout << t1.y;

	// Uncommenting below lines
	// will throw error
	// t1.x = 8;
	// cout << t1.x;

#endif

	return 0;
}


/************************************Summary*****************************************
1. Storage Classes are used to describe the features of a variable/function. These 
   features basically include the scope, visibility and life-time

2. Storage Class		Keyword			Lifetime			Visibility		Initial Value
	Automatic			auto			Function Block		Local			Garbage
	External			extern			Whole Program		Global			Zero
	Static				static			Whole Program		Local			Zero
	Register			register		Function Block		Local			Garbage
	Mutable				mutable			Class				Local			Garbage

3. auto keyword provides automatic deduction of the data type of an expression. As all 
   the types are deduced in compiler phase only, the time for compilation increases 
   slightly but it does not affect the run time of the program.

4. extern storage class simply tells us that the variable is defined elsewhere and not 
   within the same block where it is used.Basically, the value is assigned to it in a 
   different block and this can be overwritten/changed in a different block as well.

5. an extern variable is nothing but a global variable initialized with a legal value 
   where it is declared in order to be used elsewhere. It can be accessed within any 
   function/block. 

6. The main purpose of using extern variables is that they can be accessed between two 
   different files which are part of a large program.

7. When we write extern some_data_type some_variable_name; no memory is allocated. 
   Only property of variable is announced. When an extern variable is initialized, 
   then memory for this is allocated and it will be considered defined.

8. Multiple declarations of extern variable is allowed within the file. This is not 
   the case with automatic variables.

9. extern variable says to compiler  � go outside my scope and you will find the 
   definition of the variable that I declared.�

10. When a function is declared or defined, the extern keyword is implicitly assumed.

11. Eg. of an extern is: decalre a variable in a.h file with extern keyword, define it 
	in b.c file and use/call it in c.c file, provided both .c file include a.h file.

12.	When extern is used with a variable, it�s only declared, not defined. As an exception, 
	when an extern variable is declared with initialization, it is taken as the definition 
	of the variable as well.

13.	static storage class is used to declare static variables. Static variables have a 
	property of preserving their value even after they are out of their scope.

14. Static variables are initialized only once and exist until the end of the program.

15.	Static variables are local to the function to which they were defined. Global static 
	variables can be accessed anywhere in the program.

16.	By default, static variables are assigned the value 0 by the compiler.

17.	register storage class declares register variables which have the same functionality 
	as that of the auto variables. The only difference is that the compiler tries to 
	store these variables in the register of the microprocessor if a free register is 
	available.

18. register variables are much faster than that of the variables stored in the memory 
	during the runtime of the program.

19. If a free register is not available, these are then stored in the memory only. 
	Usually, a few variables which are to be accessed very frequently in a program are 
	declared with the register keyword which improves the running time of the program.

20. An important and interesting point to be noted here is that we cannot obtain the 
	address of a register variable using pointers.

21. In C++, register is a deprecated, meaningless keyword that has no effect and variables 
	declared as register still just have automatic storage.

22. Sometimes there is a requirement to modify one or more data members of class/struct 
	through const function even though you don�t want the function to update other members 
	of class/struct. This task can be easily performed by using the mutable keyword.

23. The keyword mutable is mainly used to allow a particular data member of const object 
	to be modified.

24. When we declare a function as const, this pointer passed to function becomes const. 
	Adding mutable to a variable allows a const pointer to change members.
************************************************************************************/