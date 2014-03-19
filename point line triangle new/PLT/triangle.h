#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "line.h"
#include <cmath>

class triangle
{
public:
    triangle();
    triangle(int Ax, int Ay, int Bx, int By, int Cx, int Cy);
    double area();
    double angle(line AB, line BC, line CA);
    double perimeter();
    bool equiangular();
    bool isoceles();
    bool righttriangle();

private:
    line AB;
    line BC;
    line CA;
    double s;
};

#endif // TRIANGLE_H
