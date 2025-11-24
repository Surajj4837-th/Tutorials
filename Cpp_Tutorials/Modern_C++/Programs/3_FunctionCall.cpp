// Modern_C++/Programs/3_FunctionCall.cpp
// How function calls works in C++17?
// The call stack and inline code

#include <iostream>

using namespace std;

void func2(int &x, int y, int z) {
    x+= y + z;
}

int func1(int a, int b) {
    int result {};
    result = a + b;
    func2(result, a , b);
    return result;
}

int main() {
    int x {10};
    int y{20};
    int z{};
    z = func1(x,y);
    cout << z << endl;
    return 0;
}

/* What typically happens when main calls func1 (or any function calls another) ?
    There are other ways to acheive the same results :)
    
    main:
        push local variables (if any)
        push space for the parameters
        push the return address
        transfer control to func1 (jmp)
    func1:
        push the address of the previous activation record (frame pointer)
        push any register values that will need to be restored before returning to the 
        caller function (such as main)
        push space for local variables (if any)
        retrieve the parameters from the stack and store them in local variables
        perform the code in func1 
        restore the register values 
        restore the previous activation record (move the stack pointer) 
        store any function result in a pre-defined location (such as a register or stack)
        transfer control to the return address (jmp) 
    main:
        pop the parameters 
        pop the return value 


Inline code:
For simple functions also the stack operations has to be done. These overheads can be 
avoided by using inline code. This function is faster than a regular function. The 
compiler replaces the function call with the actual function code at each place the 
function is called.  
*/



