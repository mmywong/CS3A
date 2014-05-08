#include "terrorist.h"

terrorist::terrorist() : player::player()
{
    identity = 't';
//    setIdentity('t'); //maybe not needed cause of other constructor
}

terrorist::terrorist(coord pos)
{
    identity = 't';
//    setIdentity(identity);
    setPosition(pos);
}

void terrorist::move(player *world[maxrow][maxcol])
{
    coord nospace(-1,-1);
    coord currentspot = getPosition();
    coord emptyspace = findspace(world,currentspot);

    if((getMoveStatus()==false) && (emptyspace != nospace))
    {
        world[emptyspace.i][emptyspace.j] = world[currentspot.i][currentspot.j];
        world[currentspot.i][currentspot.j] = NULL;
        if(getSteps()%3 == 0)
            world[emptyspace.i][emptyspace.j]->recruit(world);
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
