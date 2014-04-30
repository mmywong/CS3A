#ifndef CURSOREDLIST_H
#define CURSOREDLIST_H
#include "iterator.h"

template <class T>
class CursoredList : public list<T>
{
public:
    CursoredList                    ();

    //Q : returns Iterator/Cursored list with Iterator cursor as private member?
    void GoNext             ();
    void GoPrev             ();
    void PrintC             ();
private:
    Iterator<T> cursor; // because we don't want user to delete our cursor
};

//================functions===============//
template <class T>
CursoredList<T>::CursoredList():
    list<T>::list()
{
    cursor = list<T>::Begin();
}

template <class T>
void CursoredList<T>::GoNext()
{
    if(cursor.IsNull())
        cursor = list<T>::Begin();
    cursor = cursor.Next();
}

template <class T>
void CursoredList<T>::GoPrev() // ** check this!!
{

    if(cursor == NULL)// this means that it's at the head
        cursor = list<T>::End();
    cursor = list<T>::Previous(cursor);
//    Iterator<T> walker = list<T>::Begin();

//    while(!(walker.Next() == cursor))
//        walker++;
//    cursor = walker;
//    cout << "DEBUG : " << *cursor << " , walker : " << *walker << endl;
//    CursoredList temp; // contains a new iterator
//    while(temp.cursor.Next() != cursor)
//        temp.cursor = temp.cursor.Next();
//    *this = temp;
}

template <class T>
void CursoredList<T>::PrintC()
{
    if(cursor.IsNull())
        cursor = list<T>::Begin();
    Iterator<T> walker = list<T>::Begin();
    while(walker.IsNull() == false)
    {
        if(walker == cursor)
            cout << "#[" << *walker << "]#";
        else
            cout<<"["<< *walker <<"]";
        cout << "-->";
        walker = walker.Next();
    }
    cout << "||||";
}

#endif // CURSOREDLIST_H
