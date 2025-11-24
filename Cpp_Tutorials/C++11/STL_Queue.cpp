// C++11/STL_Queue.cpp
// Queue in STL in C++11

#include <iostream>
#include <queue>

using std::cout;
using std::endl;

void showq(std::queue<int> gq)
{
    std::queue<int> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

int main()
{

    //---------------------------------- ----------------------------------
    std::queue<int> Q1;
    Q1.push(10);
    Q1.push(20);
    Q1.push(30);
 
    cout << "The queue Q1 is : ";
    showq(Q1);
 
    cout << "Q1.size() : " << Q1.size() << endl;
    cout << "Q1.front() : " << Q1.front() << endl;
    cout << "Q1.back() : " << Q1.back() << endl;
 
    cout << "Q1.pop() : " << endl;
    Q1.pop();
    
    showq(Q1);

    //------------------------------------------------------------------------

    return 0;
}
/************************************Summary*****************************************
1. empty()	Returns whether the queue is empty. It return true if the queue is empty 
   otherwise returns false.

2. size()	Returns the size of the queue.

3. swap()	Exchange the contents of two queues but the queues must be of the same data 
   type, although sizes may differ.

4. emplace()	Insert a new element into the queue container, the new element is added 
   to the end of the queue.

5. front()	Returns a reference to the first element of the queue.

6. back()	Returns a reference to the last element of the queue.

7. push(g) 	Adds the element ‘g’ at the end of the queue.

8. pop() 	Deletes the first element of the queue.
************************************************************************************/