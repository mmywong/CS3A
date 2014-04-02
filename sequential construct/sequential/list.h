#ifndef LIST_H
#define LIST_H
#include "iterator.h"

class list
{
public:
    list();

    //---big three---//
    list(list &copythis); // copy constructor
    const list& operator = (list& right); //assignment operator
    ~list();  //destructor

    //---create---//
    void InsertHead(int num);//must return a node*
    void InsertAfter(iterator marker, int num); // makes a node to the right of marker's node
    void InsertBefore(iterator marker, int num); // makes a node to the left of marker's node
    void Append(int num); // makes a node at the very end of the list

    //---delete---//``
    iterator Remove(iterator marker);
    int Delete(iterator marker); // returns the item you deleted

    //---search---//
    iterator Search(int key);

    //---show---//
    void Print();

    //---sort---//
    void InsertSorted(list newlist, int num);
    void Sort();

    //---markers---//
    iterator Begin();
    iterator End();
    iterator Ithnode(int i);
    iterator WhereThisGoes(int i);

private:
    node* head;
};

#endif // LIST_H
