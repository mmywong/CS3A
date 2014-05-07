#ifndef PLAYER_H
#define PLAYER_H

class player
{
public:
    player();
    virtual void move();
    virtual void recruit(); // breed
    virtual void fired(); // starve
};

#endif // PLAYER_H
