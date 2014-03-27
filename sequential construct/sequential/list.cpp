#include "list.h"
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
 // if C=B, return C
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
     node* marker = End();
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

void list::InsertBefore(node* marker, int num)
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

void list::Append(int num)
{
    node* marker = End();
    InsertAfter(marker, num);
}

//---delete---//
node* list::Remove(node* marker)
{
    node* walker = head;

    while(walker->next != marker && walker->next != NULL) // finds the position before marker
        walker = walker->next;

    walker->next = marker->next; // makes the previous point at the node after marker

    return marker;
}

int list::Delete(node* marker)
{
    int temp; // value that's in marker
    temp = marker->item;
    Remove(marker);
    delete marker;
    return temp;
}

//---show---//
void list::Print()
{
    node* walker = head;
    while(walker != NULL)
    {
        cout<<"["<<walker->item<<"]-->";
        walker = walker->next;
    }
    cout<<"||||";
}

//---sort---//

//---markers---//
node* list::Begin()
{
    return head;
}

node* list::End()
{
    node* walker = head;
    while(walker->next != NULL)
        walker = walker->next;
    return walker;
}

node* list::Ithnode(int i)
{
    node* walker = head;
    for(int j=0; j<i; j++)
       walker = walker->next; // makes walker point at the node we want
    return walker; // returns the address of the Ith node
}

node *list::WhereThisGoes(int i)
{

}

