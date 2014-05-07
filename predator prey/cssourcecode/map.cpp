#include "map.h"

map::map()
{
    for(int i=0; i<maxrow; i++)
        for(int j = 0; j<maxcol; j++)
            world[i][j] = NULL;
}

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

void map::step()
{

}

void map::show()
{
    for(int i=0; i<maxrow; i++)
        for(int j = 0; j<maxcol; j++)
        {
            if()
        }
}

void map::initialize()
{

}

bool map::hasmoved()
{

}
