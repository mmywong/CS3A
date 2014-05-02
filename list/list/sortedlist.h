#ifndef SORTEDLIST_H
#define SORTEDLIST_H
#include "list.h"

template <class T>
class SortedList : public list<T>
{
public:
    SortedList                      ();
    SortedList                      (const list<T> sortthis);
    void Sort                       (list<T> sortthis);
    void Insert                     (T num);

//    void InsertAfter                (Iterator<T> marker, T num); // makes a node to the right of marker's node
//    void InsertBefore               (Iterator<T> marker, T num); // makes a node to the left of marker's node

    //CHECK THIS :
    list<T> operator +=                (int i); // inserts i in a sorted list
    SortedList<T> Merge                (list<T> a, list<T> b); // merges two sorted lists
private:
//    Iterator<T> head;
//    void InsertHead                 (T num);//must return a node*
//    void Append                     (T num); // makes a node at the very end of the list

};

//=======================functions=====================//
template <class T>
SortedList<T>::SortedList():
    list<T>::list()
{
}

/*
 int a = 10;
 int a(10);
 SortedList List2(list1); */
template <class T>
SortedList<T>::SortedList(list<T> sortthis)
{
    Sort(sortthis);
}

//---sort---//
template <class T>
void SortedList<T>::Sort(list<T> sortthis) // calls insert sorted until everything is inserted
{
    Iterator<T> listwalker = sortthis.Begin();
    SortedList temp;

//    temp.list<T>::InsertHead(*listwalker);
//    listwalker = listwalker.Next();

//    if(listwalker.IsNull())
//        cout << "listwalker null";
//    else
//        cout << "value : " << *listwalker << endl;
    //DEBUG//



    while(listwalker.IsNull() == false)
    {
        temp.Insert(*listwalker);
        listwalker = listwalker.Next();
    }
    *this = temp;
//    list newlist;
//    Iterator marker = head;
//    newlist.InsertHead(head->item);

//    marker = marker->next; // check this later
//    while(marker != NULL) { //marker is to iterate current class's nodes
/*       newlist.InsertSorted(marker->item);  */
//        newlist.InsertSorted(head->item); // potential bug: repeats first node twice because w1 hasn't moved
//        Delete(head); // here, before delete, "head should be set to the next node"
//        marker = marker->next;
//    }
//    head = newlist.head;
//    newlist.head = NULL;
//    cout << "reach" << endl;

}

template <class T>
void SortedList<T>::Insert(T num) // inserts one node
{
    Iterator<T> sortwalker = list<T>::Begin();
    if(sortwalker.IsNull())
            list<T>::InsertHead(num);
    else
    {
        while((sortwalker.IsNull()==false) && (num > *sortwalker))
            sortwalker = sortwalker.Next();
        if(sortwalker.IsNull())
            list<T>::Append(num);
        else /*if (num < *sortwalker)*/
            list<T>::InsertBefore(sortwalker, num);
    }
}

template <class T>
SortedList<T> SortedList<T>::Merge(list<T> a, list<T> b)
{
    SortedList<T> mergedlist;
    SortedList<T> acopy(a);
    SortedList<T> bcopy(b);

    Iterator<T> awalker = acopy.Begin();
    while(!(acopy.isEmpty()))
    {
        mergedlist.Insert(SortedList<T>::Delete(awalker));
        awalker = awalker.Next();
    }

    Iterator<T> bwalker = bcopy.Begin();
    while(!(bcopy.isEmpty()))
    {
        mergedlist.Insert(SortedList<T>::Delete(bwalker));
        bwalker = bwalker.Next();
    }

    Sort(mergedlist);
    return mergedlist;
}





#endif // SORTEDLIST_H
