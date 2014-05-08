#include "terrorist.h"
#include <iostream>
using namespace std;

terrorist::terrorist(coord pos) : player(pos)
{
    identity = 't';
}

terrorist::~terrorist()
{
}

void terrorist::move(player *world[maxrow][maxcol])
{
    incSteps();
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
//    cout << "terrorist steps : " << getSteps() << endl;

}

void terrorist::recruit(player *world[maxrow][maxcol])
{
    coord currentspot = getPosition();
    coord emptyspace = findspace(world,currentspot);
    world[emptyspace.i][emptyspace.j] = new terrorist(emptyspace);
}
