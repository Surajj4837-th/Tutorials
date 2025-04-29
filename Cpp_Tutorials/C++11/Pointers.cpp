// Pointers
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int x{ 5 };
    std::cout << x << '\n';  // print the value of variable x
    std::cout << &x << '\n'; // print the memory address of variable x

    std::cout << *(&x) << '\n'; 

    int* ptr1 = &x;  //int pointer
    int& ref1 = x;  //int reference
    
    cout << typeid(&x).name() << '\n';  //prints "Pi" means pointer to integer.

    //null pointers
    int* ptr2 {};
    int* ptr3 = nullptr;


    //----------------------------------Pointer to const value----------------------------------
    const int y{ 5 };
    const int* ptr4 { &y };      //pointer to const

    //*ptr4 = 6;    // not allowed: we can't change a const value



    //----------------------------------const pointer----------------------------------
    //A const pointer is a pointer whose address can not be changed after initialization.
    int z{ 5 };
    int* const ptr5 { &z }; // const after the asterisk means this is a const pointer
    //ptr5 = &x; //ERROR
    z = 10; //Allowed


    //----------------------------------void pointer----------------------------------
    void* voidPtr; // ptr is a void pointer
    int nValue;
    float fValue;
    short sValue;

    voidPtr = &nValue; // valid
    voidPtr = &fValue; // valid
    voidPtr = &sValue; // valid

    // std::cout << *voidPtr << '\n'; // illegal: dereference of void pointer

    int* intPtr{ static_cast<int*>(voidPtr) };  //type casting should be used for dereferencing.

    //voidPtr++; //ILLIGAL

    
    //----------------------------------pointer to a pointer----------------------------------
    int** ptrptr; // pointer to a pointer to an int
    int val = 90;
    int* ptr = &val;
    ptrptr = &ptr;

    cout << **ptrptr << endl;   //dereferencing a pointer to a pointer



    //----------------------------------arrays of pointer----------------------------------
    int** array { new int*[10] }; // allocate an array of 10 int pointers
    //int** array { new int[10][5] }; // WON'T WORK

    //This will work
    for (int count { 0 }; count < 10; ++count)
        array[count] = new int[5];


    //Deallocation also requires loop
    for (int count{0}; count < 10; ++count)
        delete[] array[count];

    delete[] array; // this needs to be done last

    return 0;
}
/************************************Summary*****************************************
1. A pointer is an object that holds a memory address as its value.

2. A pointer that has not been initialized is sometimes called a wild pointer. Wild 
   pointers contain a garbage address, and dereferencing a wild pointer will result 
   in undefined behavior.

3. Pointers and lvalue references behave similarly.

4. Pointer size is machine dependent. If the m/c is 32 bit then pointer size is 32 bits
   i.e. 4 bytes, if m/c is 64 bit then pointer size is 8 bytes.

5. A dangling pointer is a pointer that is holding the address of an object that is no 
   longer valid.

6. When a pointer is holding a null value, it means the pointer is not pointing at 
   anything. Such a pointer is called a null pointer.

7. Pointers have the ability of being able to change what they are pointing at, and 
   to be pointed at null.

8. A pointer to const is a pointer that points to a constant value.

9. A const pointer is a pointer whose address can not be changed after initialization.

10. A non-const pointer can be assigned another address to change what it is pointing at 

11. A const pointer always points to the same address, and this address can not be changed.

12. A pointer to a non-const value can change the value it is pointing to. These can 
    not point to a const value.

13. A pointer to a const value treats the value as const when accessed through the pointer
    and thus can not change the value it is pointing to. These can be pointed to const 
    or non-const l-values (but not r-values, which don’t have an address)

14. Dereferencing a void pointer is illegal. Type casting should be used for dereferencing.

15. It is not possible to do pointer arithmetic on a void pointer. This is because pointer 
    arithmetic requires the pointer to know what size object it is pointing to, so it 
    can increment or decrement the pointer appropriately.

16. You can not set a pointer to a pointer directly to a value. This is because the 
    address of operator(&) requires an lvalue, but &value is an rvalue.

17. Allocation of memory to a 2D array of pointer requires a loop and so does deallocation.

18. Because allocating and deallocating two-dimensional arrays is complex and easy to 
    mess up, it’s often easier to “flatten” a two-dimensional array of size x by y
    into a one-dimensional array of size x * y.
************************************************************************************/