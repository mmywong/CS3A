#include "rational.h"

rational::rational()
{
}

rational::rational(int num)
{
    numerator = num;
    denominator = 1;
}

rational::rational(int num, int den)
{
    numerator = num;
    denominator = den;
}

rational rational::add(rational &second)
{
    rational result;

    int numR, denR;

    numR = (numerator*second.denominator) + (second.numerator*denominator);
    denR = (denominator*second.denominator);

    result.Set(numR,denR); // more proper than using the rational because we use constructor only in main
    return result;
}

rational rational::sub(rational &second)
{
    rational result;
    //something like second.Set(); //how to input the numbers in?
    // temporary variables:
    int numR, denR;

    numR = (numerator*second.denominator) - (second.numerator*denominator);
    denR = (denominator*second.denominator);

    result.Set(numR,denR);
    return result;
}

rational rational::mul(rational &second)
{
    rational result;
    int numR, denR;

    numR = (numerator * second.numerator);
    denR = (denominator * second.denominator);

    result.Set(numR,denR);
    return result;
}

rational rational::div(rational &second)
{
    rational result;
    int numR, denR;

    numR = (numerator * second.denominator);
    denR = (denominator * second.numerator);

    result.Set(numR,denR);
    return result;
}

rational rational::Set(int num, int den) // should i combine this with input?
{
    numerator = num;
    denominator = den;
}

bool rational::less(rational &second)
{
    if(numerator*second.denominator < second.numerator*denominator)
        return true;
    else
        return false;
}

bool rational::equal(rational &second)
{
    if(numerator*second.denominator == second.numerator*denominator)
        return true;
    else
        return false;
}

void rational::neg()
{
    numerator = -numerator;
}

bool rational::zero()
{
    if(denominator == 0)
        return true;
    else
        return false;
}

void rational::input(istream &in)
{
    char slash;
    in>>numerator>>slash>>denominator;
}

void rational::output(ostream &out)
{
    if(zero() == true)
        out<<"divide by zero";
    else
        out<<numerator<<"/"<<denominator;
}

