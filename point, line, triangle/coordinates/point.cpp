#include <cmath>
#include <iostream>
#include "point.h"

Point::Point() // runs Point. runs every time you create a new obj. the constructor, the "main" of the class
{
    Set(0,0);
}

Point::Point(int new_x, int new_y) //overloading our constructor. cause what if we want to change x and y when we create the point
{
    Set(new_x, new_y);
}

double Point::distance(Point A)
{
  sqrt(pow((this->x-A.x),2) + pow((y-A.y),2)); // here, the first x refers to the x of "P" (who calls this fx)
                                        //, A.x refers to the value of the inputted argument
}

void Point::Set(int new_x, int new_y)
{
    SetX(new_x);
    SetY(new_y);
}

void Point::SetX(int new_x) // opposite of get. this is input
{
    x = new_x;
}

void Point::SetY(int new_y)
{
    y = new_y;
}

void Point::Show()
{
    cout << "(" << x << "," << y << ")" << endl;
}

int Point::GetX() // point here refers to the header file, means that GetX is a member of Point
{
    return x; //because x is a member of x, it will know what x is (x is a global for the class)
}

int Point::GetY() // reads/receives. does not create
{
    return y;
}
