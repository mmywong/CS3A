#ifndef COUNTERTERRORIST_H
#define COUNTERTERRORIST_H
#include "player.h"
#include "constants.h"

//"predator"

class counterterrorist : public player
{
public:
    counterterrorist(coord pos);
    ~counterterrorist();
    void move(player* world[maxrow][maxcol]);
    void recruit(player* world[maxrow][maxcol]); // breed
    void fired(player* world[maxrow][maxcol]); // starve
    void kill(player* world[maxrow][maxcol]); // eat

    bool missionfailed();
    coord findterrorist(player* world[maxrow][maxcol], coord currentspot);
private:
    int afk; // how many steps without kills
};

#endif // COUNTERTERRORIST_H
