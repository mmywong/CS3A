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
    coord nospace(-1,-1);
    coord currentspot = getPosition();
    coord emptyspace = findspace(world,currentspot);

    if(getSteps()%3 == 0)
        recruit(world);
    if(emptyspace != nospace)
    {
        world[emptyspace.i][emptyspace.j] = world[getPosition().i][getPosition().j];
        world[getPosition().i][getPosition().j] = NULL;
        setMoveStatus(true);
    }
    incSteps();
}

void terrorist::recruit(player *world[maxrow][maxcol])
{
    coord currentspot = getPosition();
    coord emptyspace = findspace(world,currentspot);
    world[emptyspace.i][emptyspace.j] = new terrorist(emptyspace, 't');
}
