#include "VirtualFunction.h"

int main()
{
	Base* base_ptr;
	Derived derived_obj;

	//Upcasting
	base_ptr = &derived_obj;

	//Runtime polymorphism
	base_ptr->show();	//Base class function called.
	base_ptr->print();	//Derived class function called.

	
						
	//Instantiation of abstract class is not allowed.
	//Animal animal_obj;
	//Human human_obj;

	return 0;
}

/************************************Summary*****************************************
1. A virtual function is a member function of a base class and is redefined in a
   derived class.
2. When a derived class object is referred using a pointer to the base class (upcasting),
   then calling a virtual function will call the derived class' function.
3. Difference between virtual function and function  overriding is that, in case of
   upcasting the virtual function call will execute the derived class function and in
   case of function overriding it is exactly opposite, the function call will execute
   the base class function.
4. Virtual function ensure that the correct function is called for an object regardless
   of the tpe of reference used for function call.
5. Virutal functions provide runtime polymorphism.
6. Abstract class: sometimes the implementation of all functions cannot be provided in
   a base class because we don't know the implementation, such a class is called as
   abstract class. A class is abstract if it has atleat 1 pure virtual function.
7. Pure virtual function or abstract function is a virtual function for which we don't
   have implementation, it is only delare in base class by assigning to 0.
8. If the derived class does not override the pure virtual function then it also becomes
   abstract class.
9. Abstract classes cannot be instantiated.
10. override keyword is used to properly override the virtual function. This avoids 
	any mistakes in function signature made by programmer and throws compilation error.
************************************************************************************/