#include "rational.h"

rational::rational()
{
    num = 0;
    den = 1;
}

rational::rational(int whole_number)
{
    num = whole_number;
    den = 1;
}

rational::rational(int new_num, int new_den)
{
    num = new_num;
    den = new_den;
}

void rational::Set(int new_num, int new_den)
{
    num = new_num;
    den = new_den;
}

//---input output---//

istream& operator >>(istream &in, rational &result)
{
    char slash;
    in>>result.num>>slash>>result.den;
    return in;
}

ostream& operator <<(ostream &out, const rational &result)
{
    if(result.zero() == true)
        out<<"divide by zero";
    else
        out<<result.num<<"/"<<result.den;
    return out;
}

//---friends---//
rational operator +(const rational& first, const rational& second)
{
    rational result;
    int numR, denR;

    numR = (first.num*second.den) + (second.num*first.den);
    denR = (first.den*second.den);

    result.Set(numR,denR); // more proper than using the rational because we use constructor only in main
    return result;
}

rational operator -(const rational& first, const rational& second)
{
    rational result;
    int numR, denR;

    numR = (first.num*second.den) - (second.num*first.den);
    denR = (first.den*second.den);

    result.Set(numR,denR);
    return result;
}

rational operator *(const rational& first, const rational& second)
{
    rational result;
    int numR, denR;

    numR = (first.num * second.num);
    denR = (first.den * second.den);

    result.Set(numR,denR);
    return result;
}

rational operator /(const rational& first, const rational& second)
{
    rational result;
    int numR, denR;

    numR = (first.num * second.den);
    denR = (first.den * second.num);

    result.Set(numR,denR);
    return result;
}

bool operator ==(const rational& first, const rational& second)
{
    if((first.num == second.num) && (first.den == second.den))
        return true;
    else
        return false;
}

void rational::neg()
{
    num = -num;
}

bool rational::zero() const
{
    if(den == 0)
        return true;
    else
        return false;
}

bool operator <(const rational& first, const rational& second)
{
    if(first.num*second.den < second.num*first.den)
        return true;
    else
        return false;
}

bool operator >(const rational& first, const rational& second)
{
    if(first.num*second.den > second.num*first.den)
        return true;
    else
        return false;
}
//----getters and setters---//
int rational::getDen() const
{
    return den;
}

void rational::setDen(int value)
{
    den = value;
}
int rational::getNum() const
{
    return num;
}

void rational::setNum(int value)
{
    num = value;
}
