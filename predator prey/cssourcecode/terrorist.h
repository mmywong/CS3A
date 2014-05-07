#ifndef TERRORIST_H
#define TERRORIST_H
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
