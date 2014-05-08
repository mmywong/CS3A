#ifndef COORD_H
#define COORD_H

class coord
{
public:
    coord();
    coord(int newi, int newj);

    bool operator == (const coord &right);
    bool operator != (const coord &right);
    void operator = (const coord &right);

    int i;
    int j;
};

#endif // COORD_H
