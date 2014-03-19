#ifndef COUNTER_H
#define COUNTER_H

class counter
{
public:
    counter();
    counter(int new_limit);
    void reset(); // set everything to 0
    void incr1(int value); // increment 1
    void incr10(int value); // increment 10
    void incr100(int value); // increment 100
    void incr1000(int value); // increment 1000
    bool overflow(); // checks to see if the value is greater than 99.99. if return true, cout "overflow"
    void setall();
    int getCents() const;
    void setCents(int value);

    int getDimes() const;
    void setDimes(int value);

    int getDollars() const;
    void setDollars(int value);

    int getTendollars() const;
    void setTendollars(int value);

private:
    int cents;
    int dimes;
    int dollars;
    int tendollars;
    int limit;
};

#endif // COUNTER_H
