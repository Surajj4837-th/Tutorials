// Section 17
// Weak Pointers
#include <iostream>
#include <memory>

using namespace std;

class B;    // forward declaration

class A 
{
    std::shared_ptr<B> b_ptr;
public:
    void set_B(std::shared_ptr<B> &b) 
    {
        b_ptr = b;
    }
    A() 
    { 
        cout << "A Constructor" << endl; 
    }

    ~A() 
    { 
        cout << "A Destructor" << endl; 
    }
};

class B 
{
    // std::shared_ptr<A> a_ptr;
    // Leaks memory due to strong circular reference
    // The destructors are never called if above statement is used

    std::weak_ptr<A> a_ptr;     // make weak to break the strong circular reference

public:
    void set_A(std::shared_ptr<A> &a) 
    {
        a_ptr = a;
    }

    B() 
    { 
        cout << "B Constructor" << endl;
    }

    ~B() 
    {
        cout << "B Destructor" << endl; 
    }
};

int main() {
    shared_ptr<A> a  = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->set_B(b);
    b->set_A(a);
    
    return 0;
}

/************************************Summary*****************************************
1. A weak pointer is a smart pointer that does not take ownership of an object but act 
   as an observer.
   
2. It does not participate in reference counting to delete an object or extend its lifetime. 
   
3. Weak pointers are mainly used to break the circular dependency that shared pointers
   may create. Circular dependency makes the memory freeing impossible.
************************************************************************************/