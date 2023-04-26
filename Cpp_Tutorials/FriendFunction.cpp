//Friend Function
#include "Header_FriendFunction.h"

#if 0		//Friend global function declaration and use
class Point
{
	int XCoord;
	int YCoord;

public:
	Point(int x = 0, int y = 0) : XCoord(x), YCoord(y)
	{
	}

	int getX()const
	{
		return XCoord;
	}

	int getY()const
	{
		return YCoord;
	}

	friend int FindDistance(const Point& P1, const Point& P2);
};

int FindDistance(const Point& P1, const Point& P2)
{
	double distance = 0;

	distance = sqrt(((double)P2.XCoord - P1.XCoord) * ((double)P2.XCoord - P1.XCoord)
		+ ((double)P2.YCoord - P1.YCoord) * ((double)P2.YCoord - P1.YCoord));

	return (int)distance;
}

int main()
{
	Point P1(2, 4);
	Point P2(5, 5);

	int dist = FindDistance(P1, P2);

	cout << dist << endl;
	cin.get();
	return 0;
}

#else

#if 0			//Friend class declaration and use

class Point
{
	int XCoord;
	int YCoord;

public:

	Point(int x = 0, int y = 0) : XCoord(x), YCoord(y)
	{
	}

	int getX()const;

	int getY()const;

	//friend int Calculator::FindDistance(const Point& P1, const Point& P2);

	friend class Calculator;

};		//End of Point class

class Calculator
{
	double distance;
public:

	Calculator()
	{
		distance = 0;
	}

	int FindDistance(const Point& P1, const Point& P2);

	void display() const
	{
		cout << distance << endl;
	}

};		//End of class Calculator

int Calculator::FindDistance(const Point& P1, const Point& P2)
{

	distance = sqrt(((double)P2.XCoord - P1.XCoord) * ((double)P2.XCoord - P1.XCoord)
		+ ((double)P2.YCoord - P1.YCoord) * ((double)P2.YCoord - P1.YCoord));

	return (int)distance;
}


int Point::getX()const
{
	return XCoord;
}

int Point::getY()const
{
	return YCoord;
}

int main()
{
	Point P1(2, 4);
	Point P2(5, 5);
	Calculator C1;

	C1.display();

	int dist = C1.FindDistance(P1, P2);
	cout << dist << endl;

	C1.display();

	cin.get();
	return 0;
}
#else		//Declaring just a function of another class as friend

class Point;	//Forward declaration required as Calculator should know the Point class

class Calculator
{
	double distance;
public:

	Calculator()
	{
		distance = 0;
	}

	int FindDistance(const Point& P1, const Point& P2);

	void display() const
	{
		cout << distance << endl;
	}

};		//End of class Calculator

class Point
{
	int XCoord;
	int YCoord;

public:

	Point(int x = 0, int y = 0) : XCoord(x), YCoord(y)
	{
	}

	int getX()const;

	int getY()const;

	//friend int Calculator::FindDistance(const Point& P1, const Point& P2);

	//friend class Calculator;
	friend int Calculator::FindDistance(const Point& P1, const Point& P2);

};		//End of Point class



int Calculator::FindDistance(const Point& P1, const Point& P2)
{

	distance = sqrt(((double)P2.XCoord - P1.XCoord) * ((double)P2.XCoord - P1.XCoord)
		+ ((double)P2.YCoord - P1.YCoord) * ((double)P2.YCoord - P1.YCoord));

	return (int)distance;
}


int Point::getX()const
{
	return XCoord;
}

int Point::getY()const
{
	return YCoord;
}

int main()
{
	Point P1(2, 4);
	Point P2(5, 5);
	Calculator C1;

	C1.display();

	int dist = C1.FindDistance(P1, P2);
	cout << dist << endl;

	C1.display();

	cin.get();
	return 0;
}
#endif

#endif
/************************************Summary*****************************************
1. A friend keyword is used by a non member function to access the private, protected 
   and public members of a class.

2. friend function declaration should be done with keyword 'friend' in class' body.

3. Why to use a friend function?:
   a. Developer do not want to modify a well tested class, so a function is declared a
	  friend function and is used.
   b. If the function to be added is not too related to the class (Design strategy).

4. When a class is declared as a friend then its all functions become friend by default.

5. A friend function can be:
   a. A method of another class
   b. A global function

6. Friends should be used only for limited purposes, too many functions or external
   classes are declared as friends of a class with protected or private data, it lessens
   the value of encapsulation of separate classes in object-oriented programming.

7. Friendship is not mutual. If a class A is friend of B, then B doesn’t become friend
   of A automatically.

8. Friendship is not inherited.

9. When calling just a function of another class as friend then forward declaration is
   necessary. Declaring a function/class/variable before its first appearance is called
   forward declaration.

10. Why forward declaration is necessary?
	The compiler should know no spelling mistake is done or no parameter mismatch is there.

11. Any variable/function/class declaration does not allocate memory. Memory is allocated
	only after definition is encountered.

12. Forward declaration also solves chicken and egg problem where function A requires
	function B and B requires A.
************************************************************************************/