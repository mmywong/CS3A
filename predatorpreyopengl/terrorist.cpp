#include "terrorist.h"


terrorist::terrorist(coord pos) : player(pos)
{
    identity = 't';
}

terrorist::~terrorist()
{
    delete this;
    //note : should I start from 0 to max or from 1 to max-1?
//    for(int i = 0; i < maxrow; i++)
//        for(int j = 0; j < maxcol; j++)
//            delete world[i][j];
}

void terrorist::move(player *world[maxrow][maxcol])
{
    coord nospace(-1,-1);
    coord currentspot = getPosition();
    //you forgot to update your position somewhere?
    coord emptyspace = findspace(world,currentspot);

    if((getMoveStatus()==false) && (emptyspace != nospace))
    {
        setPosition(emptyspace); // update the pos
        world[emptyspace.i][emptyspace.j] = this;
        world[currentspot.i][currentspot.j] = NULL;
        if(getSteps()%3 == 0)
           recruit(world);
        setMoveStatus(true);
    }
    incSteps();
}

void terrorist::recruit(player *world[maxrow][maxcol])
{
    coord currentspot = getPosition();
    coord emptyspace = findspace(world,currentspot);
    world[emptyspace.i][emptyspace.j] = new terrorist(emptyspace);
}
