#ifndef LIST_H
#define LIST_H
#include "iterator.h"

template <class T>
class list
{
public:
    list                            ();

    //---big three---//
    list                            (list<T> &copythis); // copy constructor
    const list& operator =          (list<T>& right); //assignment operator
    ~list                           ();  //destructor

    //---create---//
    void InsertHead                 (T num);//must return a node*
    void InsertAfter                (Iterator<T> marker, T num); // makes a node to the right of marker's node
    void InsertBefore               (Iterator<T> marker, T num); // makes a node to the left of marker's node
    void Append                     (T num); // makes a node at the very end of the list

    //---delete---//``
    T Delete                      (Iterator<T> marker); // returns the item you deleted

    //---search---//
    int Search                      (T key);

    //---show---//
    void Print                      () const;

    //---change---//
    int& operator []                (int index);

    //---sort---//
//    void InsertSorted               (int num);
//    void Sort                       ();

    //---new lists---//
    void Reverse                    ();

    //---markers---//
    Iterator<T> Begin                  ();
    Iterator<T> End                    ();
    Iterator<T> Ithnode                (int i);
    int IthElement                  (); // returns the item of IthNode
//    Iterator Previous               ();

private:
    //---node ---//
    //public fx should not have node* everywhere
    //private fx can have node* because user has no access
    //use these node* in private to write public functions
    void InsertAfter                (node* marker, T num); // makes a node to the right of marker's node
    void InsertBefore               (node* marker, T num); // makes a node to the left of marker's node
    T Delete                      (node* marker);
    node* Remove                    (node* marker);
    node* nEnd                      ();
    //node* WhereThisGoes(int i);


    node* head;
};

#endif // LIST_H
