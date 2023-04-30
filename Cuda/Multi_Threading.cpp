//Multithreading
#include <iostream>
#include <thread>

using std::cout;
using std::endl;


void function(int value)
{
	for (int temp = 0; temp < 5; temp++)
		cout << "Thread using funciton at " << temp << endl;
}

class sample
{
public:

	//For implementing that function object, first, we need a class, 
	//and inside that class, we have to overload the operator ().
	void operator()(int value)
	{
		for (int temp = 0; temp < 5; temp++)
			cout << "Thread using funciton object at " << temp << endl;
	}
};

int main()
{
	//function sent for multi-threading.
	std::thread thread_function(function, 10);


	//function object sent for multi-threading.
	sample object;
	std::thread thread_function_object(object, 20);


	//lambda expression sent for multi-threading.
	auto f = [](int value)
	{
		for (int temp = 0; temp < 5; temp++)
			cout << "Thread using lambda expression: " << value << endl;

	};

	std::thread thread_lambda(f, 30);

	//Wait for thread_function thread to finish
	thread_function.join();

	//Wait for thread_function_object thread to finish
	thread_function_object.join();

	//Wait for thread_lambda thread to finish
	thread_lambda.join();

	return 0;
}
/************************************Summary*****************************************
1. Multithreading is a feature that allows concurrent execution of two or more parts 
   of a program for maximum utilization of the CPU. Each part of such a program is 
   called a thread. So, threads are lightweight processes within a process.

2. Multithreading support was introduced in C++11. Prior to C++11, we had to use POSIX 
   threads or <pthreads> library.

3. Functions, function objects or lambda expressions can be sent to std::thread ctor 
   for multithreading.

4. For implementing that function object, first, we need a class, and inside that class, 
   we have to overload the operator ().

5. In general, there are two types of multitasking: process-based and thread-based.
   Process-based multitasking handles the concurrent execution of programs. Thread-based 
   multitasking deals with the concurrent execution of pieces of the same program.
************************************************************************************/