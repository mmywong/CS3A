#ifndef COUNTERTYPE_H
#define COUNTERTYPE_H

class counter
{
public:
    countertype(); // sets values to 0
    countertype(int value); // this constructor calls set
    void set(int value); // sets the value to the value specified by argument
    void increase(); // increase by 1
    void decrease(); // decrease by 1
    int get(); // returns the current value
    void print(ostream &out); // outputs count to a stream
private:
    int value;
    int limit; //max amount counter can handle
};

#endif // COUNTERTYPE_H
