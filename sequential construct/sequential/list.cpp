#include "list.h"
#include "iterator.h"
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
    iterator marker = copythis.head;
    iterator marker2 = head;
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
    iterator marker = right.head;
    iterator marker2 = head;
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
     iterator marker = End();
     while(marker != head)
     {
         delete marker;
         marker = End();
     }
     delete marker;
     head = NULL;
}

//---create---//
void list::InsertHead(int num)
{
    iterator temp = new node;

    temp->item = num;
    temp->next = head;
    head = temp;
}

void list::InsertAfter(iterator marker, int num)
{
    iterator temp = new node;
    temp->item = num;
    temp->next = marker->next;
    marker->next = temp;
}

void list::InsertBefore(iterator marker, int num)
{
//    if(marker = head)
//        return NULL;
    iterator temp = new node;
    iterator walker = head;
    temp->item = num;

    while(walker->next != marker && walker->next != NULL)
        walker = walker->next;
    temp->next = walker->next;
    walker->next = temp;
}

void list::Append(int num)
{
    iterator marker = End();
    InsertAfter(marker, num);
}

//---delete---//
iterator list::Remove(iterator marker)
{
    iterator walker = head;

    if(marker = head) // case that you want to remove head
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

int list::Delete(iterator marker)
{
    int temp; // value that's in marker
    temp = marker->item;
    Remove(marker);
    delete marker;
    return temp;
}

iterator list::Search(int key)
{
    iterator marker = head;
    while((marker != NULL) && (marker->item != key))
        marker = marker->next;
    return marker; // if item is not found, marker will point at NULL and return NULL
}

//---show---//
void list::Print()
{
    iterator walker = head;
    while(walker != NULL)
    {
        cout<<"["<<walker->item<<"]-->";
        walker = walker->next;
    }
    cout<<"||||";
}


//---sort---//
void list::Sort() // calls insert sorted until everything is inserted
{
    list newlist;
    newlist.InsertHead(head->item);
    marker = head;
    marker = marker->next; // check this later
    while(head != NULL)
    {
        InsertSorted(newlist, marker->item); // potential bug: repeats first node twice because marker hasn't moved
    }
}

void list::InsertSorted(list newlist, int num) // inserts one node
{
    iterator newmarker = newlist.head;
    iterator marker = Remove(head);
    while((newmarker != NULL) && (marker->item <= newmarker->item))
    {
    if((marker->item) <= (newmarker->item))
        InsertBefore(newmarker,marker->item);
    else // value is greater than
        InsertAfter(newmarker, marker->item);
    }
    //&& (i < marker->item)
}

//---markers---//
iterator list::Begin()
{
    return head;
}

iterator list::End()
{
    iterator walker = head;
    while(walker->next != NULL)
        walker = walker->next;
    return walker;
}

iterator list::Ithnode(int i)
{
    iterator walker = head;
    for(int j=0; j<i; j++)
       walker = walker->next; // makes walker point at the node we want
    return walker; // returns the address of the Ith node
}

/*
node *list::WhereThisGoes(int i)
{
    node* marker = head;
    while((marker != NULL) && (i < marker->item))
        marker = marker->next;
}*/
