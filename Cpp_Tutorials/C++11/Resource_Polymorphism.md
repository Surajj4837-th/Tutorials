## Polymorphism
- It is a concept called as single interface multiple methods.
	Here a single task can be done in multiple ways, not supported by C.

											Polymorphism
			           _________________________|____________________________________
					  |													       		 |
				Compile Time													 Runtime
			__________|________________											 	 |
		   |						   |									  Virtual Functions	
		Function					Operator
		Overloading					Overloading


1. Compile Time Polymorphism
   Function and operator overloading are both functions and the function call resolution is done 
   by compiler.
	
	a. Function overloading-

		There can be more than one function with the same name.
		
		How a compiler differentiates between different functions having same names?
		Function definition selection depends on:
		- Number of arguments
		- Type of arguments
		- Same arguments but different order
		- const object invokes const function and non-const object invokes non-const 
		  function
		
		Which cases are invalid and create ambiguity for compiler in choosing the 
		function definition?
		- Example 1: Overloading with References vs Values (Too Similar)
				void doSomething(int x);
				void doSomething(int& x);
		
			Above declarations are not allowed.

		- Example 2: Overloading by Return Type Only 
		Why function overloading is not done by considering the change in return type 
		of a function?
		- Because the developer may or may not use the return type.

				int sum(int a, int b);
				void sum(int a, int b);
		
		In both the cases, it is not compulsory for the developer to use the returned 
		data. This creates ambiguity for the compiler.

		- Example 3: Overloading That Leads to Ambiguity (e.g., Default Arguments)
			void display(int x);
			void display(int x, int y = 10);  // Ambiguous call: display(5);

b. Operator Overloading

	int a = 10;
	++a;		//Compiler knows what to do
	
	class Trainee;
	++Trainee;	//Compiler doesn't know what to do
	
	Operator overloading says if an operator with a primitive data type is allowed 
	then it should also be allowed with an user defined data type.
	i.e. if ++a is allowed then ++Trainee should also be allowed.

1. Run Time Polymorphism

   Virtual and pure virtual functions.