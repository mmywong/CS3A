#include <iostream>

using namespace std;

struct node{
    int item;
    node* next;
};

node* InsertHead(node* head, int num);
void InsertAfter(node* head, int num);
void InsertBefore(node* head, int num);
void Print(node* head);

int main()
{
    node* mainhead = NULL;
    mainhead = InsertHead(mainhead, 1);
    mainhead = InsertHead(mainhead, 2);
    InsertAfter(mainhead,9);
    mainhead = InsertHead(mainhead, 3);
    mainhead = InsertHead(mainhead, 4);
    Print(mainhead);

    cout << endl << endl;

    return 0;
}

node* InsertHead(node* head, int num)
{
    node* temp = new node;

    temp->item = num;
    temp->next = head;
    head = temp;

    return head;
}

void InsertAfter(node* head, int num)
{
    node* temp = new node;
    temp->item = num;
    temp->next = head->next;
    head->next = temp;
}

void InsertBefore(node* head, node* index, int num)
{
    node* temp = new node;
    node* walker = head;
    temp->item = num;

    while(walker->next != index && walker->next != NULL)
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
