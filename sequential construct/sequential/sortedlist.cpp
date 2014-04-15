#include "sortedlist.h"

SortedList::SortedList():
    list()
{
    head = NULL;
}

/*
 int a = 10;
 int a(10);
 SortedList List2(list1); */

//---sort---//
void list::Sort() // calls insert sorted until everything is inserted
{
    list newlist;
    node* marker = head;
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

void list::InsertSorted(int num) // inserts one node
{
    node* newmarker = head;
    while((newmarker != NULL) && (num < newmarker->item))
        newmarker = newmarker->next;

    if(num < newmarker->item)
        InsertBefore(newmarker, num);
    else // value is greater than
        InsertAfter(newmarker, num);
    newmarker = head;
}
