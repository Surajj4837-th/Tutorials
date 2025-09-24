//Compile time polymorphism (Static)
#include <iostream>
#include <memory>

class Base 
{
public:
    void say_hello() const 
    {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
};

class Derived: public Base 
{
public:
    void say_hello()  const 
    {   
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
};

void greetings(const Base &obj) 
{
    std::cout << "Greetings: " ;
    obj.say_hello();        //obj is a reference to Base class
}

int main() 
{
    Base b;
    b.say_hello();
    
    Derived d;
    d.say_hello();
    
    greetings(b);   //Compile time polymorphism
    greetings(d);   //Compile time polymorphism
    
    //Raw pointer
    Base *ptr = new Derived();
    ptr->say_hello();  //At compi

    //smart pointer
    std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();
    ptr1->say_hello();

    delete ptr;

    return 0;
}

/************************************Summary****************************************
1. Types:
   a. Compile-time polymorphism: Function overloading, Operator overloading, Templates.
   b. Run-time polymorphism: Virtual functions.

2. At comple time, the compiler determines which function to call based on the 
   argument types. This is known as early binding or static binding or compile-time
   polymorphism.
***********************************************************************************/