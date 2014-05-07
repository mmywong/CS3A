#ifndef MAP_H
#define MAP_H
#include "player.h"
#include "terrorist.h"
#include "counterterrorist.h"
#include "constants.h"
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

    bool hasmoved(); // tells you if everyone has stepped
private:
    player* world[maxrow][maxcol];
};

#endif // MAP_H
