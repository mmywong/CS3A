#include "map.h"

Map::Map()
{
    for(int i=0; i<maxrow; i++)
        for(int j = 0; j<maxcol; j++)
            world[i][j] = NULL;

    coord spot(1,2);
    counterterrorist CT1;
    counterterrorist CT2(spot);
    world[1][2] = CT2;
}

//void Map::read()
//{
//    for(int i = 0; i < maxrow; i++)
//        for (int j = 0; j < maxrow; j++)
//            world[i][j] = new player()
//}

//void map::read(char filename[])
//{
//    ifstream in;
//    in.open(filename);
//    for(int i=0; i<maxrow; i++)
//    {
//        for(int j=0; j<maxcol; j++)
//        {
//            in>>world[i][j];
//        }
//    }
//    in.close();
//}

void Map::step()
{
//    for(int i = 0; i < maxrow; i++)
//    {
//        for(int j = 0; j < maxcol; j++)
//        {
//            world[i][j] = new
//        }
//    }
}

void Map::show()
{
    for(int i = 0; i < maxrow; i++)
    {
        for(int j = 0; j < maxcol; j++)
        {
            if(world[i][j] == NULL)
                cout << "   ";
            else // print according to identity
                cout << " "<< world[i][j]->getIdentity() << " ";
        }
        cout << endl << endl;
    }
}

void Map::initialize()
{
    for(int i=0; i < maxrow; i++)
    {
        coord left(i,0);
        coord right(i,maxcol-1);
        world[i][0] = new player(left, '#');
        world[i][maxcol-1] = new player(right, '#');
    }
    for(int j = 0; j < maxcol; j++)
    {
        coord top(0,j);
        coord bot(maxrow-1,j);
        world[0][j] = new player(top, '#');
        world[maxrow-1][j] = new player(bot, '#');
    }
}

bool Map::hasmoved()
{
    for(int i = 0; i < maxrow; i++)
        for(int j = 0; j < maxcol; j++)
            if(world[i][j]->getMoveStatus() == false) // if not everyone moved
                return false;
    return true;
}



