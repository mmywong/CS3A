#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iomanip>
#include "mypanelopengl.h"

using namespace std;

void init(int world[max_row][max_col]);
void infinite(int world[max_row][max_col]);
void readfile(int world[][max_col], int ui, int uj, char filename[]);
void savefile(int world[max_row][max_col]);
int CountNeighbors(int world[max_row][max_col], int row, int col);
void GetNextGen(int world[max_row][max_col], int world2[max_row][max_col]);
void Convert(int i, int j, int x, int y);
void clearSet(int world[max_row][max_col]);
void Random(int world[max_row][max_col]);

void clearSet(int world[max_row][max_col])
{
    for(int i=0; i<max_row; i++)
        for(int j=0; j<max_col; j++)
            world[i][j]=0;
}

//takes a .txt file, reads it and places the text into
//the 2D array starting from world[1][1] to world[max_row-1][max_col-1]
void readfile(int world[max_row][max_col], int ui, int uj, char filename[])
{
    ifstream in;
    //read config file
    in.open(filename);

    //load pattern file into array:
    for(int i=ui; i<max_row-1; i++)
    {
        for(int j=uj; j<max_col-1; j++)
        {
            in>>world[i][j];
        }
    }
    in.close();
}

//initializes the world and sets everything to 0
void init(int world[max_row][max_col])
{
    for(int i = 0; i < max_row; i++)
        for(int j = 0; j < max_col; j++)
            world[i][j] = 0;
}

//takes what array has and saves it into .txt file
void savefile(int world[max_row][max_col])
{
    ofstream out;
    out.open("savefile.txt");
    for(int i=1; i<max_row-1; i++)
    {
        for(int j=1; j<max_col-1; j++)
        {
            out<<setw(3)<<world[i][j];
        }
        out<<endl;
    }
    //close file
    out.close();
}

//counts the number of neighbors surrounding one location
int CountNeighbors(int world[max_row][max_col], int row, int col)
{
    int neighbors = 0;
    for(int i = (row-1); i < (row+2); i++)
    {
        for(int j = (col-1); j < (col+2); j++)
            neighbors += world[i][j];
    }
    if(world[row][col] == 1)
        neighbors -= 1;
    return neighbors;
}

//step function which gets the next generation
void GetNextGen(int world[max_row][max_col], int world2[max_row][max_col])
{
    infinite(world);
    for(int j=0; j<max_col; j++)
    {
        for (int i=0; i<max_row; i++)
        {
            int totalNeighbors = CountNeighbors(world,i,j);
            switch(totalNeighbors)
            {
                case 2: if(world[i][j] == 1)
                            world2[i][j] = 1;
                        else
                            world2[i][j] = 0;
                        break;

                case 3: world2[i][j] = 1;
                        break;

                default: world2[i][j] = 0;
             }
          }
    }
    for(int i=0; i<max_row; i++)
        for(int j=0; j<max_col; j++)
            world[i][j]=world2[i][j];
}

//creates infinite loop by copying the borders
void infinite(int world[max_row][max_col])
{
    world[0][0]=world[max_row-2][max_col-2]; //set top left corner of gutter
    world[max_row-1][max_col-1]=world[1][1]; //set bottom right corner of gutter
    world[max_row-1][0]=world[1][max_col-2]; //set bottom left corner of gutter
    world[0][max_col-1]=world[max_row-2][1]; //set top right corner of gutter
    for(int i=1; i<max_row-1; i++)
    {
        world[i][0] = world[i][max_col-2];
        world[i][max_col-1] = world[i][1];
    }
    for(int j=1; j<max_col-1; j++)
    {
        world[0][j] = world[max_row-2][j];
        world[max_row-1][j] = world[1][j];
    }
}

void Random(int world[max_row][max_col])
{
    for(int i = 1; i < max_row-2; i++)
    {
        for(int j = 1; j < max_col-2 ; j++)
        {
            world[i][j] = rand()%2;
        }
    }
}

#endif // GAMEOFLIFE_H
