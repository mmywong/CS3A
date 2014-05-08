#include "counterterrorist.h"
#include <iostream>
using namespace std;

counterterrorist::counterterrorist() : player::player()
{
    killcount = 0;
    killstep = 0;
    identity = 'c'; //maybe not needed because of other constructor
}

counterterrorist::counterterrorist(coord pos, char newidentity)
{
    killcount = 0;
    killstep = 0;
    identity = newidentity;
//    setIdentity(identity);
    setPosition(pos);
}

void counterterrorist::move(player *world[maxrow][maxcol])
{
    //options : move normally, recruit, fired, kill
    //if step%8==0 , recruit
    //if killstep >3 && killcount = 0, fired (delete or set to null)
    //if  surrounding has a t, kill the t
    //else move normally
    //move and recruit first. then if flag is still false, decide to fire or kill
    coord currentspot = getPosition();
    coord emptyspace = findspace(world,currentspot);
    coord nospace(-1,-1);
    coord terroristlocation = findterrorist(world,currentspot);

    if(terroristlocation != nospace) // terrorist is found
    {
        kill(world);
    }
    if(emptyspace != nospace) // an empty space is found to move
    {
        world[emptyspace.i][emptyspace.j] = world[currentspot.i][currentspot.j];
        world[currentspot.i][currentspot.j] = NULL;
        incSteps();
        setMoveStatus(true);
        killstep++;
    }

    if(getSteps()%8 == 0)
        recruit(world);

    if((killstep>3) && (killcount == 0))
        fired(world);
    else // not fired
        killstep++;
}

void counterterrorist::recruit(player *world[maxrow][maxcol])
{
    coord currentspot = getPosition();
    coord emptyspace = findspace(world,currentspot);
    world[emptyspace.i][emptyspace.j] = new counterterrorist(emptyspace, 'c');
}

void counterterrorist::fired(player *world[maxrow][maxcol])
{
    coord currentspot = getPosition();
    world[currentspot.i][currentspot.j] = NULL;
}

void counterterrorist::kill(player *world[maxrow][maxcol])
{
    coord currentspot = getPosition();
    coord terroristlocation = findterrorist(world,currentspot);
    //T spot taken over by CT
    world[terroristlocation.i][terroristlocation.j] = world[currentspot.i][currentspot.j];
    //empty CT's previous location
    world[currentspot.i][currentspot.j] = NULL;
    incSteps();
    setMoveStatus(true);
    resetKillCount();
    killcount++;
    killstep++;
}

coord counterterrorist::findterrorist(player *world[maxrow][maxcol], coord currentspot)
{
    coord spaces[8];
    int index = 0;
    srand (time(NULL));

    for(int li=currentspot.i-1; li<currentspot.i+2; li++)
    {
        for(int lj=currentspot.j-1; lj<currentspot.j+2; lj++)
        {
            if(world[li][lj]->identity == 't')
            {
                spaces[index].i=li;
                spaces[index].j=lj;
                index++;
            }
            else if(world[li][lj]->identity == 'c')
            {
            }
            else
            {
            }
        }
    }

    if(index==0)
    {
        coord nospace(-1,-1);
        return nospace;
    }
    else
    {
        int randomcoor = (rand()%(index));
        return spaces[randomcoor];
    }
}

void counterterrorist::resetKillCount()
{
    killcount = 0;
}

