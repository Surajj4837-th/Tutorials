// C++11/STL_Set.cpp
// Set in STL in C++11

#include <iostream>
#include <set>

using std::cout;
using std::endl;

int main()
{

    //---------------------------------- ----------------------------------

    std::set<char> a;
    
    //Insertion
    a.insert('G');
    a.insert('F');
    a.insert('G');  //Duplicate values are rejected

    for (auto &str : a)
    {
        std::cout << str << ' ';
    }
    std::cout << '\n';


    // empty set container
    std::set<int> s1;
 
    // insert elements in random order
    s1.insert(40);
    s1.insert(30);
    s1.insert(60);
    s1.insert(20);
    s1.insert(50);

    // printing set s1
    std::set<int>::iterator itr;
    cout << "\nThe set s1 is : \n";
    for (itr = s1.begin(); itr != s1.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;

    // remove all elements up to 30 in s1
    s1.erase(s1.begin(), s1.find(30));

    //Display set
    for (itr = s1.begin(); itr != s1.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;

    // remove element with value 50 in s2
    int num;
    num = s1.erase(50);

    //Display set
    for (itr = s1.begin(); itr != s1.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;


    //---------------------------------------------------------------------

    return 0;
}
/************************************Summary*****************************************
1. Sets are a type of associative container in which each element has to be unique 
   because the value of the element identifies it. 

2. Set has values in descending order.

3. For searching binary search tree is used.

4. To store the elements in an random order, unordered_set() can be used.
************************************************************************************/