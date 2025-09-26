//Smart pointers
#include <iostream>
#include <memory>

using std::cout;
using std::endl;

//Smart pointer class
template <class T> class SmartPtr 
{
    T* ptr; // Actual pointer
public:

    // Constructor
    explicit SmartPtr(T* p = NULL) 
    { 
        ptr = p; 
    }
 
    // Destructor
    ~SmartPtr() 
    { 
        delete (ptr);
    }
 
    // Overloading dereferencing operator
    T& operator*() 
    { 
        return *ptr; 
    }
 
    // Overloading arrow operator so that
    // members of T can be accessed
    // like a pointer (useful if T represents
    // a class or struct or union type)
    T* operator->() 
    { 
        return ptr; 
    }
};


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
	SmartPtr<int> ptr(new int());
    *ptr = 20;
    cout << *ptr << endl;

	//unique pointer
	cout << "-------Unique pointer-------" << endl;
	std::unique_ptr<Rectangle> P1(new Rectangle(10, 5));
    cout << P1->area() << endl; // This'll print 50
 
    // unique_ptr<Rectangle> P2(P1);
    std::unique_ptr<Rectangle> P2;
    P2 = move(P1);
 
    // This'll print 50
    cout << P2->area() << endl;
 
	//Prints nothing
	//cout<< P1->area() <<endl;	//Code Crashes

	//shared pointer
	cout << "-------Shared pointer-------" << endl;
	std::shared_ptr<Rectangle> P3(new Rectangle(10, 5));
    // This'll print 50
    cout << P3->area() << endl;
 
    std::shared_ptr<Rectangle> P4;
    P4 = P3;
 
	cout << "After sharing" << endl;
    // This'll print 50
    cout << P4->area() << endl;
 
    // This'll also print 50 now
    cout << P3->area() << endl;
 
    // This'll print 2 as Reference Counter is 2
    cout << P3.use_count() << endl;

	return 0;
}


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
   
************************************************************************************/