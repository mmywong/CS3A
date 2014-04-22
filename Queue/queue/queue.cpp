#include "queue.h"

queue::queue()
{
}

void queue::EnQueue(int &i)
{
    InsertHead(i);
}

int queue::DeQueue()
{
    Iterator marker = End();
    int num = *marker;
    Delete(marker);
    return num;
}

bool queue::isEmpty()
{
    return list::isEmpty();
}
