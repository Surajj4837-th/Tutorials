//Pure virtual functions and abstract classesss
#include <iostream>
#include <vector>

class Shape 			// Abstract Base class
{
private:
       // attributes common to all shapes
public:
      virtual void draw() = 0;	 // pure virtual function
      virtual void rotate() = 0;   // pure virtual function
      virtual ~Shape() { }
};

class Open_Shape: public Shape     // Abstract class
{
public:
    virtual ~Open_Shape() { }
};

class Closed_Shape : public Shape   // Abstract class
{
public:
    virtual ~Closed_Shape() { };
};

class Line: public Open_Shape      // Concrete class
{
public:
    virtual void draw() override 
    {
        std::cout << "Drawing a line" << std::endl;
    }

    virtual void rotate() override 
    {
        std::cout << "Rotating a line" << std::endl;
    }

    virtual ~Line() {}
};

class Circle: public Closed_Shape      // Concrete class
{
public:
    virtual void draw() override 
    {
        std::cout << "Drawing a circle" << std::endl;
    }

    virtual void rotate() override 
    {
        std::cout << "Rotating a circle" << std::endl;
    }

    virtual ~Circle() {}
};

class Square: public Closed_Shape      // Concrete class
{
public:
    virtual void draw() override 
    {
        std::cout << "Drawing a square" << std::endl;
    }

    virtual void rotate() override 
    {
        std::cout << "Rotating a square" << std::endl;
    }

    virtual ~Square() {}
};


void DrawAllShapes(const std::vector<Shape *> &shapes) 
{
    std::cout << "Refreshing" << std::endl;
    for (const auto p: shapes) 
        p->draw();
}

int main() 
{
    // Shape s;                     // Error: cannot instantiate abstract class
    // Shape *p = new Shape();      // Error: cannot instantiate abstract class

    Circle c;
    c.draw();

    Shape *ptr = new Circle();
    ptr->draw();
    ptr->rotate();

    Shape *s1 = new Circle();
    Shape *s2 = new Line();
    Shape *s3 = new Square();
    
    std::vector<Shape *> shapes {s1,s2,s3};
        
    DrawAllShapes(shapes);
    
    delete s1;
    delete s2;
    delete s3;

    delete ptr;
    
    return 0;
}

/************************************Summary****************************************
1. Abstract classes cannot be instantiated. These are used as base classes. Also referred
   abstract base classes. Its derived classes can instantiate objects.

2. The classes which can be instantiated are called as concrete classes. All its member
   functions are defined.

3. Abstract base class must have at least 1 pure virtual function. Pure virtual function 
   makes the class abstract.

4. Pure virtual fucntions do not have any implementation.

5. Derived classes must override the pure virtual function. If it does not do that
   then it also becomes an abstract class.

6. In order to be useful the pure virtual function must be declared as public.

7. The application of abstract classes is to provide an interface. For example there
   is a draw function needed in every shape class. So we can declare a pure virtual
   function draw in the base class Shape. 
   If we want to print any information of the objects then print function can be 
   declared as pure virtual function in the base class. This will ensure that every 
   derived class must implement the print function.
***********************************************************************************/