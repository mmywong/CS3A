#ifndef LINE_H
#define LINE_H
#include "point.h"

class Line{
public:
    Line(); // the constructor
    int length(int x, int y);
    int slope(int x, int y);
private:
    Point P; // will make P of type "point" kinda~
    Point Q;
};

#endif // LINE_H
