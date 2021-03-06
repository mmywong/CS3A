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

    bool missionaccomplished();
    coord findterrorist(player* world[maxrow][maxcol], coord currentspot);
    void resetKillCount();
    void resetKillStep();
private:
    int killcount; // how many kills
    int killstep; // how many steps since last kill
};

#endif // COUNTERTERRORIST_H
