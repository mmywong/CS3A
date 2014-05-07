#include "terrorist.h"

terrorist::terrorist() : player::player()
{
    setIdentity('t'); //maybe not needed cause of other constructor
}

terrorist::terrorist(coord pos, char identity)
{
    setIdentity(identity);
    setPosition(pos);
}

void terrorist::move(player *world[maxrow][maxcol])
{
    setMoveStatus(true);

    coord nospace(-1,-1);
    coord currentspot = getPosition();

//    if(currentspot == nospace) // currentspot is at (-1,-1) because a coord hasn't been set for terrorist yet //revision: impossible because all T's have been initialized
//        return;

    coord emptyspace = findspace(world,currentspot);

    //check -1
    if(emptyspace == nospace)
        return;
    else //if not -1
    {
        world[emptyspace.i][emptyspace.j] = world[getPosition().i][getPosition().j];
        world[getPosition().i][getPosition().j] = NULL;
    }

    incSteps();
}

void terrorist::recruit(player *world[maxrow][maxcol])
{

}
