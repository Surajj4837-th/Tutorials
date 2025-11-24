//C++11/SmartPointer_Shared.cpp
//Smart pointers in C++11 using shared_ptr

#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;

class Rectangle 
{
    int length;
    int breadth;
 
public:
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
 
    int area() 
    { 
        return length * breadth; 
    }
};


int main()
{
	//Shared pointer
	cout << "-------Shared pointer-------" << endl;
	std::shared_ptr<Rectangle> P1(new Rectangle(10, 5));
    
    // This'll print 50
    cout << "P1: " << P1->area() << endl;
 
    std::shared_ptr<Rectangle> P2;
    P2 = P1;
 
	cout << "After sharing" << endl;
    cout << "P2: " << P2->area() << endl;   // This'll print 50
 
    // This'll print 2 as reference counter is 2
    cout << "P1 use count: " << P1.use_count() << endl;

    P2.reset(); //Make P2 null, decrement the reference counter by 1
    cout << "After resetting P2: " << P1.use_count() << endl;

    
    // Another way of creating shared pointer
    std::shared_ptr<Rectangle> P3 = std::make_shared<Rectangle>(20, 5);
    cout << "P3: " << P3->area() << endl;   // This'll print 100


    //Create a vector of shared pointers
    std::shared_ptr<Rectangle> P4 = std::make_shared<Rectangle>(30, 5);
    std::shared_ptr<Rectangle> P5 = std::make_shared<Rectangle>(40, 5);
    std::shared_ptr<Rectangle> P6 = std::make_shared<Rectangle>(50, 5);
    cout << "P3 use count: " << P3.use_count() << endl;
    cout << "P4 use count: " << P4.use_count() << endl;
    cout << "P5 use count: " << P5.use_count() << endl;
    cout << "P6 use count: " << P6.use_count() << endl; 

    std::vector<std::shared_ptr<Rectangle>> vec;
    vec.push_back(P3);
    vec.push_back(P4);
    vec.push_back(P5);
    vec.push_back(P6);

    cout << "P3 use count: " << P3.use_count() << endl;
    cout << "P4 use count: " << P4.use_count() << endl;
    cout << "P5 use count: " << P5.use_count() << endl;
    cout << "P6 use count: " << P6.use_count() << endl; 
    //P3, P4, P5, P6 count increases due to push back operation

    for (const auto& ptr : vec) //ptr is a const reference to shared_ptr
        cout << ptr->area() << std::endl;

	return 0;
}
//Automatically all objects will be deleted when they go out of scope and the data 
// will be deleted from heap.

/************************************Summary*****************************************
1. A Smart Pointer is a wrapper class over a pointer which can deallocate and free 
   destroyed object memory.

2. Smart pointers are also useful in the management of resources, such as file handles 
   or network sockets.	

3. If smart pointer is not used then the developer has to take care of the object memory 
   cleanup.
      
4. Problems with normal pointers:
   - Memory leaks
   - Dangling pointer
   - Wild pointers
   - Buffer overflow due to memory allocation beyond memory block.

5. auto_ptr - pointer object stores a pointer to a single allocated object. This is 
   deprecated in C++11. Replaced by unique pointer.
   
6. unique_ptr - stores one pointer only. We can assign a different object by removing 
   the current object from the pointer. When it is destroyed, it deletes the object
   it points to.
   
7. shared_ptr - more than one pointer can point to this one object at a time and it�ll 
   maintain a Reference Counter.

8. weak_ptr - A weak pointer is a smart pointer that does not take ownership of an object 
   but act as an observer. In other words, it does not participate in reference counting 
   to delete an object or extend its lifetime. Weak pointers are mainly used to break the 
   circular dependency that shared pointers may create.
   https://iamsorush.com/posts/weak-pointer-cpp/

9. Pointers - https://iamsorush.com/posts/how-use-cpp-raw-pointer/

10. Shared pointer points to an object on heap.

11. It eshtablishes shared ownership of an object through a pointer. 

12. Several shared_ptr objects may own the same object. The object is destroyed and 
    its memory is deallocated when either of the following happens:
    - the last remaining shared_ptr owning the object is destroyed;
    - the last remaining shared_ptr owning the object is assigned another pointer via 
      operator= or reset().

13. When all the pointers go out of scope, the data is deleted automatically from heap.

14. Last one owning shared_ptr will have responsibilty to clean up the memory.

15. Scope is very important in this, if a shared pointer is passed by value to a function, 
    the reference count is incremented when the function is called and decremented 
    when the function exits. Also if there are multiple pointers in the function are 
    made to share the data then the reference count is incremented for each pointer and 
    they are decremented when they go out of scope.
************************************************************************************/