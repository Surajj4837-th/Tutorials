//Template
#include <iostream>

using std::cout;
using std::endl;

//Function template
template <typename T>
T myMax(T x, T y)
{
    T ans = (x > y) ? x : y;
    return ans;
}


//Class template
template <typename T> 
class Array 
{
private:
    T* ptr;
    int size;

public:
    Array(T arr[], int s);
    void print();
};

template <typename T> 
Array<T>::Array(T arr[], int s)
{
    ptr = new T[s];
    size = s;
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
}

template <typename T> 
void Array<T>::print()
{
    for (int i = 0; i < size; i++)
        cout << " " << *(ptr + i);
    cout << endl;
}

//More than 1 argument to template
template <class T, class U> 
class A 
{
    T x;
    U y;

public:
    A(T x, U y) 
    { 
        cout << "Constructor Called: " << x << ", " << y << endl; 
    }
};


//Default data types
template <class T, class U = char> 
class B
{
    T x;
    U y;

public:
    B(T x, U y = 'a')
    {
        cout << "Constructor Called: " << x << ", " << y << endl;
    }
};


//template with non-type argument
template <class T, int max> 
int arrMin(T arr[], int n)
{
    int m = max;
    for (int i = 0; i < n; i++)
        if (arr[i] < m)
            m = arr[i];

    return m;
}



//template classs and constructor
template <class T> 
class info 
{
public:

    info(T A)
    {
        cout << "A = " << A << " size of data in bytes:" << sizeof(A) << endl;
    }

};


int main()
{
    // Call myMax for int
    cout << myMax<int>(3, 7) << endl;

    // call myMax for double
    cout << myMax<double>(3.0, 7.0) << endl;

    // call myMax for char
    cout << myMax<char>('g', 'e') << endl;


    //-----------------------------------------------------------------

    //template class
    int arr1[5] = { 1, 2, 3, 4, 5 };
    float arr2[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    
    Array<int> a1(arr1, 5);
    Array<float> a2(arr2, 5);

    a1.print();
    a2.print();
    
    //-----------------------------------------------------------------


    //template with multiple arguments
    A<char, char> A1('a', 'b');
    A<int, double> A2(1, 2.2);

    //-----------------------------------------------------------------


    //template with default data types
    B<int> b(90);

    //-----------------------------------------------------------------


    //function with non-type argument
    int arr3[] = { 10, 20, 15, 12};

    int n1 = sizeof(arr3) / sizeof(arr3[0]);

    char arr4[] = { 1, 2, 3 };
    int n2 = sizeof(arr4) / sizeof(arr4[0]);

    // Second template parameter to arrMin must be a constant
    cout << arrMin<int, 13>(arr3, n1) << endl;
    cout << arrMin<char, 256>(arr4, n2) << endl;

    //-----------------------------------------------------------------


    //Class template and constructor which accepts any data type.
    // passing character value by creating an objects
    info<char> p('x');

    // passing integer value by creating an object
    info<int> q(22);

    // passing float value by creating an object
    info<float> r(2.25);

    return 0;
}
/************************************Summary*****************************************
1. Code reusability is implementaed using template.

2. There are 2 types of templates : 
    - Function template
    - Class template

3. Templates are expanded at compiler time. Compiler does type-checking before template
   expansion. Source code contains only function/class, but compiled code may contain
   multiple copies of the same function/class.

4. Template function can be used for user defined data type if > operator is overloaded.

5. We can specify default data types to the template.

6. When there is a static variable in a template class/fundtion then each instance of 
   the template will contain its own static variable.

7. The typename can be replaced with class.

8. Non-type values can be passed as argument to a template, these must be consants and 
   are mainly used to specify a threshold or a useful value in a logic.

9. Similar to regular classes the template class functions can be declared in class body 
   and can be defined outside.

10. Function overloading is used when multiple functions do similar operations whereas
    template is used when the functions do same operation.

11. Function overloading can take varying numbers of arguments.	Templates cannot take 
    varying numbers of arguments.
************************************************************************************/