//Smart pointers
#include <iostream>
#include <memory>
#include <vector>

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
    cout << "P1: " << P1->area() << endl; // This'll print 50
 
    // std::unique_ptr<Rectangle> P2(P1);   //Error
    //Unique pointers are not allowed to copy or assign to another object

    std::unique_ptr<Rectangle> P2;
    P2 = move(P1);  //P1 will become null after this
 
    // This'll print 50
    cout << "P2: " << P2->area() << endl;
 
	//Prints nothing
	//cout<< P1->area() <<endl;	//Code Crashes

    //Another way of creating unique pointer in C++14
    std::unique_ptr<Rectangle> P5 = std::make_unique<Rectangle>(10, 5);
    //Template argument of class type and the constructor arguments in ()

    cout << "P5: " << P5->area() << endl; // This'll print 50

    //Create a vector of unique pointers
    std::vector<std::unique_ptr<Rectangle>> vec;
    vec.push_back(std::make_unique<Rectangle>(10, 5));
    vec.push_back(std::make_unique<Rectangle>(20, 5));
    vec.push_back(std::make_unique<Rectangle>(30, 5));
    // vec.push_back(P1); //Error: cannot move a null unique pointer
    // vec.push_back(P2); //Error: cannot copy unique pointer

    for (const auto& ptr : vec) //ptr is a const reference to unique_ptr
    {
        cout << "Area: " << ptr->area() << endl;
    }
    
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
   a. Memory leaks: If the developer forgets to delete the memory allocated to 
      the object then it will lead to memory leaks.
   b. Dangling pointers: If the developer deletes the object memory but forgets to 
      set the pointer to nullptr then it will lead to dangling pointer.
   c. Double deletion: If the developer deletes the same object memory twice then 
      it will lead to undefined behaviour.
   d. Not exception safe: If an exception is thrown after the memory allocation but 
      before the delete statement then it will lead to memory leaks.
      
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

10. Uniques pointers are not allowed to copy or assign to another object. But they can 
    be moved.

11. After moving a unique pointer to another, the source pointer becomes null.

12. When using a for loop over unique pointer vector, reference is to be used as the 
    unique pointer cannot be copied and when we do not use reference in for loop assignment
    then it tries to copy the unique pointer to the loop variable.

13. Custom deleters can be used with smart pointers to define how the memory should be 
    deallocated. This is useful when dealing with resources that require special cleanup 
    procedures, such as file handles or network connections.
************************************************************************************/