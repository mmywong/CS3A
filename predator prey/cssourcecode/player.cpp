#include "player.h"

player::player()
{
    playermoved = false;
    steps = 0;
}

void player::move()
{

    steps++;

}
coord player::getPosition() const
{
    return position;
}

void player::setPosition(const coord &value)
{
    position = value;
}

