#ifndef SORTEDLIST_H
#define SORTEDLIST_H
#include "list.h"

class SortedList : public list
{
public:
    SortedList                      ();
    SortedList                      (list sortthis);
    void InsertSorted               (int num);
//    void Sort                       ();
    void Sort                       (list sortthis);
    //CHECK THIS :
    list operator +=                (int i); // inserts i in a sorted list
    list Merge                      (list a, list b); // merges two sorted lists
private:
    Iterator head;
};

//=======================functions=====================//
SortedList::SortedList():
    list()
{
    head = NULL;
}

/*
 int a = 10;
 int a(10);
 SortedList List2(list1); */
SortedList::SortedList(list sortthis)
{
    Sort(sortthis);
}

//---sort---//
void SortedList::Sort(list sortthis) // calls insert sorted until everything is inserted
{
    list newlist;
    Iterator marker = head;
    newlist.InsertHead(head->item);

    marker = marker->next; // check this later
    while(marker != NULL) { //marker is to iterate current class's nodes
//        newlist.InsertSorted(marker->item);
        newlist.InsertSorted(head->item); // potential bug: repeats first node twice because w1 hasn't moved
        Delete(head); // here, before delete, "head should be set to the next node"
        marker = marker->next;
    }
    head = newlist.head;
    newlist.head = NULL;
    cout << "reach" << endl;

}

void SortedList::InsertSorted(int num) // inserts one node
{

    Iterator newmarker = head;
    while((newmarker != NULL) && (num < newmarker->item))
        newmarker = newmarker->next;

    if(num < newmarker->item)
        InsertBefore(newmarker, num);
    else // value is greater than
        InsertAfter(newmarker, num);
    newmarker = head;
}



#endif // SORTEDLIST_H
