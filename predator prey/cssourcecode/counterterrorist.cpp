#include "counterterrorist.h"
#include <iostream>
using namespace std;

counterterrorist::counterterrorist() : player::player()
{
    setIdentity('c');
}

counterterrorist::counterterrorist(coord pos)
{
    setIdentity('c');
    setPosition(pos);
    cout << this->getIdentity() <<endl;
}

void counterterrorist::move(player *world[maxrow][maxcol])
{
    coord currentspot = getPosition();
    coord emptyspace = findspace(world,currentspot);
    coord nospace(-1,-1);
    //check -1
    if(emptyspace == nospace)
        return;
    else
    {
    //if not -1
        world[emptyspace.i][emptyspace.j] = world[getPosition().i][getPosition().j];
        world[getPosition().i][getPosition().j] = NULL;
    }
}

void counterterrorist::recruit(player *world[maxrow][maxcol])
{

}

void counterterrorist::fired(player *world[maxrow][maxcol])
{

}

