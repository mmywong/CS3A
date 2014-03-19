#include "countertype.h"

countertype::countertype()
{

}

countertype::countertype(int new_value)
{
    limit = new_value;
}

void countertype::set(int new_value)
{
    value = new_value;
}

void countertype::increase()
{

}

void countertype::decrease()
{

}

int countertype::get()
{
    return value;
}

void countertype::print(ostream &out)
{

}
