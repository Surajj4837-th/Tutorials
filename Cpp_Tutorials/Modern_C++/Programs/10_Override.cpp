//Override specifier
#include <iostream>

class Base 
{
public:
    virtual void say_hello() const 
    {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }

    virtual ~Base() 
    {}
};

class Derived: public Base 
{
public:
    virtual void say_hello() const override
    {
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }

    virtual ~Derived() 
    {}
};


int main() 
{    
    Base *p1 = new Base();      // Base::say_hello()
    p1->say_hello();
    
    Derived *p2 = new Derived();    // Derived::say_hello()
    p2->say_hello();
    
    Base *p3 = new Derived();   //  Base::say_hello()   ?????   I wanted Derived::say_hello()
    p3->say_hello();
       
    return 0;
}

/************************************Summary****************************************
1. Override specifier is used in the derived class to indicate that a member function
   is meant to override a base class function.

2. The function signature (name, parameters, and constness) in the derived class
   must exactly match the base class function being overridden using virtual keyword.
   Sometimes when the programmer intends to override a base class function but makes
   a mistake in the function signature, the base class function is hidden instead of
   being overridden. This can lead to unexpected behavior.
***********************************************************************************/