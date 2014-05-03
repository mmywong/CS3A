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
    polynomial result = this;
    if((this->isEmpty()) == true)
        result.InsertHead(p);
    else
        result.Append(p);
    result.Neaten();
    return result;
}

polynomial polynomial::operator -(polyterm p)
{
    polynomial result = this;
    if((this->isEmpty()) == true)
        result.InsertHead(polyterm::neg(p));
    else
        result.Append(polyterm::neg(p));
    result.Neaten();
    return result;
}

polynomial polynomial::operator *(polyterm p)
{
    polynomial newpoly(this);
    Iterator<polyterm> walker = newpoly.Begin();
    while(walker.IsNull() == false)
        *walker = (*walker)*(p);
    return newpoly;
}

polynomial polynomial::operator +(polynomial poly)
{
    polynomial res;
    res.Merge(*this, poly);
    return res;
}

polynomial polynomial::operator -(const polynomial poly)
{
    polynomial res;
    res.Merge(*this, negative(poly));
    return res;
}

polynomial polynomial::operator *(const polynomial poly)
{
    polynomial poly2(this);
    Iterator<polyterm> polywalker = poly.Begin();
    Iterator<polyterm> poly2walker = poly2.Begin();
    while(polywalker.IsNull() == false)
    {
        while(poly2walker.IsNull() == false){
            (*polywalker) = (*poly2walker)*(*polywalker);
            poly2walker++;
        }
        polywalker++;
    }
}

void polynomial::InsertPoly(polyterm p)
{
    if((this->isEmpty()) == true)
        SortedList<polyterm>::InsertHead(p);
    else
        SortedList<polyterm>::Append(p);
    Neaten();
}

polynomial polynomial::negative(polynomial p)
{
    polynomial negpoly(this);
    Iterator<polyterm> walker = negpoly.Begin();
    while(walker.IsNull() == false)
    {
        *walker = (*walker).neg(*walker);
        walker++;
    }
    return negpoly;
}

void polynomial::Neaten()
{
    SortedList<polyterm>::Sort(*this);
    Iterator<polyterm> walker = this->Begin();
    polyterm p1, p2;
    while(walker.IsNull() == false)
    {
        p1 = *walker;
        p2 = *(walker.Next());
        if(p1.samepower(p1, p2))
        {
            p1 = (p1 + p2);
            SortedList<polyterm>::Delete(walker.Next());
        }
    }

//    Iterator<polyterm> walker = list<polyterm>::Begin();
//    polyterm w, w_n;
//    polyterm combined;
//    while(walker.IsNull() == false)
//    {
//        w = *walker;
//        w_n = *(walker.Next());
//        if(w.getexp() == w_n.getexp())
//        {
//            combined.exp = w.getexp();
//            combined.coef = w.getcoef() + w_n.getcoef();
//        }
//    }
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

