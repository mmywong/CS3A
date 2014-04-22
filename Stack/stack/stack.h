#ifndef STACK_H
#define STACK_H
#include "../../../CS3A/sequential construct/sequential/list.h"

template<class T>
class list;

class stack : public list
{
public:
    stack();
    void Push                       (int i);
    int Pop                         ();
    int Top                         () const;
    bool Empty                      () const;
    void Print                      () const;
};

#endif // STACK_H
