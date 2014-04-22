#ifndef COORD_H
#define COORD_H
#include <iostream>

using namespace std;

class coord
{
public:
    coord();
    coord(float newX, float newY);

    friend ostream& operator <<(ostream& out, const& coord c);
private:
    float x;
    float y;
};

#endif // COORD_H
