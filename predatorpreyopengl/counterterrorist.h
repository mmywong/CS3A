#ifndef COUNTERTERRORIST_H
#define COUNTERTERRORIST_H

//---libraries for opengl---//
#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iomanip>
#include "mypanelopengl.h"
//-------------------------//

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

    coord findterrorist(player* world[maxrow][maxcol], coord currentspot);
    void resetKillCount();
private:
    int killcount; // how many kills
    int killstep; // how many steps since last kill
};

#endif // COUNTERTERRORIST_H
