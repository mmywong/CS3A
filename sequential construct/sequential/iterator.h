#ifndef Iterator_H
#define Iterator_H
#include "node.h"

class Iterator
{
public:
    friend class list;
    Iterator                    ();
    Iterator                    (node* p);
    Iterator                    (const Iterator &p);
    bool IsNull                 () const;
    Iterator Next               () const;

    //---operators---//

    bool operator ==     (const Iterator& itr); // checks if they are the same
    int& operator *             (); // dereference

    Iterator operator ++        (int); //postfix (always has dummy variable)
    Iterator& operator ++       (); // prefix (note the &)

 private:
    node* nodeptr;

};

#endif // Iterator_H
