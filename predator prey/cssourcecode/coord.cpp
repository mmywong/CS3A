#include "coord.h"

coord::coord()
{
}

coord::coord(int newi, int newj)
{
    i = newi;
    j = newj;
}

bool coord::operator ==(const coord &right)
{
    if((i == right.i) && (j == right.j))
        return true;
    else
        return false;
}

bool coord::operator !=(const coord &right)
{
    if((i == right.i) && (j == right.j))
        return false;
    else
        return true;
}

void coord::operator =(const coord &right)
{
    j = right.j;
    i = right.i;
}
