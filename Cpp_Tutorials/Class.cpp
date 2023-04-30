//Stack implementation using Class

#if 1
#include"Class.h"

/******* Member function declarations and definitions *********/
//Compiler sees the functions defined outside the class as global function and
//thus the data members used inside the function definition will give errors.
//We have to use scope resolution opeator to tell the compiler that a
//function belongs to which particular class.

void Stack::InitializeIndex()
//Initialize index of array
{
	index = 0;
}

void Stack::Push(int value)
//Pushes the value to the location pointed by pointer
{
	if(index < MAX)
	{
		array[index] = value;
		++index;
	}
}

int Stack::Pop()
//Returns and removes the value on top of stack
{
	if(index >= 0)
	{
		int value = array[index];
		--index;
		return value;
	}
}

int Stack::Top()
//Returns the value on top of stack
{
	if(index >= 0)
	{
		int value = array[index - 1];
		return value;
	}
}

int main()
{
	Stack S1;
	//Object declaraton of Stack class.
	//Stack is just a concept/template and S1 is a physical entity which consumes memory
	int i;

	/* Following access not allowed in OOP concept.
		S1.index = 100;
	*/

	cout << "Size of empty class: " << sizeof(emptyClass) << "bytes." << endl;
	//What is the size of an empty class?

	S1.InitializeIndex();

	S1.Push(10);
	S1.Push(20); 

	cout << S1.Top() << endl;

	int value = S1.Pop();
	
	cin.get();
}


#else

#include "Header.h"

/************************Class Declaration************************/
class Stack{

private:
	int array [MAX];
	int index;

public:
	/******* Member function declarations and definitions *********/
	void InitializeIndex()
	//Initialize index of array
	{
		index = 0;
	}

	void Push(int value)
	//Pushes the value to the location pointed by pointer
	{
		if(index < MAX)
		{
			array[index] = value;
			++index;
		}
	}

	int Pop()
	//Returns and removes the value on top of stack
	{
		if(index >= 0)
		{
			int value = array[index];
			--index;
			return value;
		}
	}

	int Top()
	//Returns the value on top of stack
	{
		if(index >= 0)
		{
			int value = array[index - 1];
			return value;
		}
	}
};//End of class


int main()
{
	Stack S1;
	//Object declaration of Stack class.
	//Stack is just a concept/template and S1 is a physical entity which consumes memory
	
	/* Following access not allowed in OOP concept.
		S1.index = 100;
	*/

	S1.InitializeIndex();

	S1.Push(10);
	S1.Push(20); 

	cout << S1.Top()<<endl;

	int value = S1.Pop();	

	cin.get();
}

#endif

/************************************Summary****************************************
1. Class is a user defined data type and it does not allow direct access to its 
   members outside its scope.

2. If not specified, the data members and functions of a class are private.

3. If not specified, the data members and functions of a structure are public.

4. Access specifiers:
   private
   public
   protected
   
   The effect of an access specifier is applicable till compiler finds another access 
   specifier or till the compiler finds the end of class.
   private and protected are similar for a single class.

5. Terminology: Class variable is called as an object here.

6. In case the class is too long to go through its components i.e. class is less readable,
   in such case the function definitions can be placed outside the class.

7. There are 2 variables of same name, one is global and other is local. When they both
   are existing then how to access each one of them?

   :: operator used to access global variable.
   Or 
   extern keyword can also be used.

8. Use of scope resolution operator:
	a. To define the class member functions outside the class.
	b. To access the global variable in a function.
  
9. Size of empty class is nonzero to ensure that the two different objects will have 
   different addresses.
************************************************************************************/