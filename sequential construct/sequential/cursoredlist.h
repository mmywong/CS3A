#ifndef CURSOREDLIST_H
#define CURSOREDLIST_H
#include "iterator.h"

class CursoredList : public list
{
public:
    CursoredList                    ();

    //Q : returns Iterator/Cursored list with Iterator cursor as private member?
    CursoredList GoNext             ();
    CursoredList GoPrev             ();
private:
    Iterator cursor; // because we don't want user to delete our cursor
};

//================functions===============//
CursoredList::CursoredList():
    list()
{
    cursor = NULL;
}

CursoredList CursoredList::GoNext()
{

}

CursoredList CursoredList::GoPrev()
{

}


#endif // CURSOREDLIST_H
