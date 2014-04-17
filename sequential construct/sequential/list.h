#ifndef LIST_H
#define LIST_H
#include "iterator.h"
#include <iostream>

using namespace std;

template <class T>
class list
{
public:
    list                            ();

    //---big three---//
    list                            (list<T> &copythis); // copy constructor
    const list<T> &operator =       (list<T>& right); //assignment operator
    ~list                           ();  //destructor

    //---create---//
    void InsertHead                 (T num);//must return a node*
    void InsertAfter                (Iterator<T> marker, T num); // makes a node to the right of marker's node
    void InsertBefore               (Iterator<T> marker, T num); // makes a node to the left of marker's node
    void Append                     (T num); // makes a node at the very end of the list

    //---delete---//``
    T Delete                        (Iterator<T> marker); // returns the item you deleted

    //---search---//
    int Search                      (T key);

    //---show---//
    void Print                      () const;

    //---change---//
    T &operator []                  (int index);

    //---sort---//
//    void InsertSorted               (int num);
//    void Sort                       ();

    //---new lists---//
    void Reverse                    ();

    //---markers---//
    Iterator<T> Begin                  ();
    Iterator<T> End                    ();
    Iterator<T> Ithnode                (int i);
    int IthElement                     (); // returns the item of IthNode
//    Iterator Previous               ();

private:
    //---node ---//
    //public fx should not have node* everywhere
    //private fx can have node* because user has no access
    //use these node* in private to write public functions
    void InsertAfter                (node<T>* marker, T num); // makes a node to the right of marker's node
    void InsertBefore               (node<T>* marker, T num); // makes a node to the left of marker's node
    T Delete                        (node<T>* marker);
    node<T>* Remove                 (node<T>* marker);
    node<T>* nEnd                   ();
    //node* WhereThisGoes(int i);


    node<T>* head;
};

//=============functions==============//
//---constructor---//
template <class T>
list<T>::list()
{
    head = NULL;
}

//---big three---//
//memory leak as well
template <class T>
list<T>::list(list<T> &copythis)
{
    InsertHead(copythis.head->item);
    node<T>* marker = copythis.head;
    node<T>* marker2 = head;
    head->next = NULL;
    marker = marker->next;
    while(marker != NULL)
    {
        Append(marker->item);
        marker = marker->next;
        marker2 = marker2->next;
    }
}

//memory leak. what if A is not empty / contains nodes which haven't been deleted
// delete extra nodes. e.g. 4nodes = 5 nodes.
//problem : only reassigned the head. what about the floating nodes we don't have access to?
template <class T>
const list<T> &list<T>::operator =(list<T> &right)
{
    InsertHead(right.head->item);
    node<T>* marker = right.head;
    node<T>* marker2 = head;
    head->next = NULL;
    marker = marker->next;
    while(marker != NULL)
    {
        Append(marker->item);
        marker = marker->next;
        marker2 = marker2->next;
    }
}

template <class T>
list<T>::~list()
{
    while(head)
    {
        Delete(head);
    }
    head = NULL;
    /*
     node<T>* marker = nEnd();
     while(marker != head)
     {
         delete marker;
         marker = nEnd();
     }
     delete marker;
     head = NULL;
    */
}

//---create---//
template <class T>
void list<T>::InsertHead(T num)
{
    node<T>* temp = new node<T>;

    temp->item = num;
    temp->next = head;
    head = temp;
}

template <class T>
void list<T>::InsertAfter(Iterator<T> marker, T num)
{
    node<T>* temp = new node<T>;
    temp->item = num;
    temp->next = marker.nodeptr->next;
    marker.nodeptr->next = temp;
}

template <class T>
void list<T>::InsertBefore(Iterator<T> marker, T num)
{
//    if(marker = head)
//        return NULL;
    node<T>* temp = new node<T>;
    node<T>* walker = head;
    temp->item = num;

    while((walker->next != marker.nodeptr) && (walker->next != NULL))
        walker = walker->next;
    temp->next = walker->next;
    walker->next = temp;
}

template <class T>
void list<T>::Append(T num)
{
    Iterator<T> marker = End();
    InsertAfter(marker, num);
}

//---delete---//
template <class T>
node<T>* list<T>::Remove(node<T> *marker)
{
    node<T>* walker = head;

    if(marker == head) // case that you want to remove head
        head = head->next;
    else // case that you want to remove something from pos 1 onwards
    {
        while(walker->next != marker && walker->next != NULL) // finds the position before marker
            walker = walker->next;
        walker->next = marker->next; // makes the previous point at the node after marker
    }
    marker->next = NULL;
    return marker;
}

template <class T>
T list<T>::Delete(Iterator<T> marker)
{
    Delete(marker.nodeptr);
}

template <class T>
T list<T>::Delete(node<T> *marker)
{
    int temp = marker->item;
    delete Remove(marker);
    return temp;
}

template <class T>
int list<T>::Search(T key)
{
    int pos = 0;
    node<T>* marker = head;
    while((marker != NULL) && (marker->item != key))
    {
        marker = marker->next;
        pos++;
    }
    if(marker == NULL)
        return -1; // not found
    return pos; // if item is found
}

//---show---//
template <class T>
void list<T>::Print() const
{
    node<T>* walker = head;
    while(walker != NULL)
    {
        cout<<"["<<walker->item<<"]-->";
        walker = walker->next;
    }
    cout << "||||";
}

template <class T>
T &list<T>::operator [](int index)
{
    return Ithnode(index).nodeptr->item;
    /* is the same as doing this :
    Iterator temp = Ithnode(index);
    return temp.nodeptr->item;
    */
}

template <class T>
void list<T>::Reverse()
{
    node<T>* first = head;
    node<T>* last = nEnd();
    list<T> newlist;

    newlist.InsertHead(Delete(last));

    while(first != NULL)
    {
        InsertAfter(newlist.head, Delete(last));
        last = nEnd();
    }
    head = newlist.head;
}

//---markers---//
template <class T>
Iterator<T> list<T>::Begin()
{
    return Iterator<T>(head);
}

template <class T>
node<T>* list<T>::nEnd()
{
    node<T>* walker = head;
    while(walker->next != NULL)
        walker = walker->next;
    return walker;
}

template <class T>
Iterator<T> list<T>::End()
{
    return Iterator<T>(nEnd());
}

template <class T>
Iterator<T> list<T>::Ithnode(int i)
{
    node<T>* walker = head;
    for(int j=0; j<i; j++)
       walker = walker->next; // makes walker point at the node we want
    return Iterator<T>(walker); // returns the address of the Ith node
}

template <class T>
void list<T>::InsertAfter(node<T> *marker, T num)
{
    node<T>* temp = new node<T>;
    temp->item = num;
    temp->next = marker->next;
    marker->next = temp;
}

template <class T>
void list<T>::InsertBefore(node<T> *marker, T num)
{
    node<T>* temp = new node<T>;
    node<T>* walker = head;
    temp->item = num;

    while((walker->next != marker) && (walker->next != NULL))
        walker = walker->next;
    temp->next = walker->next;
    walker->next = temp;
}

/*
template <class T>
Iterator list<T>::WhereThisGoes(int i)
{
    node<T>* marker = head;
    while((marker != NULL) && (i < marker->item))
        marker = marker->next;
}*/


#endif // LIST_H
