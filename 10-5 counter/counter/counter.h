#ifndef COUNTER_H
#define COUNTER_H
#include <iostream>

using namespace std;

class counter
{
public:
    counter();
    counter(int new_value); // this constructor calls set
    void set(int new_value); // sets the value to the value specified by argument
    void increase(); // increase by 1
    void decrease(); // decrease by 1
    int get(); // returns the current value
    //bool neg(); // checks for negative
    void print(ostream &out); // outputs count to a stream

private:
    int value;
};

#endif // COUNTER_H
