#ifndef LIST_H
#define LIST_H
#include "Iterator.h"

class list
{
public:
    list                            ();

    //---big three---//
    list                            (list &copythis); // copy constructor
    const list& operator =          (list& right); //assignment operator
    ~list                           ();  //destructor

    //---create---//
    void InsertHead                 (int num);//must return a node*
    void InsertAfter                (Iterator marker, int num); // makes a node to the right of marker's node
    void InsertBefore               (Iterator marker, int num); // makes a node to the left of marker's node
    void Append                     (int num); // makes a node at the very end of the list

    //---delete---//``
    int Delete                      (Iterator marker); // returns the item you deleted

    //---search---//
    int Search                      (int key);

    //---show---//
    void Print                      () const;

    //---change---//
    int& operator []                (int index);

    //---sort---//
    void InsertSorted               (int num);
    void Sort                       ();

    //---markers---//
    Iterator Begin                  ();
    Iterator End                    ();
    Iterator Ithnode                (int i);


private:
    //---node ---//
    //public fx should not have node* everywhere
    //private fx can have node* because user has no access
    //use these node* in private to write public functions
    void InsertAfter                (node* marker, int num); // makes a node to the right of marker's node
    void InsertBefore               (node* marker, int num); // makes a node to the left of marker's node
    int Delete                      (node* marker);
    node* Remove                    (node* marker);
    node* nEnd                      ();
    //node* WhereThisGoes(int i);


    node* head;
};

#endif // LIST_H
