//Type casting operators
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	//C type implicit casting
	float var1 = 9.2F;
	int var2 = var1;
	cout << var2 << endl;

	//static casting - similar to implicit casting in C.
	int var3 = static_cast<int>(var1);
	float var4 = static_cast<float>(var3);
	cout << var3 << endl;
	cout << var4 << endl;

	//type casting
	float var5 = 97.89F;
	char* var6 = (char*)&var5;
	cout << *var6 << endl;

	
	std::cin.get();
	return 0;
}

/************************************Summary*****************************************
1. A Cast operator is an unary operator which forces one data type to be converted into 
   another data type.
2. Static cast - Is is the simplest cast done at compile time.
************************************************************************************/