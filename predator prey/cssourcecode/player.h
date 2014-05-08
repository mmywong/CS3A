#ifndef PLAYER_H
#define PLAYER_H
#include "coord.h"
#include "constants.h"
#include <ctime>
#include <stdlib.h>

class player
{
public:
    player(coord pos);
    virtual void move(player* world[maxrow][maxcol]);
    virtual void recruit(player* world[maxrow][maxcol]); // breed
    virtual void fired(player* world[maxrow][maxcol]); // starve

    coord findspace(player* world[maxrow][maxcol], coord pos);
//    void setplayer(player* world[maxrow][maxcol]);
    coord randomspace();

    //getters and setters, private member modifiers//
    coord getPosition() const;
    void setPosition(coord newposition);
//    char getIdentity();
//    void setIdentity(char newidentity);
    int getSteps() const;
    void incSteps();
    bool getMoveStatus();
    void setMoveStatus(bool status);
    char identity;
private:
    coord position;
    int steps;
    bool playermoved;
};

#endif // PLAYER_H
