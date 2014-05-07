#include "map.h"

Map::Map()
{
    for(int i = 0; i < maxrow; i++)
        for(int j = 0; j < maxcol; j++)
            world[i][j] = 0;
}

void Map::read(char filename[])
{
    ifstream in;
    in.open(filename);
    for(int i=0; i<maxrow; i++)
    {
        for(int j=0; j<maxcol; j++)
        {
            in>>world[i][j];
        }
    }
    in.close();
}

void Map::save()
{
    ofstream out;
    out.open("savefile.txt");
    for(int i=0; i<maxrow; i++)
    {
        for(int j=0; j<maxcol; j++)
        {
            out<<setw(3)<<world[i][j];
        }
        out<<endl;
    }
    //close file
    out.close();
}

void Map::step()
{

}


void Map::init()
{
    for(int i = 0; i < maxrow; i++)
        for(int j = 0; j < maxcol; j++)
            world[i][j] = 0;
}

