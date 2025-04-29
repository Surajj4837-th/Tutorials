// Vector
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int main()
{
    std::vector<int> g1;
 
    for (int i = 1; i <= 5; i++)
        g1.push_back(i);

    //----------------------------------iterators----------------------------------
    cout << "Output of begin and end: ";
    for (auto i = g1.begin(); i != g1.end(); ++i)
        cout << *i << ", ";

    cout << endl;
    //Output of begin and end: 1, 2, 3, 4, 5, 

    cout << "\nOutput of cbegin and cend: ";
    for (auto i = g1.cbegin(); i != g1.cend(); ++i)
        cout << *i << ", ";

    cout << endl;
    //Output of cbegin and cend: 1, 2, 3, 4, 5, 

    cout << "\nOutput of rbegin and rend: ";
    for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
        cout << *ir << ", ";
 
    cout << endl;
    //Output of rbegin and rend: 5, 4, 3, 2, 1, 

    cout << "\nOutput of crbegin and crend : ";
    for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
        cout << *ir << ", ";

    cout << endl;
    //Output of crbegin and crend : 5, 4, 3, 2, 1, 

    cout << endl;

    //----------------------------------Capacity----------------------------------

    cout << "Size : " << g1.size();             //Returns the number of elements in the vector.
    cout << "\nCapacity : " << g1.capacity();   //Returns the size of the storage space currently allocated to the vector expressed as number of elements.
    cout << "\nMax_Size : " << g1.max_size();   // Returns the maximum number of elements that the vector can hold.
 
    // resizes the vector size to 4
    g1.resize(4);
 
    // prints the vector size after resize()
    cout << "\nSize after resizing: " << g1.size();
 
    // checks if the vector is empty or not
    if (g1.empty() == false)
        cout << "\nVector is not empty";
    else
        cout << "\nVector is empty";
 
    // Shrinks the vector
    g1.shrink_to_fit();
    cout << "\nVector elements are: ";
    for (auto it = g1.begin(); it != g1.end(); it++)
        cout << *it << " ";

    g1.reserve(10);     //Requests that the vector capacity be at least enough to contain n elements.
    cout << "\nCapacity after reserving: " << g1.capacity();

    cout << endl;

    //----------------------------------Capacity----------------------------------

    cout << "\nReference operator : g1[2] = " << g1[2];     //Returns a reference to the element at position ‘g’ in the vector
 
    cout << "\nat : g1.at(3) = " << g1.at(3);               //Returns a reference to the element at a position in the vector
 
    cout << "\nfront() : g1.front() = " << g1.front();      //Returns a reference to the first element in the vector
 
    cout << "\nback() : g1.back() = " << g1.back();         //Returns a reference to the last element in the vector
 
    // pointer to the first element
    int* pos = g1.data();
    cout << "\nThe first element is " << *pos << endl;

    cout << endl;

    //----------------------------------Modifiers----------------------------------

    std::vector<int> v;

    // fill the vector with 10 five times
    v.assign(5, 10);

    // inserts 15 to the last position, size is increased by 1.
    v.push_back(15);

    int n = v.size();
    cout << "\nThe last element is: " << v[n - 1] << endl;     //access last element

    // removes last element, decreases size.
    v.pop_back();


    // inserts 5 at the beginning, it does not replace the front element
    v.insert(v.begin(), 5);

    // removes the first element
    v.erase(v.begin());

    // inserts 5 at the beginning + 1 position
    v.emplace(v.begin() + 1, 5);

    // Inserts 20 at the end
    v.emplace_back(20);

    // prints the vector
    cout << "\nThe vector elements are: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << endl;

    // erases the vector, size = 0
    v.clear();


    // two vector to perform swap
    std::vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    v2.push_back(3);
    v2.push_back(4);

    // Swaps v1 and v2
    v1.swap(v2);

    //------------------------------------------------------------------------

    return 0;
}
/************************************Summary*****************************************
1. 
************************************************************************************/