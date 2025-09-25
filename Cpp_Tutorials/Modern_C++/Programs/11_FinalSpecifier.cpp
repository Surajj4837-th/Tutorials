//Override specifier
#include <iostream>

using namespace std;

class Base 
{
public:
    virtual void say_hello() const 
    {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
};

class Derived: public Base 
{
public:
    virtual void say_hello()  const override final      //Avoids further overriding
    {       
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
};

class Another: public Derived 
{
public:
    virtual void say_hello()  const override         // Error cannot: override final method
    {
        std::cout << "Hello - I'm a Another class object" << std::endl;
    }
};

void greetings(const Base &obj) 
{
    std::cout << "Greetings: " ;
    obj.say_hello();
}

using namespace std;

int main() 
{
    Base b;
    b.say_hello();
    
    Derived d;
    d.say_hello();
    
    Another a;
    a.say_hello();

    return 0;
}

/************************************Summary****************************************
1. final specifier when used at class level prevents the class from being inherited.

2. final specifier when used at method level prevents the method from being overridden
   in derived classes.

3. This is used for performance optimization and to avoid unintentional overrides.
***********************************************************************************/