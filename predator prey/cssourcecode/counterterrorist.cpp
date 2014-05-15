#include "counterterrorist.h"
#include <iostream>

using namespace std;

counterterrorist::counterterrorist(coord pos) : player(pos), afk(0)
{
    identity = 'c';
}

counterterrorist::~counterterrorist()
{
}

void counterterrorist::move(player *world[maxrow][maxcol])
{
    //possible actions : move normally, recruit, fired, kill
    incSteps();
    coord currentspot = getPosition();
    coord emptyspace = findspace(world,currentspot);
    coord nospace(-1,-1);
    coord terroristlocation = findterrorist(world,currentspot);

    if((getMoveStatus()==false) && (terroristlocation != nospace)) // terrorist is found
    {
        kill(world);
        setMoveStatus(true);
    }
    else
        afk++;

    //***DEBUG***//
    cout << "step : " << getSteps() << endl;
    cout << "afk status : " << afk << endl;
    cout << "mission failed?" << missionfailed() << endl;
    cout << "================================" << endl;

    currentspot = getPosition();
    if((getMoveStatus()==false) && (emptyspace != nospace)) // an empty space is found to move
    {
        world[emptyspace.i][emptyspace.j] = world[currentspot.i][currentspot.j];
        world[currentspot.i][currentspot.j] = NULL;
        setMoveStatus(true);
    }

    if(getSteps()%8 == 0)
        recruit(world);
    if(missionfailed())
    {
        fired(world);
        afk = 0;
    }
}

void counterterrorist::recruit(player *world[maxrow][maxcol])
{
    coord currentspot = getPosition();
    coord emptyspace = findspace(world,currentspot);
    world[emptyspace.i][emptyspace.j] = new counterterrorist(emptyspace);
}

void counterterrorist::fired(player *world[maxrow][maxcol])
{
    cout << "fired" << endl;
    coord currentspot = getPosition();
    delete *world[currentspot.i][currentspot.j];
    world[currentspot.i][currentspot.j] = NULL;
    cout << "my identity after getting fired : " << this->identity << endl;
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
    world[terroristlocation.i][terroristlocation.j] = this;
    //empty CT's previous location
    world[currentspot.i][currentspot.j] = NULL;
    this->setPosition(terroristlocation);
    setMoveStatus(true);
    afk = 0;
}

bool counterterrorist::missionfailed()
{
    if(afk == 3)
        return true;
    else
        return false;
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
