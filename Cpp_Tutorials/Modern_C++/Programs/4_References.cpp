// Section 12
// References
// Please see the section 11 examples for references as function paramters
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{    
    int num {100};
    int &ref {num};
    
    cout << num << endl;
    cout << ref << endl;
    
    num  = 200;
    cout << "\n---------------------------------" << endl;
    cout << num << endl;
    cout << ref << endl;
    
    ref = 300;
    cout << "\n---------------------------------" << endl;
    cout << num << endl;
    cout << ref << endl;
    
    cout << "\n---------------------------------" << endl;
    vector<string> stooges {"Larry", "Moe", "Curly"};

    for (auto str: stooges)     
        str = "Funny";              // str is a COPY of the each vector element
      
    for (auto str:stooges)        // No change
        cout << str << endl;
 
    cout << "\n---------------------------------" << endl;
    for (auto &str: stooges)  // str is a reference to each vector element
        str = "Funny";
     
    for (auto const &str:stooges)       // notice we are using const
        cout << str << endl;            // now the vector elements have changed
    
    cout << endl;
    return 0;
}
/*******************************************************************************************
1. An alias for a variable.

2. Must be initialized to a variable when declared.

3. Cannot be null.

4. Once initialized cannot be made to refer to a diﬀerent variable.

5. Very useful as function parameters.

6. Might be helpful to think of a reference as a constant pointer that is automatically dereferenced.
******************************************************************************************/