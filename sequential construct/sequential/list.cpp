#include "list.h"
#include "Iterator.h"
#include <iostream>

using namespace std;

//---constructor---//
list::list()
{
    head = NULL;
}

//---big three---//
list::list(list &copythis)
{
    InsertHead(copythis.head->item);
    node* marker = copythis.head;
    node* marker2 = head;
    head->next = NULL;
    marker = marker->next;
    while(marker != NULL)
    {
        Append(marker->item);
        marker = marker->next;
        marker2 = marker2->next;
    }
}

const list &list::operator = (list &right)
{
    InsertHead(right.head->item);
    node* marker = right.head;
    node* marker2 = head;
    head->next = NULL;
    marker = marker->next;
    while(marker != NULL)
    {
        Append(marker->item);
        marker = marker->next;
        marker2 = marker2->next;
    }
}

list::~list()
{
    while(head)
    {
        Delete(head);
    }
    head = NULL;
    /*
     node* marker = nEnd();
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
void list::InsertHead(int num)
{
    node* temp = new node;

    temp->item = num;
    temp->next = head;
    head = temp;
}

void list::InsertAfter(Iterator marker, int num)
{
    node* temp = new node;
    temp->item = num;
    temp->next = marker.nodeptr->next;
    marker.nodeptr->next = temp;
}

void list::InsertBefore(Iterator marker, int num)
{
//    if(marker = head)
//        return NULL;
    node* temp = new node;
    node* walker = head;
    temp->item = num;

    while(walker->next != marker.nodeptr && walker->next != NULL)
        walker = walker->next;
    temp->next = walker->next;
    walker->next = temp;
}

void list::Append(int num)
{
    Iterator marker = End();
    InsertAfter(marker, num);
}

//---delete---//
node* list::Remove(node* marker)
{
    node* walker = head;

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

int list::Delete(Iterator marker)
{
    int temp; // value that's in marker
    temp = marker.nodeptr->item;
    Remove(marker.nodeptr);
    delete marker.nodeptr;
    return temp;
}

Iterator list::Search(int key)
{
    node* marker = head;
    while((marker != NULL) && (marker->item != key))
        marker = marker->next;
    return Iterator(marker); // if item is not found, marker will point at NULL and return NULL
}

//---show---//
void list::Print() const
{
    node* walker = head;
    while(walker != NULL)
    {
        cout<<"["<<walker->item<<"]-->";
        walker = walker->next;
    }
    cout << "||||";
}

int &list::operator [](int index)
{
    return Ithnode(index).nodeptr->item;
    /* is the same as doing this :
    Iterator temp = Ithnode(index);
    return temp.nodeptr->item;
    */
}


//---sort---//
void list::Sort() // calls insert sorted until everything is inserted
{
    list newlist;
    newlist.InsertHead(head->item);
    node* marker = head;
    marker = marker->next; // check this later
    while(head != NULL)
    {
        InsertSorted(newlist, marker->item); // potential bug: repeats first node twice because marker hasn't moved
    }
}

void list::InsertSorted(list newlist, int num) // inserts one node
{
    node* newmarker = newlist.head;
    Iterator marker = Remove(head);
    while((newmarker != NULL) && (marker.nodeptr->item <= newmarker->item))
    {
        newmarker = newmarker->next;
    }
    if((marker.nodeptr->item) <= (newmarker->item))
        InsertBefore(newmarker,marker.nodeptr->item);
    else // value is greater than
        InsertAfter(newmarker, marker.nodeptr->item);

    newmarker = newlist.head;
    //&& (i < marker->item)
}

//---markers---//
Iterator list::Begin()
{
    return Iterator(head);
}

node* list::nEnd()
{
    node* walker = head;
    while(walker->next != NULL)
        walker = walker->next;
    return walker;
}

Iterator list::End()
{
    return Iterator(nEnd());
}

Iterator list::Ithnode(int i)
{
    node* walker = head;
    for(int j=0; j<i; j++)
       walker = walker->next; // makes walker point at the node we want
    return Iterator(walker); // returns the address of the Ith node
}

/*
node *list::WhereThisGoes(int i)
{
    node* marker = head;
    while((marker != NULL) && (i < marker->item))
        marker = marker->next;
}*/
