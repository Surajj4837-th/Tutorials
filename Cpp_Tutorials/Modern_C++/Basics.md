# Basics

## Namespace
1. Used to avoid name conflicts between diffent library contents.
2. Scope resolution operator ::.
3. Types of use:
   1. Explicitely use namespace. Eg. `std::cout`.
   2. Use entire namespace by delaring the namespace in beginning. Eg. `using namespace std;`.
   3. Use only a specific funciton. Eg. `using std::cout;`.

# I/O
1. cout, cin, cerr, and clog are objects representing streams.
2. cout: standard output stream.
3. cin: standard input stream.
4. <<: insertion operator.
5. \>>: extraction operator.


## Variables and Constatnts
1. C++ primitive types
   1. integer: signed, unsigned, short, long and long long.
   2. floating point: float, double and long double.
   3. boolean
   4. character
   5. sizeof  

Declaring variables, rules:  
1. Can contain letters, numbers and underscores.
2. Must begin with a letter or underscore.
3. Cannot begin with a number.
4. Cannot use C++ reserved keywords.
5. Cannot redeclare a name in the same scope.
6. C++ is case  sensitive.

## Initializing
```C++
int age;        // uninitialized
int age = 21;   // C-like initialization
int age (21);   // Constructor initialization
int age {21};   // C++11 list initialization syntax
```