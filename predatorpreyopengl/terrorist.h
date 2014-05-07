#ifndef TERRORIST_H
#define TERRORIST_H

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
//"prey"

class terrorist : public player
{
public:
    terrorist();
    void move();
    void recruit();
};

#endif // TERRORIST_H
