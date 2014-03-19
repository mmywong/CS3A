#include <iostream>
#include "line.h"

using namespace std;

line::line(){

}

line::line(Point new_P, Point new_Q)// makes a new line with new point p and q
{
    P.SetX(new_P.x); //using the SetX function which is a member of P. "P.SetX()" is a function
    P.SetY(new_P.y); //new_P.y is the y value of new_P (a new point)
    Q.SetX(new_Q.x);
    Q.SetY(new_Q.y);
}

double line::length() // no need arguments because we know our points. (global)
{
    return P.distance(Q);
}

double line::slope()
{
    return ((P.y-Q.y)/(P.x-Q.x));
}
