#ifndef POLYNODE_H
#define POLYNODE_H

template <class T>
struct polynode{
    T item;
    polynode<T>* next;
};
#endif // POLYNODE_H
