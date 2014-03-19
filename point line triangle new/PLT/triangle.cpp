#include "triangle.h"

using namespace std;

triangle::triangle()
{
}

triangle::triangle(int Ax, int Ay, int Bx, int By, int Cx, int Cy)
{
    point A(Ax,Ay);
    point B(Bx,By);
    point C(Cx,Cy);

    AB = line(A,B);
    BC = line(B,C);
    CA = line(C,A);
}

double triangle::area()
{
    //using Heron's formula
    double s;// semiperimeter = (a+b+c)/2
    s = (perimeter())/2;
    return (sqrt(s*(s-AB.length())*(s-BC.length())*(s-CA.length())));
}

double triangle::angle(line AB, line BC, line CA)
{
    //assuming angle A is the angle we want to look for
    return(
                (acos((pow(BC.length(),2) + pow(CA.length(),2) - pow(AB.length(),2))/
                (2*BC.length()*CA.length())))
                *(180/M_PI) // converter
           );
}

double triangle::perimeter()
{
    return(AB.length() + BC.length() + CA.length());
}

bool triangle::equiangular()
{
    if(AB.length() == BC.length() && AB.length() == CA.length()) // note: do not do two == in a row
        return true;
    else
        return false;
}

bool triangle::isoceles()  // two equal sides
{
    if(AB.length() == BC.length() || AB.length() == CA.length() || AB.length() == CA.length()) // note: do not do two == in a row
        return true;
    else
        return false;
}

bool triangle::righttriangle()
{
    if(angle(AB,BC,CA) == 90 || angle(BC,CA,AB) == 90 || angle(CA,BC,AB))
        return true;
    else
        return false;
}


