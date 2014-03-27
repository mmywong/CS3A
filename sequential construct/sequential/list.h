#ifndef LIST_H
#define LIST_H

struct node{
    int item;
    node* next;
};

class list
{
public:
    list();

    //---big three---//
    list(list &copythis); // copy constructor
    const list& operator = (list& right); //assignment operator
    ~list();  //destructor

    //---create---//
    void InsertHead(int num);
    void InsertAfter(node *marker, int num); // makes a node to the right of marker's node
    void InsertBefore(node* marker, int num); // makes a node to the left of marker's node
    void Append(int num); // makes a node at the very end of the list

    //---delete---//
    node* Remove(node* marker);
    int Delete(node* marker); // returns the item you deleted

    //---show---//
    void Print();

    //---sort---//
    void InsertSorted(node* head, int num);
    void Sort(node* head);

    //---markers---//
    node* Begin();
    node* End();
    node* Ithnode(int i);
    node* WhereThisGoes(int i);

private:
    node* head;
};

#endif // LIST_H
