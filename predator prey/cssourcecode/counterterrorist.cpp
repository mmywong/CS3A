#include "counterterrorist.h"
#include <iostream>

using namespace std;

counterterrorist::counterterrorist(coord pos) : player(pos), killcount(0), killstep(0)
{
    identity = 'c';
}

counterterrorist::~counterterrorist()
{
}

void counterterrorist::move(player *world[maxrow][maxcol])
{
    incSteps();
//    cout << "initial killstep : " << killstep << endl;
//    cout << "initial killcount : " << killcount << endl;
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

    if((getMoveStatus()==false) && (terroristlocation != nospace)) // terrorist is found
    {

        kill(world);
        setMoveStatus(true);
    }
//    else
//        killstep--;
    currentspot = getPosition();
    if((getMoveStatus()==false) && (emptyspace != nospace)) // an empty space is found to move
    {
        world[emptyspace.i][emptyspace.j] = world[currentspot.i][currentspot.j];
        world[currentspot.i][currentspot.j] = NULL;
//        incSteps(); // moved to the beginning of fx
        setMoveStatus(true);
    }

    if(getSteps()%8 == 0)
        recruit(world);
    if((killstep>3) && (killcount == 0))
        fired(world);

    //***DEBUG***//
//    cout << "step : " << getSteps() << endl;
//    cout << "killstep : " << killstep << endl;
//    cout << "killcount : " << killcount << endl;
//    cout << "================================" << endl;
}

void counterterrorist::recruit(player *world[maxrow][maxcol])
{
    coord currentspot = getPosition();
    coord emptyspace = findspace(world,currentspot);
    world[emptyspace.i][emptyspace.j] = new counterterrorist(emptyspace);
}

void counterterrorist::fired(player *world[maxrow][maxcol])
{
    coord currentspot = getPosition();
    delete world[currentspot.i][currentspot.j];
    world[currentspot.i][currentspot.j] = NULL;
    // what is my identity now? player still a CT ?
    // test:
//    this->identity = '#';
    //passed test. nvm.
}

void counterterrorist::kill(player *world[maxrow][maxcol])
{
    coord currentspot = getPosition();
    coord terroristlocation = findterrorist(world,currentspot);
    //T spot taken over by CT
    //delete terrorist first before moving CT there
    delete world[terroristlocation.i][terroristlocation.j] ;
    world[terroristlocation.i][terroristlocation.j] = world[currentspot.i][currentspot.j];
    //empty CT's previous location
    world[currentspot.i][currentspot.j] = NULL;
    this->setPosition(terroristlocation);
    incSteps();
    setMoveStatus(true);
//    resetKillCount();
    killcount++;
    killstep = 0;
}

coord counterterrorist::findterrorist(player *world[maxrow][maxcol], coord currentspot)
{
    coord plotpoint[8];
    int index = 0;
    for(int li=(currentspot.i-1); li<(currentspot.i+2); li++){
        for(int lj=(currentspot.j-1); lj<(currentspot.j+2); lj++){
            if(world[li][lj]){
                if(world[li][lj]->identity == 't'){
                    plotpoint[index].i = li;
                    plotpoint[index].j = lj;
                    index++;
                }
            }
        }
    }

    if(index==0){
        coord nospace(-1,-1);
        return nospace;
    }
    else
    {
        coord temp = plotpoint[rand()%(index)]; // just for debug
//        cout << "plotpoint 1, i : " << temp.i << endl;
//        cout << "plotpoint 1, j : " << temp.j << endl;
//        return plotpoint[ rand()%(index) ]; //ORIGINAL LINE
        return temp;
    }
}

void counterterrorist::resetKillCount()
{
    killcount = 0;
}

void counterterrorist::resetKillStep()
{
    killstep = 0;
}

