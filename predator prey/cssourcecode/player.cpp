#include "player.h"
#include <iostream>
using namespace std;

player::player()
{
    position = randomspace();
//    identity = ' '; // check, not sure.
    playermoved = false;
    steps = 0;
}

player::player(coord pos, char name)
{
    position = pos;
    identity = name;
    playermoved = false;
    steps = 0;
//    world[pos.i][pos.j] = new player() ????
}

void player::move(player *world[maxrow][maxcol])
{
}

void player::recruit(player *world[maxrow][maxcol])
{
}

void player::fired(player *world[maxrow][maxcol])
{
}

coord player::findspace(player *world[maxrow][maxcol], coord pos)
{
    coord spaces[8];
    int index = 0;
    srand (time(NULL));

    for(int si=pos.i-1; si<pos.i+2; si++)
    {
        for(int sj=pos.j-1; sj<pos.j+2; sj++)
        {
            if(world[si][sj]==NULL)
            {
                spaces[index].i=si;
                spaces[index].j=sj;
                index++;
            }
        }
    }

    if(index==0)
    {
        coord nospace(-1,-1);
        return nospace;
    }

    int randomcoor = (rand()%(index));
    return spaces[randomcoor];
}

//void player::setplayer(player *world[maxrow][maxcol])
//{
//    for(int i = 0; i < maxrow; i++)
//    {
//        for(int j = 0; j < maxcol; j++)
//        {
//            coord pos(i,j);
//            world[i][j] = new player(pos, getIdentity());
//        }
//    }
//}

coord player::randomspace()
{
    coord randspot(rand()%maxrow, rand()%maxcol);
    return randspot;
}

coord player::getPosition() const
{
    return position;
}

void player::setPosition(coord newposition)
{
    position = newposition;
}

int player::getSteps() const
{
    return steps;
}

void player::incSteps()
{
    steps++;
}

bool player::getMoveStatus()
{
    return playermoved;
}

void player::setMoveStatus(bool status)
{
    playermoved = status;
}

