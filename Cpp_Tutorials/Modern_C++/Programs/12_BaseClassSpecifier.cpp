// Modern_C++/Programs/12_BaseClassSpecifier.cpp
// Base class references in C++17
#include <iostream>

// This class uses dynamic polymorphism for the withdraw method
// We'll learn about virtual functions in the next video
class Account 
{
public:
    virtual void withdraw(double amount) 
    {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account() 
    {  }
};

class Checking: public Account  
{
public:
    virtual void withdraw(double amount) 
    {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual ~Checking() 
    {  }
};

class Savings: public Account  
{
public:
    virtual void withdraw(double amount) 
    {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() 
    {  }
};

class Trust: public Account  
{
public:
    virtual void withdraw(double amount) 
    {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() 
    {  }
};

void do_withdraw(Account &account, double amount) 
{
    account.withdraw(amount);
}

int main()
{
    Account a;
    Account &ref = a;
    ref.withdraw(1000); // In Account::withdraw

    Trust t;
    Account &ref1 = t;
    ref1.withdraw(1000); // In Trust::withdraw

    Account a1;
    Savings a2;
    Checking a3;
    Trust a4;

    do_withdraw(a1, 1000); // In Account::withdraw
    do_withdraw(a2, 2000); // In Savings::withdraw
    do_withdraw(a3, 3000); // In Checking::withdraw
    do_withdraw(a4, 4000); // In Trust::withdraw

    return 0;
}

/************************************Summary****************************************
1. In addition to base class pointer we can also use base class references to achieve 
   polymorphism.

2. Useful when we pass objects to functions that expect base class references.

3. The base class references are used instead of base class pointers to take advantage 
   of the references:
   a. We don't have to check for nullptr.
   b. We don't have to use the dereference operator (*).
   c. We don't have to use the address of operator (&) when passing arguments.
   d. Lifetime of references is managed automatically, in contrast to pointers where
      we have to manage memory manually.

4. Base class references can be more intuitive and easier to read in certain contexts,
   especially when dealing with function parameters.

5. Both base class pointers and references can be used to achieve polymorphism,
   and the choice between them often depends on the specific use case and coding style.
***********************************************************************************/