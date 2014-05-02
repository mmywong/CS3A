#include "polynomial.h"

polynomial::polynomial() : SortedList::SortedList()
{
}

const polynomial &polynomial::operator =(polynomial &right)
{
    polynomial left;
    Iterator<polyterm> rwalker = right.Begin();
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
    SortedList<polyterm>::Insert(p);
    Neaten();
}

polynomial polynomial::operator -(polyterm p)
{

}

polynomial polynomial::operator *(polyterm p)
{
    Iterator<polyterm> walker = list<polyterm>::Begin();
//    while(walker.IsNull() == false)
}

polynomial polynomial::operator +(polynomial poly)
{
    polynomial res;
    res = SortedList<polyterm>::Merge(*this, poly);
    return res;
}

polynomial polynomial::operator -(const polynomial poly)
{

}

polynomial polynomial::operator *(const polynomial poly)
{

}

void polynomial::Neaten()
{
    Iterator walker = list<polyterm>::Begin();
    polyterm w, w_n;
    polyterm combined;
    while(walker.IsNull() == false)
    {
        w = *walker;
        w_n = *(walker.Next());
        if(w.getexp() == w_n.getexp())
        {
            combined.exp = w.getexp();
            combined.coef = w.getcoef() + w_n.getcoef();
        }
    }
    Sort(*this);
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

