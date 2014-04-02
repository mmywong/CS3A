#include "iterator.h"
#include <iostream>

iterator::iterator()
{
    nodeptr = NULL;
}

bool iterator::IsNull()
{
    if(iterator.nodeptr == NULL)
        return true;
    else
        return false;
}

iterator iterator::Next()
{
    nodeptr = nodeptr->next;
    return nodeptr;
}

bool iterator::operator ==(const iterator& itr1, const iterator& itr2)
{
    if(itr1.nodeptr == itr2.nodeptr)
        return true;
    else
        return false;
}

int iterator::operator *()
{
    return nodeptr->item;
}

iterator iterator::operator ++(iterator itr, int i)
{
    int counter = 0;
    while(counter != i)
    {
        itr.nodeptr = itr.nodeptr->next;
        counter++;
    }
    return itr;
}

iterator iterator::operator ++(iterator &itr)
{
    itr.nodeptr = itr.nodeptr->next;
    return itr;
}
