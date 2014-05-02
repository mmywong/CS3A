#include "polynomial.h"

polynomial::polynomial() : SortedList::SortedList()
{
}

const polynomial &polynomial::operator =(polynomial &right)
{
    polynomial left;
    Iterator rwalker = right.Begin();
    left.InsertHead(*rwalker);
    while (rwalker.IsNull() == false)
    {
        left.Append(*rwalker);
        rwalker = rwalker.Next();
    }
    return left;
}

polynomial polynomial::operator +(polyterm p)
{

    SortedList::Insert(p);
}

polynomial polynomial::operator -(polyterm p)
{

}

polynomial polynomial::operator *(polyterm p)
{

}

polynomial polynomial::operator +(const polynomial poly)
{

}

polynomial polynomial::operator -(const polynomial poly)
{

}

polynomial polynomial::operator *(const polynomial poly)
{

}

//polynomial::polynomial(polynomial &copythis)
//{

//}

//ostream &operator <<(ostream &out, const polynomial &p)
//{

//}

void polynomial::PrintPoly()
{
    Iterator<polyterm> walker = list<polyterm>::Begin();
    cout << *walker;
    walker = walker.Next();
    while(walker.IsNull() == false)
    {
        cout<<" + "<< *walker <<" + ";
        walker = walker.Next();
    }
    cout << "0";
}

