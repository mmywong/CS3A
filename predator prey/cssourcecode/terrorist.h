#ifndef TERRORIST_H
#define TERRORIST_H
#include "player.h"
#include "constants.h"
//"prey"

class terrorist : public player
{
public:
    terrorist(coord pos);
    void move(player* world[maxrow][maxcol]);
    void recruit(player* world[maxrow][maxcol]); //breed
};

#endif // TERRORIST_H
