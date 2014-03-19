#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

using namespace std;

class rational
{
public:
    rational();
    rational(int num);
    rational(int num, int den);
    rational add(rational &second); // +
    rational sub(rational &second); // -
    rational mul(rational &second); // *
    rational div(rational &second); // /
    rational Set(int num, int den);
    bool less(rational &second); // less than
    bool equal(rational &second);
    void neg(); // negative values
    bool zero();
    void input(istream &in);
    void output(ostream &out);
private:
    int numerator;
    int denominator;
};

#endif // RATIONAL_H
