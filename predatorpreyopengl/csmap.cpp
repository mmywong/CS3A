#include "csmap.h"
#include "terrorist.h"
#include "counterterrorist.h"

csmap::csmap()
{
    for(int i=0; i<maxrow; i++)
        for(int j = 0; j<maxcol; j++)
            world[i][j] = NULL;
}

void csmap::step()
{
    setflagsfalse();
    for(int i = 1; i < maxrow-1; i++)
        for(int j = 1; j < maxcol-1; j++)
            if(world[i][j])
                if(world[i][j]->getMoveStatus() == false)
                    world[i][j]->move(world);
}

void csmap::show()
{
    for(int i = 0; i < maxrow; i++)
    {
        for(int j = 0; j < maxcol; j++)
        {
            cout << " ";
            if(world[i][j] == NULL)
                cout << " ";
            else // print according to identity
                cout << world[i][j]->identity;
            cout << " ";
        }
        cout << endl;
    }
}

void csmap::initialize()
{
    for(int i=0; i < maxrow; i++)
    {
        coord left(i,0);
        coord right(i,maxcol-1);
        world[i][0] = new player(left);
        world[i][maxcol-1] = new player(right);
    }
    for(int j = 0; j < maxcol; j++)
    {
        coord top(0,j);
        coord bot(maxrow-1,j);
        world[0][j] = new player(top);
        world[maxrow-1][j] = new player(bot);
    }
}

void csmap::random()
{
    int CTnum = 20;
    int Tnum = 80;
    for(int i = 1; i < CTnum-1; i++)
    {
        coord c_randspot(rand()%(maxrow-2) + 1 , rand()%(maxcol-2) + 1); //between 1 and 19
        world[c_randspot.i][c_randspot.j] = new counterterrorist(c_randspot);
    }
    for(int j = 1; j < Tnum-1; j++)
    {
        coord ct_randspot(rand()%(maxrow-2) + 1, rand()%(maxcol-2) + 1); //between 1 and 19
        world[ct_randspot.i][ct_randspot.j] = new terrorist(ct_randspot);
    }
}

bool csmap::hasmoved()
{
    for(int i = 1; i < maxrow-1; i++)
        for(int j = 1; j < maxcol-1; j++)
            if(world[i][j])
                if(world[i][j]->getMoveStatus() == false) // if not everyone moved
                   return false;
    return true;
}

void csmap::setflagsfalse()
{
    for(int i = 1; i < maxrow-1; i++)
        for (int j = 1; j < maxcol-1; j++)
            if(world[i][j])
                world[i][j]->setMoveStatus(false);
}



