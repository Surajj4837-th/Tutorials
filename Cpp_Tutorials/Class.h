#include "Header.h"

#if 1   //More readable class declaration

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