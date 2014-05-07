#ifndef PLAYER_H
#define PLAYER_H
#include "coord.h"

class player
{
public:
    player();

    virtual void move();
    virtual void recruit(); // breed
    virtual void fired(); // starve
    virtual void show();

    coord position;
    coord getPosition() const;
    void setPosition(const coord &value);

private:

    int steps;
    bool playermoved;
};

#endif // PLAYER_H
