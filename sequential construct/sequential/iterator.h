#ifndef Iterator_H
#define Iterator_H
#include "node.h"
#include <iostream>

using namespace std;

template<class T> //dummy variable
class list;

template <class T>
class Iterator
{
public:
    friend class list<T>;

    Iterator<T>                    ()    {    nodeptr = NULL;}
    Iterator<T>                    (node<T>* p);
    Iterator<T>                    (const Iterator<T> &p);
    bool IsNull                    () const;
    Iterator<T> Next               ();

    //---operators---//
    bool operator ==            (const Iterator<T>& itr); // checks if they are the same
    T& operator *               (); // dereference

    Iterator<T> operator ++        (int); //postfix (always has dummy variable)
    Iterator<T>& operator ++       (); // prefix (note the &)
    void Delete			();

 private:
    node<T>* nodeptr;

};

//=============functions=============//

template <class T>
Iterator<T>::Iterator(node<T> *p)
{
    nodeptr = p;
}

template <class T>
Iterator<T>::Iterator(const Iterator<T> &p)
{
    nodeptr = p.nodeptr;
}

template <class T>
bool Iterator<T>::IsNull() const
{
    if(nodeptr == NULL)
        return true;
    else
        return false;
}

template <class T>
bool Iterator<T>::operator ==(const Iterator<T>& itr)
{
    if(nodeptr == itr.nodeptr)
        return true;
    else
        return false;
}

template <class T>
T& Iterator<T>::operator *() //pass by reference so that the value is changed (note case : *Iterator = 100)
{
//    if(nodeptr == NULL) //REPLACE WITH TRY STATEMENT to account for null!!
//        cout << "NULL in dereference iterator"<< endl;
//    else
        return nodeptr->item;
}

template <class T>
Iterator<T> Iterator<T>::operator ++(int) // postfix
{
    Iterator<T> tempitr;
    tempitr.nodeptr = nodeptr;
    nodeptr = nodeptr->next;
    return tempitr;
}

template <class T>
Iterator<T> &Iterator<T>::operator ++() // prefix
{
    nodeptr = nodeptr->next;
    return *this;
}

template <class T>
void Iterator<T>::Delete()
{
    delete nodeptr;
}

template <class T>
Iterator<T> Iterator<T>::Next()
{
    //Iterator<T> itr; //here iterator points to Some dark entity(RANDOM)
    //itr points to nothing
    nodeptr = nodeptr->next; // here, program will crash, no warning given
    return *this;
}


#endif // Iterator_H
