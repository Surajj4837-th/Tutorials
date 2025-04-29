//Boolean
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    bool a{}; // default initialize to false
    
    
    bool b{false};
    std::cout << b << '\n'; // b is false, which evaluates to 0
    std::cout << !b << '\n'; // !b is true, which evaluates to 1

    std::cout << std::boolalpha; // print bools as true or false

    std::cout << b << '\n';
    std::cout << !b << '\n';


    bool c{4}; // may give warning else set to true
    std::cout << c << '\n';


    return 0;
}
/************************************Summary*****************************************
1. Boolean values are not actually stored in Boolean variables as the words “true” or 
   “false”. Instead, they are stored as integers: 1 and 0.

2. std::boolalpha helps to print true and false instead of 1 and 0. std::cin also takes 
   0 and 1 as input. To get the input as true and false std::boolalpha should be used.
************************************************************************************/