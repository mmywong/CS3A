#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "../../../CS3A/list/list/sortedlist.h"
#include "polyterm.h"

class polynomial : protected SortedList<polyterm>
{
public:
    polynomial              ();

//    polynomial                             (polynomial &copythis); // copy constructor
    const polynomial &operator =           (polynomial& right); //assignment operator

    polynomial operator +                  (polyterm p);
    polynomial operator -                  (polyterm p);
    polynomial operator *                  (polyterm p);

    polynomial operator +                  (polynomial poly);
    polynomial operator -                  (const polynomial poly);
    polynomial operator *                  (const polynomial poly);
    void InsertPoly                        (polyterm p);
    polynomial negative                    (polynomial p);
//    friend ostream& operator <<         (ostream& out, const polynomial& p);
    void Neaten                         ();
    void PrintPoly                      ();
};

#endif // POLYNOMIAL_H
