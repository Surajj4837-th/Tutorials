//C++11/OperatorOverloadingBinary.cpp
//Binary operator overloading in C++11

#include <iostream>

using std::cout;
using std::endl;

class Point
{
	int XCoord;
	int YCoord;

public:
	Point(): XCoord(0), YCoord(0)
	{
	}

	Point(int x, int y): XCoord(x), YCoord(y)
	{
	}

	int getX()const
	{
		return this->XCoord;
	}

	int getY()const
	{
		return this->YCoord;
	}

	Point operator+(const Point& ob);
	friend Point operator-(const Point& ob1, const Point& ob2);

};//End of class

//Class member operator function
Point Point ::operator+(const Point& ob)
{
	Point temp;
	temp.XCoord = this->XCoord + ob.XCoord;
	temp.YCoord = this->YCoord + ob.YCoord;

	return temp;
}

//Global operator function
Point operator-(const Point& ob1, const Point& ob2)
{
	Point temp;
	temp.XCoord = ob1.XCoord - ob2.XCoord;
	temp.YCoord = ob1.YCoord - ob2.YCoord;

	return temp;
}

int main()
{
	Point P1(2,4);
	Point P2(4,6);

	Point P3;

	P3 = P1 + P2;		//conversion-> P1.operator+(P2);

	cout << P3.getX() << ", " << P3.getY() << endl;

	Point P4 = P3 - P1;		//Conversion-> operator-(P3, P1);

	cout << P4.getX() << ", " << P4.getY() << endl;

	cin.get();
	return 0;
}

/************************************Summary*****************************************
1. In unary operator LHS object will invoke the function and RHS object will be passed
   as parameter.

2.	Number of arguments as per operator function scope and type of operator:
								  Member Function				Friend Function (Global)
	Unary Operator (Prefix)			0 Arguments						1 Argument
	Unary Operator (Postfix)		1 Argument						2 Arguments
	Binary Operator					1 Argument						2 Arguments
************************************************************************************/