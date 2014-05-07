#ifndef COUNTERTERRORIST_H
#define COUNTERTERRORIST_H
#include "player.h"
#include "constants.h"

//"predator"

class counterterrorist : public player
{
public:
    counterterrorist();
    counterterrorist(coord pos);
    void move(player* world[maxrow][maxcol]);
    void recruit(player* world[maxrow][maxcol]); // breed
    void fired(player* world[maxrow][maxcol]); // starve
    void kill(player* world[maxrow][maxcol]); // eat
private:

};

#endif // COUNTERTERRORIST_H
