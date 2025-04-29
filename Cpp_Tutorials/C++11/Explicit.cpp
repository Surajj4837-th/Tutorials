//Use of explicit keyword
#include <iostream>

using std::cout;
using std::endl;

class Foo
{
public:
  // single parameter constructor, can be used as an implicit conversion
  Foo (int foo) : m_foo (foo) 
  {
  }

  int GetFoo () { return m_foo; }

private:
  int m_foo;
};

void DoBar (Foo foo)
{
  int i = foo.GetFoo ();
}

int main ()
{
	Foo Obj1 = 10;			//Valid without explicit
	Foo Obj2 = Foo(20);		//Valid
	Foo Obj3 = (Foo)30;		//Valid
	Foo Obj4(40);			//Valid

	DoBar (42);				//Valid without explicit
	/*
	The argument is not a Foo object, but an int. However, there exists a constructor 
	for Foo that takes an int so this constructor can be used to convert the parameter to the correct type.

	The compiler is allowed to do this once for each parameter.
	*/
}
/************************************Summary*****************************************
1. In C++, a constructor with only one required parameter is considered an implicit 
   conversion function. It converts the parameter type to the class type.

2. Prefixing the explicit keyword to the constructor prevents the compiler from using 
   that constructor for implicit conversions.

3. In above example if the keyword 'explicit' is used before constructor then the function 
   call will give error.  It is now necessary to call for conversion explicitly with 
   DoBar (Foo (42)).

4. This avoids accidental construction of objects.
*************************************************************************************/