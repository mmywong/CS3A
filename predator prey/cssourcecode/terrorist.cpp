#include "terrorist.h"


terrorist::terrorist(coord pos) : player(pos)
{
    identity = 't';
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
