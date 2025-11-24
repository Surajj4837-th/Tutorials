// Modern_C++/Programs/9_Polymorphism_Dynamic.cpp
//Run time polymorphism (Dynamic) in C++17

#include <iostream>
#include <vector>

class Account 
{
public:
    virtual void withdraw(double amount)    //Overriden in derived class
    {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account() 
    { 
        std::cout << "Account:: destructor" << std::endl;
    }
};

class Checking: public Account  
{
public:
    virtual void withdraw(double amount) 
    {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    
    virtual ~Checking() 
    {
        std::cout << "Checking:: destructor" << std::endl;
    }
};

class Savings: public Account  
{
public:
    virtual void withdraw(double amount) 
    {
        std::cout << "In Savings::withdraw" << std::endl;
    }

    virtual ~Savings() 
    {
        std::cout << "Savings:: destructor" << std::endl;
    }
};

class Trust: public Account  
{
public:
    virtual void withdraw(double amount) 
    {
        std::cout << "In Trust::withdraw" << std::endl;
    }

    virtual ~Trust() 
    {
        std::cout << "Trust:: destructor" << std::endl;
    }
};

int main() 
{
    std::cout << "\n === Pointers ==== " << std::endl;
    Account *p1 = new Account();
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();
    
    p1->withdraw(1000);     //In Account::withdraw
    p2->withdraw(1000);     //In Savings::withdraw
    p3->withdraw(1000);     //In Checking::withdraw
    p4->withdraw(1000);     //In Trust::withdraw
    
    std::cout << "\n === Array ==== " << std::endl;
    Account *array [] = {p1,p2,p3,p4};
    for (auto i=0; i<4; ++i)
        array[i]->withdraw(1000);

    std::cout << "\n === Vector ==== " << std::endl;
    std::vector<Account *> accounts {p1,p2,p3,p4};
    for (auto acc_ptr: accounts)
        acc_ptr->withdraw(1000);

    std::cout << "\n === Clean up ==== " << std::endl;
    delete p1;  //Base and derived destructors are called
    delete p2;  //Base and derived destructors are called
    delete p3;  //Base and derived destructors are called
    delete p4;  //Base and derived destructors are called
        
    return 0;
}

/************************************Summary*********************************************
1. For dynamic polymorphism:
   a. Inheritance must be there.
   b. Base class reference or pointer must be used to refer to derived class object.
   c. Derived class must override the base class virtual function.

2. Virtual functions are member functions in the base class that you expect to 
   override in derived classes. When you use a base class pointer or reference to 
   refer to a derived class object, you can call a virtual function for that object 
   and execute the derived class's version of the function.

3. Declare the base class function as virtual which is to be overridden in derived 
   class.

4. To override a base class virtual function in derived class, the function signature
   must be same as that of base class. The virtual keyword is optional in derived class.

5. If a derived class object is destroyed using base class pointer, then the base class
   destructor must be virtual. This ensures that the derived class destructor is called
   first, followed by the base class destructor. If the base class destructor is not
   virtual, then only the base class destructor is called, and the derived class
   destructor is not called, which can lead to resource leaks.

6. Whenever there are virtual functions in a class, it should have a virtual destructor. 
   This ensures that the derived class destructor is called when an object is deleted 
   through a base class pointer.

7. When a base class pointer is created pointing to a derived class object, then the
   base class part of derived class object is created first, followed by the derived
   class part. When the object is destroyed, the derived class destructor is called 
   first, followed by the base class destructor.

8. Virtual functions use a mechanism called the virtual table (vtable) to support 
   dynamic dispatch. Each class with virtual functions has its own vtable, which is 
   essentially a lookup table of function pointers. When a virtual function is called 
   on an object, the program uses the vtable to determine the correct function to call 
   based on the actual type of the object at runtime.

9. Dynamic polymorphism introduces a slight performance overhead due to the 
   additional indirection required to look up the function in the vtable. However, 
   this overhead is generally negligible compared to the benefits of flexibility 
   and maintainability that dynamic polymorphism provides.

10. Dynamic polymorphism is a powerful feature of C++ that enables flexible and 
    extensible code through runtime method resolution, allowing developers to 
    implement polymorphic behavior in their applications.

11. In the above example, we created a base class Account with a virtual function 
    withdraw(). The derived classes Checking, Savings, and Trust override the 
    withdraw() function to provide their specific implementations.

12. In the main() function, we created base class pointers pointing to derived
    class objects. When we called the withdraw() function using these pointers,
    the appropriate derived class version of the function was executed based on
    the actual object type at runtime, demonstrating dynamic polymorphism.

13. Finally, we deleted the objects using the base class pointers. Since the base
    class destructor is virtual, the derived class destructors were called first,
    followed by the base class destructor, ensuring proper cleanup of resources.
****************************************************************************************/