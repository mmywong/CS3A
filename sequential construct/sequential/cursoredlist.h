#ifndef CURSOREDLIST_H
#define CURSOREDLIST_H
#include "iterator.h"

template <class T>
class CursoredList : protected list<T>
{
public:
    CursoredList                    ();

    //Q : returns Iterator/Cursored list with Iterator cursor as private member?
    void GoNext             ();
    void GoPrev             ();
private:
    Iterator<T> cursor; // because we don't want user to delete our cursor
};

//================functions===============//
template <class T>
CursoredList<T>::CursoredList():
    list<T>::list()
{
    cursor = NULL;
}

template <class T>
void CursoredList<T>::GoNext()
{

}

template <class T>
void CursoredList<T>::GoPrev()
{

}


#endif // CURSOREDLIST_H
