#ifndef ITERATOR_H
#define ITERATOR_H

struct node{
    int item;
    node* next;
};

class iterator
{
public:
    friend class list;
    iterator();
    bool IsNull();
    iterator Next();

    //---operators---//
    friend bool operator ==(const iterator& itr1, const iterator& itr2); // checks if they are the same
    int operator *(); // dereference
    iterator operator ++(iterator& itr, int i); //increments position by i amount to the right
    iterator operator ++(iterator& itr); // increments/moves to the next spot to the right

 private:
    node* nodeptr;

};

#endif // ITERATOR_H
