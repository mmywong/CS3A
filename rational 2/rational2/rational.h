#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

using namespace std;

class rational
{
public:
    //constructors:
    rational();
    rational(int whole_number);
    rational(int new_num, int new_den);
    void Set(int new_num, int new_den);

    //operators:
    friend rational operator +(const rational& first, const rational& second); // does this not declare?
    friend rational operator -(const rational& first, const rational& second);
    friend rational operator *(const rational& first, const rational& second);
    friend rational operator /(const rational& first, const rational& second);
    friend bool operator ==(const rational& first, const rational& second);
    friend bool operator <(const rational& first, const rational& second);
    friend bool operator >(const rational& first, const rational& second);

    //friends:
    void neg(); // negative values
    bool zero() const;

    //input and output functions:
    friend istream& operator >>(istream& in, rational& result);
    friend ostream& operator <<(ostream& out, const rational& result);

    //getter and setter for private variables:
    int getDen() const;
    void setDen(int value);
    int getNum() const;
    void setNum(int value);

private:
    int num;
    int den;
};

#endif // RATIONAL_H
