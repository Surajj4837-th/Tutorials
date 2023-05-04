// Deque
#include <iostream>
#include <deque>

using std::cout;
using std::endl;

void showdq(std::deque<int> g)
{
    std::deque<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}


int main()
{

    //---------------------------------- ----------------------------------

    std::deque<int> DQ;
    DQ.push_back(10);
    DQ.push_front(20);
    DQ.push_back(30);
    DQ.push_front(15);
    cout << "The deque DQ is : ";
    showdq(DQ);
 
    cout << "DQ.size() : " << DQ.size() << endl;
    cout << "DQ.max_size() : " << DQ.max_size() << endl;
 
    cout << "DQ.at(2) : " << DQ.at(2) << endl;
    cout << "DQ.front() : " << DQ.front() << endl;
    cout << "DQ.back() : " << DQ.back() << endl;
 
    cout << "DQ.pop_front() : ";
    DQ.pop_front();
    showdq(DQ);
 
    cout << "DQ.pop_back() : ";
    DQ.pop_back();
    showdq(DQ);

    //clear deque
    DQ.clear();

    //Check if the deque is empty
    cout << "Is the queue empty?: " << DQ.empty() << endl;

    //------------------------------------------------------------------------

    return 0;
}
/************************************Summary*****************************************
1. Double-ended queues are sequence containers with the feature of expansion and contraction 
   on both ends.

2. Deque is similar to vectors, but is more efficient in case of insertion and deletion 
   of elements.
************************************************************************************/