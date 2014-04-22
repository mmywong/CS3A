#include "polygon.h"

polygon::polygon()
{
}

polygon::polygon(int n, coord *v)
{
    numofvertices = n;
    vertices = v;
}

void polygon::setvertices(int n, coord *v)
{
    numofvertices = n;
    vertices = v;
}
