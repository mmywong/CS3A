#ifndef POLYGON_H
#define POLYGON_H
#include "coord.h"
#include <iostream>

class polygon
{
public:
    polygon();
    polygon(int n, coord* v);
    void setvertices(int n, coord* v);


    coord* vertices;
    int numofvertices;
//    friend ostream& operator <<(ostream& out, const& polygon); // what does this do? show the polygon? weird for paint
};

#endif // POLYGON_H
