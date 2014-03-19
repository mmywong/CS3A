#ifndef LINE_H
#define LINE_H
#include "point.h"

class line
{
public:
    line(); // the constructor
    line(point P, point Q);
    double length();
    double slope();
    double x_intercept();
    double y_intercept();
private:
    point P; // will make P of type "point" kinda~
    point Q;
};

#endif // LINE_H
