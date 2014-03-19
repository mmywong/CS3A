#include <iostream>
#include "line.h"
using namespace std;

line::line(){

}

line::line(point new_P, point new_Q)// makes a new line with new point p and q
{
    P.SetX(new_P.GetX()); //using the SetX function which is a member of P. "P.SetX()" is a function
    P.SetY(new_P.GetY()); //new_P.y is the y value of new_P (a new point)
    Q.SetX(new_Q.GetX());
    Q.SetY(new_Q.GetY());
}

double line::length() // no need arguments because we know our points. (global)
{
    return P.distance(Q);
}

double line::slope()
{
    return ((1.0*(P.GetY()-Q.GetY()))/(1.0*(P.GetX()-Q.GetX()))); // 1.0* converts this to a double|| Alt: (double)(P.GetY()-Q.GetY())
}

double line::x_intercept()
{
    return (-(y_intercept()/slope()));
}

double line::y_intercept()
{
    double gradient;
    gradient = slope();
    return (P.GetY() - gradient*(P.GetX()));
}
