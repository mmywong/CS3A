#ifndef QUEUE_H
#define QUEUE_H
#include "../../../CS3A/sequential construct/sequential/list.h"

class queue : public list
{
public:
    queue();
    void EnQueue(int i);
    int DeQueue();
    bool isEmpty();
};

#endif // QUEUE_H
