#ifndef STACK_H
#define STACK_H
#include "list.h"
//template<class T>
//class list;

template <class T>
class stack : protected list<T>
{
public:
    stack                           ();
    void Push                       (T i);
    T Pop                           ();
    T Top                           ();
    bool Empty                      ();
    void Print                      () const;
};

template <class T>
stack<T>::stack() : list<T>::list()
{
}

template <class T>
void stack<T>::Push(T i)
{
    list<T>::InsertHead(i);
}

template <class T>
T stack<T>::Pop()
{
    Iterator<T> walker = list<T>::Begin();
    T temp = *walker;
    list<T>::Delete(walker);
    return temp;
}

template <class T>
T stack<T>::Top()
{
    return *(list<T>::Begin());
}

template <class T>
bool stack<T>::Empty()
{
    return list<T>::isEmpty();
}

template <class T>
void stack<T>::Print() const
{
    list<T>::Print();
}
#endif // STACK_H
