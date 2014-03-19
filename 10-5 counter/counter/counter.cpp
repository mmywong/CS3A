#include "counter.h"

counter::counter()
{
    value = 0;
}

counter::counter(int new_value)
{
    if(new_value >= 0)
         value = new_value;
}

void counter::set(int new_value)
{
    if(new_value >=0)
        value = new_value;
}

void counter::increase()
{
    value += 1;
}

void counter::decrease()
{
    if(value >= 1)
        value -= 1;
}

int counter::get()
{
    return value;
}

//bool counter::neg()
//{
//    if(value < 0)
//        return true;
//    else
//        return false;
//}

void counter::print(ostream &out)
{
    out<<value;
}
