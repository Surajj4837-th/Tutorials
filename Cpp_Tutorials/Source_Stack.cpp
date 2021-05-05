//Stack implementation using Structure

#include "Header.h"

int main()
{
	Stack S1;
	//In C, I will have to use keyword struct for a structure variable declaration
	//Even though there are functions declared in the structure the memory allocated 
	//will be equal to the variables of the structure only

	S1.initializeIndex();
	//The code will crash if index is not initialized as it will have a random value 
	//which may not point to anything iin the array

	S1.Push(10);
	S1.Push(20);
	//Whichever variable calls the member function, the function.
	//works with the data of that variable, here the variable is S1.
	//The pointer of the variable is implicitly passed to the member function 

	cout << S1.Top()<<endl;

	int value = S1.Pop();

	cin.get();
}

/************************************Summary****************************************
1. This code shows first charachteristic of OOP i.e. Encapsulation.

2. Encapsulation is a feature in which we combine data and functions together.
   Structure used here has some data members and some member functions.

3. It's a partial encapsulation used in the code because encapsulation also suggests
   that when we create a variable, the data of the variable should not be accessed
   directly rather it should be accessed through members functions only.
   We can also do a mistake here,
   S1.index = 100;
   technically and syntactically it is correct but it is not the concept of encapsulation.
   Direct access of the data is harmful to the program.

4. By default strutures in C++ do not have such protection to data.

5. Polymorphism:
   It is a feature in which an object can perform a task in multiple ways.

6. Inheritance:
   Child of an object carries the attributes/charachteristics of the parent.
************************************************************************************/