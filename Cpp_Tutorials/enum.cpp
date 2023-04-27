//Enum
#include <iostream>

using std::cout;
using std::endl;

void main()
{
	enum season { spring, summer, autumn, winter };	//enum declaration
	// enum name - season
	// spring, summer and winter are values of type season.
	// By default, spring is 0, summer is 1 and so on. 


	//default values of enum elements can be changes during declaration
	enum season2
	{
		spring2 = 10,
		summer2 = 4,
		autumn2 = 8,
		winter2 = 12
	} season_list;	//declare variable

	//create enum variable
	season2 season_list2;


	enum week { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
	week today = Wednesday;
	cout << "Day " << today + 1 << endl;

	//Size of enum
	cout << sizeof(week) << endl << sizeof(season2) << endl;

	int my_week = Sunday | Tuesday;
	cout << my_week << endl;

	//various integer types can be declared explicitely for saving memory
	enum gender : unsigned char
	{
		Male,
		Female
	};


	//Multiple values can be assigned to an enum variable by using values of power of 2
	enum drink
	{
		Water = 1,
		Lemon_juice = 2,
		Beer = 4,
		Wine = 8
	};

	//Casting is required to do OR operation
	drink Person1 = static_cast<drink>(static_cast<int>(drink::Water) | static_cast<int>(drink::Lemon_juice));

	cout << "Drink order of Person1: " << Person1 << endl;

}
/************************************Summary*****************************************
1. An enumeration is a user-defined data type that is generally used when you expect 
   the variable to select one value from the possible set of values.

2. An enum variable takes only one value out of many possible values. This makes enum 
   a good choice to work with flags.

3. enum variable is of int type and thus has size of 4 bytes.

4. By default, the starting code value of the first element of the enum is 0. But it 
   can be changed explicitly.

5. Enum can also be used to assign multiple values to the variable by using values of 
   power of 2.
************************************************************************************/