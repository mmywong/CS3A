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
//"grid" / "world"
using namespace std;

class Map
{
public:
    Map();
    void read(char filename[]);
    void save();
    void step();
//    void show();
    void init();
private:
    int world[maxrow][maxcol];
};

#endif // MAP_H
