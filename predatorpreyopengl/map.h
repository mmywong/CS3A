#ifndef MAP_H
#define MAP_H

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
#include "terrorist.h"
#include "counterterrorist.h"
#include "constants.h"
#include "coord.h"
#include <fstream>
#include <iostream>

using namespace std;
//"grid" / "world"
class Map
{
public:
    Map();
    void read();
    void step();
    void show();
    void initialize();
    void random();
    bool hasmoved(); // tells you if everyone has stepped
    void setflagsfalse();
//private:
    player* world[maxrow][maxcol];
};

#endif // MAP_H
