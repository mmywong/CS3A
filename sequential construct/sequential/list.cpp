#include "list.h"
#include <iostream>

using namespace std;

list::list()
{
    head = NULL;
}

list::list(const list &copy)
{

}

const list &list::operator =(list &right)
{

}

list::~list()
{

}


void list::InsertHead(node*& head, int num)
{
    node* temp = new node;

    temp->item = num;
    temp->next = head;
    head = temp;
}

void list::InsertAfter(node* marker, int num)
{
    node* temp = new node;
    temp->item = num;
    temp->next = marker->next;
    marker->next = temp;
}

void list::InsertBefore(node* head, node* marker, int num)
{
//    if(marker = head)
//        return NULL;
    node* temp = new node;
    node* walker = head;
    temp->item = num;

    while(walker->next != marker && walker->next != NULL)
        walker = walker->next;
    temp->next = walker->next;
    walker->next = temp;
}

void list::Print(node *head)
{
    node* walker = head;
    while(walker != NULL)
    {
        cout<<"["<<walker->item<<"]-->";
        walker = walker->next;
    }
    cout<<"||||";
}

node* list::Remove(node* head, node* marker)
{
    node* walker = head;

    while(walker->next != marker && walker->next != NULL) // finds the position before marker
        walker = walker->next;

    walker->next = marker->next; // makes the previous point at the node after marker

    return marker;
}

int list::Delete(node* head, node* marker)
{
    int temp; // value that's in marker
    temp = marker->item;
    Remove(head,marker);
    delete marker;
    return temp;
}
