#ifndef SORTEDLIST_H
#define SORTEDLIST_H
#include "list.h"

class SortedList : public list
{
public:
    SortedList();
    void InsertSorted               (int num);
    void Sort                       ();

    //CHECK THIS :
    list operator +=                (int i); // inserts i in a sorted list
    list Merge                      (list a, list b); // merges two sorted lists
private:
    Iterator head;
};

#endif // SORTEDLIST_H
