#include <cmath>
#include <iostream>
#include "point.h"

using namespace std;

point::point() // runs Point. runs every time you create a new obj. the constructor, the "main" of the class
{
    Set(0,0);
}

point::point(int new_x, int new_y) //overloading our constructor. cause what if we want to change x and y when we create the point
{
    Set(new_x, new_y);
}

double point::distance(point A)
{
  return sqrt(pow((x-A.GetX()),2) + pow((y-A.GetY()),2)); // here, the first x refers to the x of "P" (who calls this fx)
                                                     //, A.x refers to the value of the inputted argument
}

void point::Set(int new_x, int new_y)
{
    SetX(new_x);
    SetY(new_y);
}

void point::SetX(int new_x) // opposite of get. this is input
{
    x = new_x;
}

void point::SetY(int new_y)
{
    y = new_y;
}

void point::Show()
{
    cout << "(" << x << "," << y << ")" << endl;
}

int point::GetX() // point here refers to the header file, means that GetX is a member of Point
{
    return x; //because x is a member of x, it will know what x is (x is a global for the class)
}

int point::GetY() // reads/receives. does not create
{
    return y;
}
