// C++11/OperatorOverloadingStreamOperator.cpp
// Overloaded insertion and extraction operators in C++11

#include <iostream>
#include <cstring>

using namespace std;

class Mystring
{
    friend std::ostream& operator<<(std::ostream& os, const Mystring& rhs);
    friend std::istream& operator>>(std::istream& in, Mystring& rhs);

private:
    char* str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                 // No-args constructor
    Mystring(const char* s);                    // Overloaded constructor
    Mystring(const Mystring& source);           // Copy constructor
    Mystring(Mystring&& source);                // Move constructor
    ~Mystring();                                // Destructor

    Mystring& operator=(const Mystring& rhs);   // Copy assignment
    Mystring& operator=(Mystring&& rhs);        // Move assignment

    void display() const;

    int get_length() const;                     // getters
    const char* get_str() const;
};

// No-args constructor
Mystring::Mystring()
    : str{ nullptr } {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char* s)
    : str{ nullptr } {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    }
    else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

// Copy constructor
Mystring::Mystring(const Mystring& source)
    : str{ nullptr } {
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
    std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring(Mystring&& source)
    :str(source.str) {
    source.str = nullptr;
    std::cout << "Move constructor used" << std::endl;
}

// Destructor
Mystring::~Mystring() {
    delete[] str;
}

// Copy assignment
Mystring& Mystring::operator=(const Mystring& rhs) {
    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs)
        return *this;
    delete[] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring& Mystring::operator=(Mystring&& rhs) {
    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs)
        return *this;
    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// getters
int Mystring::get_length() const { return strlen(str); }
const char* Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream& operator<<(std::ostream& os, const Mystring& rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream& operator>>(std::istream& in, Mystring& rhs) {
    char* buff = new char[1000];
    in >> buff;
    rhs = Mystring{ buff };
    delete[] buff;
    return in;
}



int main() {

    Mystring larry{ "Larry" };
    Mystring moe{ "Moe" };
    Mystring curly;

    cout << "Enter the third stooge's first name: ";
    cin >> curly;

    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;

    cout << "\nEnter the three stooges names separated by a space: ";
    cin >> larry >> moe >> curly;

    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;

    return 0;
}

/************************************Summary*****************************************
1. Output

    Enter the third stooge's first name: suraj
    Using move assignment
    The three stooges are Larry, Moe, and suraj

    Enter the three stooges names separated by a space: Suraj Ashish Vrunda
    Using move assignment
    Using move assignment
    Using move assignment
    The three stooges are Suraj, Ashish, and Vrunda
************************************************************************************/