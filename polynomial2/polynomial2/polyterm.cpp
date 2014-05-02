#include "polyterm.h"


polyterm::polyterm()
{
}

polyterm::polyterm(double coefficient, int exponent)
{
    coef = coefficient;
    exp = exponent;
}

polyterm::polyterm(polyterm &copythis)
{
   coef = copythis.coef;
   exp  = copythis.exp;
}

const polyterm &polyterm::operator =(polyterm &right)
{
    polyterm p;
    p.coef = right.coef;
    p.exp = right.exp;
    return p;
}


polyterm polyterm::operator +(const polyterm p)
{
    polyterm r;
    if(exp == p.exp)
    {
        r.exp = exp;
        r.coef = coef + p.coef;
    }
    else
        cout << "error";
    return r;
}

polyterm polyterm::operator -(const polyterm p)
{
    polyterm r;
    if(exp == p.exp)
    {
        r.exp = p.exp;
        r.coef = coef - p.coef;
    }
    else
        cout << "error";
    return r;
}

polyterm polyterm::operator *(const polyterm p)
{
    polyterm r;
    r.exp = exp + p.exp;
    r.coef = coef * p.coef;
    return r;
}

bool polyterm::operator ==(const polyterm p)
{
    if((coef == p.coef) && (exp == p.exp))
        return true;
    else
        return false;
}

bool polyterm::operator <(const polyterm p) // what if exp are equal but coeff
{
    if(exp < p.exp)
        return true;
    else if(exp == p.exp)
    {
        if(coef < p.coef)
            return true;
        else
            return false;
    }
    else
        return false;
}

bool polyterm::operator >(const polyterm p)
{
    if(exp > p.exp)
        return true;
    else if(exp == p.exp)
    {
        if(coef > p.coef)
            return true;
        else
            return false;
    }
    else
        return false;
}

bool polyterm::samepower(const polyterm p)
{
    if(exp == p.exp)
        return true;
    else
        return false;
}

int polyterm::getexp()
{
    return exp;
}

double polyterm::getcoef()
{
    return coef;
}

istream &operator >>(istream &in, polyterm &p)
{
    char x, power;
    in >> p.coef >> x >> power >> p.exp; // can read 3x^2
    return in;
}

ostream &operator <<(ostream &out, const polyterm &p)
{
    out << p.coef << "x^" << p.exp;
    return out;
}

