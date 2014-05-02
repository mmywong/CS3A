#ifndef POLYTERM_H
#define POLYTERM_H
#include <iostream>

using namespace std;

class polyterm
{
public :
    polyterm                            ();
    polyterm                            (double coefficient, int exponent);
    polyterm                            (polyterm &copythis); // copy constructor
    const polyterm &operator =          (polyterm& right); //assignment operator

    polyterm operator +                 (const polyterm p); // run an error if diff exp
    polyterm operator -                 (const polyterm p);
    polyterm operator *                 (const polyterm p);
    bool operator ==                    (const polyterm p);
    bool operator <                     (const polyterm p);
    bool operator >                     (const polyterm p); // compares only coef
    bool samepower                      (const polyterm p);

    //---input and output---//
    friend istream& operator >>         (istream& in, polyterm& p);
    friend ostream& operator <<         (ostream& out, const polyterm& p);

    int getexp                          ();
    double getcoef                      ();
private:
    int exp;
    double coef;
};

#endif // POLYTERM_H
