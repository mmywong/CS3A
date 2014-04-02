#include "Iterator.h"
#include <iostream>

Iterator::Iterator()
{
    nodeptr = NULL;
}

Iterator::Iterator(node *p)
{
    nodeptr = p;
}

Iterator::Iterator(const Iterator &p){
    nodeptr = p.nodeptr;
}

bool Iterator::IsNull() const
{
    if(nodeptr == NULL)
        return true;
    else
        return false;
}


bool Iterator::operator ==(const Iterator& itr)
{
    if(nodeptr == itr.nodeptr)
        return true;
    else
        return false;
}

int& Iterator::operator *() //pass by reference so that the value is changed (note case : *Iterator = 100)
{
    return nodeptr->item;
}

Iterator Iterator::operator ++(int) // postfix
{
    Iterator tempitr;
    tempitr.nodeptr = nodeptr;
    nodeptr = nodeptr->next;
    return tempitr;
}

Iterator &Iterator::operator ++() // prefix
{
    nodeptr = nodeptr->next;
    return *this;
}

Iterator Iterator::Next() const
{
    Iterator itr;
    itr.nodeptr = itr.nodeptr->next;
    return itr;
}
