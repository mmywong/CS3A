#ifndef COUNTERTERRORIST_H
#define COUNTERTERRORIST_H
#include "player.h"

//"predator"

class counterterrorist : public player
{
public:
    counterterrorist();
    void move();
    void recruit();
    void fired();
    void show();
private:

};

#endif // COUNTERTERRORIST_H
