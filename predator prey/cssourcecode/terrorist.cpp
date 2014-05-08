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
    //WOW, there's memory leak here
    //Say i put something here
    coord nospace(-1,-1);
    coord currentspot = getPosition();
    coord emptyspace = findspace(world,currentspot);

    if((getMoveStatus()==false) && (emptyspace != nospace))
    {
        world[emptyspace.i][emptyspace.j] = world[getPosition().i][getPosition().j];
        world[getPosition().i][getPosition().j] = NULL;
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
