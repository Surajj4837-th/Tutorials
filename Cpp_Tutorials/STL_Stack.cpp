//Stack
#include <iostream>
#include <stack>

using std::cout;
using std::endl;

int main()
{

    //---------------------------------- ----------------------------------

    std::stack<int> stack;
    stack.push(21);
    stack.push(22);
    stack.push(24);
    stack.push(25);

    int num = 0;
    stack.push(num);

    stack.pop();
    stack.pop();
    stack.pop();

    cout << "Is stack empty: " << stack.empty() << endl;
    cout << "Size of stack: " << stack.size() << endl;

    while (!stack.empty()) {
        cout << stack.top() <<" ";
        stack.pop();
    }

    cout << endl;

    //------------------------------------------------------------------------

    return 0;
}
/************************************Summary*****************************************
1. empty() – Returns whether the stack is empty – Time Complexity : O(1) 

2. size() – Returns the size of the stack – Time Complexity : O(1) 

3. top() – Returns a reference to the top most element of the stack – Time Complexity : O(1) 

4. push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1) 

5. pop() – Deletes the most recent entered element of the stack – Time Complexity : O(1) 
************************************************************************************/