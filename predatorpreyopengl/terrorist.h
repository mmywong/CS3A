#ifndef TERRORIST_H
#define TERRORIST_H

//---libraries for opengl---//
//#include <iostream>
//#include <stdio.h>      /* printf, NULL */
//#include <stdlib.h>
//#include <time.h>
//#include <fstream>
//#include <iomanip>
//#include "mypanelopengl.h"
//--------------------------//
#include "player.h"
#include "constants.h"
//"prey"

class terrorist : public player
{
public:
    terrorist(coord pos);
    ~terrorist();
    void move(player* world[maxrow][maxcol]);
    void recruit(player* world[maxrow][maxcol]); //breed
};

#endif // TERRORIST_H
