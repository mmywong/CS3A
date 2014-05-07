#ifndef COUNTERTERRORIST_H
#define COUNTERTERRORIST_H

//---libraries for opengl---//
#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iomanip>
#include "mypanelopengl.h"
//-------------------------//

#include "player.h"

//"predator"

class counterterrorist : public player
{
public:
    counterterrorist();
    void move();
    void recruit();
    void fired();
private:

};

#endif // COUNTERTERRORIST_H
