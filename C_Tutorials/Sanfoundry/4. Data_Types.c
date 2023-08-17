//Data types

#include <stdio.h>

struct empty
{

};

union uni
{
    int a ;
    char b;

}uni_obj;

enum level {
   Low = 10,
   Medium,
   High
};

int main()
{
    //**************************************************************************//
    printf("char: %d bytes\n", sizeof(char));
    printf("short: %d bytes\n", sizeof(short));
    printf("int: %d bytes\n", sizeof(int));
    printf("long: %d bytes\n", sizeof(long));
    printf("long long: %d bytes\n", sizeof(long long));
    printf("float: %d bytes\n", sizeof(float));
    printf("double: %d bytes\n", sizeof(double));
    printf("void: %d bytes\n", sizeof(void));
    printf("size_t: %d bytes\n", sizeof(size_t));

    
    //**************************************************************************//

    struct empty emp;
    printf("empty: %d bytes\n", sizeof(emp));

    printf("uni_obj: %d bytes\n", sizeof(uni_obj));


    uni_obj.a = 9090;
    printf("uni_obj.a: %d\n", uni_obj.a);
    printf("uni_obj.b: %c\n", uni_obj.b);
    

    //**************************************************************************//

    enum level Water_Level;
    Water_Level = Medium;

    printf("Water_Level: %d\n", Water_Level);
    

    //**************************************************************************//
}

/*****************************************OUTPUT***********************************
char: 1 bytes
short: 2 bytes
int: 4 bytes
long: 8 bytes
long long: 8 bytes
float: 4 bytes
double: 8 bytes
void: 1 bytes
size_t: 8 bytes
empty: 0 bytes
uni_obj: 4 bytes
uni_obj.a: 9090
uni_obj.b: �
Water_Level: 11
***********************************************************************************/

/************************************Summary****************************************
1. Data types are classified in 3 ways:

   Primitive: char, int, short, long, float, double, void, size_t, long long.
   User defined: struct, union, enum, typedef.
   Derived: array, pointer, function pointer, 

2. void was used as return type of some funtions, like malloc which returned memory of 
   type void hence a type casting is required after using malloc.

3. union stores the memory equal to largest variable of its members. Thus only 1 member 
   can store the sata at a time.

4. Enum is a data type used to debote state of a situation. The default value of 1st 
   variable is 0 and rest  carry ou the ascending values.

5. In 64bit machine long and long long are same data type as both are 8 byte long. 

************************************************************************************/
