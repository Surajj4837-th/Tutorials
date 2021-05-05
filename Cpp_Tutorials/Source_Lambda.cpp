//Lambda
#include "Header.h"

int main()
{

	cin.get();
	return 0;

}
/************************************Summary*****************************************
1. C++ 11 allows to write an inline function which can be used for short snippets of 
   code that are not going to be reused and not worth naming.

2. Syntax:
   [ capture clause ] (parameters) -> return-type  
	{   
      definition of method   
	} 
   Generally return-type in lambda expression are evaluated by compiler itself and we 
   don’t need to specify that explicitly and -> return-type part can be ignored but 
   in some complex case as in conditional statement, compiler can’t make out the return 
   type and we need to specify that.
************************************************************************************/