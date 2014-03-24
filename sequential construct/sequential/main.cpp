#include <iostream>

using namespace std;


struct node{
    int item;
    node* next;
};

void InsertHead(node *&head, int num);
void InsertAfter(node *marker, int num);
void InsertBefore(node* head, node* marker, int num);
void Print(node* head);
node* Remove(node* head, node* marker);
int Delete(node* head, node* marker); // returns the item you deleted
//void InsertSorted(node* head, int num);
//void Sort(node* head);
//delete
int main()
{
    node* mainhead = NULL;

    InsertHead(mainhead, 1); // first node

    node* marker = mainhead;

    InsertAfter(marker, 2);
    marker = marker->next;
    InsertAfter(marker, 3);
    marker = marker->next;
    InsertAfter(marker, 4);
    marker = marker->next;
    InsertBefore(mainhead,marker,0);

    InsertAfter(marker, 5);
    Remove(mainhead,marker);
    Print(mainhead);

    cout << endl << endl;

    return 0;
}

void InsertHead(node*& head, int num)
{
    node* temp = new node;

    temp->item = num;
    temp->next = head;
    head = temp;
}

void InsertAfter(node* marker, int num)
{
    node* temp = new node;
    temp->item = num;
    temp->next = marker->next;
    marker->next = temp;
}

void InsertBefore(node* head, node* marker, int num)
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

void Print(node *head)
{
    node* walker = head;
    while(walker != NULL)
    {
        cout<<"["<<walker->item<<"]-->";
        walker = walker->next;
    }
    cout<<"||||";
}

node* Remove(node* head, node* marker)
{
    node* walker = head;

    while(walker->next != marker && walker->next != NULL) // finds the position before marker
        walker = walker->next;

    walker->next = marker->next; // makes the previous point at the node after marker

    return marker;
}

int Delete(node* head, node* marker)
{
    int temp; // value that's in marker
    temp = marker->item;
    Remove(head,marker);
    delete marker;
    return temp;
}
