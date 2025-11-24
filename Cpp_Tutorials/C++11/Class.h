//Class.h
//Class Declaration in C++11

#include <iostream>

#if 1   //More readable class declaration

#define MAX			10

/************************Class Declaration************************/
class Stack{

private:
	int array [MAX];
	int index;

public:
	void InitializeIndex();
	void Push(int value);
	int Pop();
	int Top();
};//End of class

class emptyClass{};

#endif