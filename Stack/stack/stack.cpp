#include "stack.h"

stack::stack() : list()
{
}

void stack::Push(int i)
{
    InsertHead(i);
}

int stack::Pop()
{
    node* walker = Begin();
    int temp = walker->item;
    list::Delete(walker);
    return temp;
}

int stack::Top() const
{
    return *(Begin());
}

bool stack::Empty() const
{
    return list::isEmpty();
}

void stack::Print() const
{
    list::Print();
}
