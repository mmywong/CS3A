#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

template <class T>
class queue : protected list<T>
{
public:
    queue();
    void EnQueue            (T i);
    T DeQueue               ();
    bool Empty              ();
    void Print              () const;
};

template <class T>
queue<T>::queue()
{
}

template <class T>
void queue<T>::EnQueue(T i)
{
    list<T>::InsertHead(i);
}

template <class T>
T queue<T>::DeQueue()
{
    Iterator<T> marker = list<T>::End();
    T num = *marker;
    list<T>::Delete(marker);
    return num;
}

template <class T>
bool queue<T>::Empty()
{
    return list<T>::isEmpty();
}

template <class T>
void queue<T>::Print() const
{
    list<T>::Print();
}

#endif // QUEUE_H
