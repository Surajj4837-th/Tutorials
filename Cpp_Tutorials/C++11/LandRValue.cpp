#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int a = 0;	// a - l-value, 0 - r-value

	int b = a;	//l-value can appear on both sides of =.

	(a > b ? a : b) = 1;	//Valid statement

	//l-value reference
	int& c = a;
	c = 10;			//l-value rference can be updated

	std::cout << std::boolalpha;		//To print true and false instead of 1 and 0 respectively.

	std::cout << (&c == &a) << std::endl;

	// r-value
	int x {100};		// 100 is an r-value
	int y = x + 200;	// (x+200)is an r-value

	std::string name = "Frank";		// "Frank" is an r-value

	int max_num = std::max(20,30); // std::max(20,30) is an r-value, since it returns a non-addressable result.

	// r-value reference
	int&& rref = 90;

	rref = 80;		//r-value rference can be updated

	//Following statements are invalid
	//int& d = 10;		//Cannot bind r-value to l-value reference	
	//int&& rref2 = a;	//Cannot bind l-value to r-value reference

	//However following statements are allowed
	rref = b;
	a = rref;

	return 0;
}
/************************************Summary*****************************************
1. l-value refers to memory location which identifies an object. l-value may appear 
   as either left hand or right hand side of an assignment operator(=).

2. The l-value is one of the following:
   - The name of the variable of any type i.e, an identifier of integral, floating, 
	 pointer, structure, or union type.
   - A subscript ([ ]) expression that does not evaluate to an array.
   - A unary-indirection (*) expression that does not refer to an array
   - An l-value expression in parentheses.
   - A const object (a non-modifiable l-value).
   - The result of indirection through a pointer, provided that it isn?t a function pointer.
   - The result of member access through pointer(-> or .)

3. r-value refers to data value that is stored at some address in memory. 

4. r-value cannot be assigned a value thus r-value cannot appear on left side of "=".

5. rvalue references extend the lifespan of the temporary object to which they are assigned.

6. lvalue references can be assigned with the rvalues but rvalue references cannot be 
   assigned to the lvalue.

7. lvalue references can be used to alias an existing object and in pass by reference. 

8. Anythinf that is not an l-value is an r-value:
	- Right side of an assignment operator.
	- A literal.
	- A temporary which is intended to be non-modifiable.
************************************************************************************/