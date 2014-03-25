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
    list(const list &copy); // copy constructor
    const list& operator = (list& right); //assignment operator
    ~list();  //destructor

    //---create---//
    void InsertHead(node *&head, int num);
    void InsertAfter(node *marker, int num);
    void InsertBefore(node* head, node* marker, int num);

    //---delete---//
    node* Remove(node* head, node* marker);
    int Delete(node* head, node* marker); // returns the item you deleted

    //---show---//
    void Print(node* head);

    //---sort---//
    void InsertSorted(node* head, int num);
    void Sort(node* head);

private:
    node* head;
};

#endif // LIST_H
