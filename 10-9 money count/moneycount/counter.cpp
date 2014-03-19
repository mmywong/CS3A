#include "counter.h"

counter::counter()
{
    cents = 0;
    dimes = 0;
    dollars = 0;
    tendollars = 0;
}

counter::counter(int new_limit)
{
    limit = new_limit;
    cents = 0;
    dimes = 0;
    dollars = 0;
    tendollars = 0;
}

void counter::reset()
{
    cents = 0;
    dimes = 0;
    dollars = 0;
    tendollars = 0;
}

void counter::incr1(int value)
{
    cents += value;
}

void counter::incr10(int value)
{
    dimes += value;
}

void counter::incr100(int value)
{
    dollars += value;
}

void counter::incr1000(int value)
{
    tendollars += value;
}

bool counter::overflow() //hasn't used limit. FIX!!
{
    int totalamt;
    totalamt = tendollars*1000 + dollars*100 + dimes*10 + cents;

    if (totalamt > limit)
        return true;
    else
        return false;
}

void counter::setall() // point is to display a value 0-9 for each display
{
    int carry1,carry10,carry100; //(carry = cents/10)

    if(cents > 9)
    {
        carry1 = cents/10;
        setCents(cents%10); // set to the amount (cents%10).
        dimes += carry1;
    }
    if(dimes > 9)
    {
        carry10 = dimes/10;
        setDimes(dimes%10);
        dollars += carry10;
    }
    if(dollars > 9)
    {
        carry100 = dollars/10;
        setDollars(dollars%10);
        tendollars += carry100;
    }
}
int counter::getCents() const
{
    return cents;
}

void counter::setCents(int value)
{
    cents = value;
}
int counter::getDimes() const
{
    return dimes;
}

void counter::setDimes(int value)
{
    dimes = value;
}
int counter::getDollars() const
{
    return dollars;
}

void counter::setDollars(int value)
{
    dollars = value;
}
int counter::getTendollars() const
{
    return tendollars;
}

void counter::setTendollars(int value)
{
    tendollars = value;
}




