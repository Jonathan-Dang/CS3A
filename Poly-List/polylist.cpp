#include "polylist.h"
#include "../Sorted_list/slist.h"

PolyList::PolyList():_poly(false,true)
{
    _poly.Insert(Term());
}

PolyList& PolyList::operator +=(const Term& t)
{
    _poly.Insert_and_Add(t);
    _fix_order();
    return *this;
}
PolyList& PolyList::operator -=(const Term& t)
{
    Term hold = t;
    hold = -hold;
    _poly.Insert_and_Add(hold);
    _fix_order();
    return *this;
}
PolyList& PolyList::operator *=(const Term& t)
{
    if(t == Term())
    {
        *this = PolyList();
        return *this;
    }

    SList<Term> hold = _poly;
    PolyList product;
    for(SList<Term>::Iterator w = hold.Begin(); w != nullptr; w++)
    {
        Term term = (*w);
        term *= t;
        product += term;
    }
    *this = product;
    return *this;
}
PolyList& PolyList::operator /=(const Term& t)
{
    SList<Term> hold = _poly;
    for(SList<Term>::Iterator w = hold.Begin(); w != nullptr; w++)
    {
        Term term = *w;
        term /= t;
        _poly.Insert_and_Add(term);
        _poly.Delete(_poly.Search(*w));
        _fix_order();
    }
    _fix_order();
    return *this;
}

PolyList operator +(const PolyList& p, const Term& t)
{
    PolyList sum = p;
    sum += t;
    return sum;
}
PolyList operator -(const PolyList& p, const Term& t)
{
    PolyList diff = p;
    diff -= t;
    return diff;
}
PolyList operator *(const PolyList& p, const Term& t)
{
    PolyList product = p;
    product *= t;
    return product;
}
PolyList operator /(const PolyList& p, const Term& t)
{
    PolyList quotent = p;
    quotent /= t;
    return quotent;
}

PolyList& PolyList::operator +=(const PolyList& p)
{
    for(SList<Term>::Iterator w = p._poly.Begin(); w != nullptr; w++)
    {
        Term t = *w;
        *this += t;
    }
    return *this;
}
PolyList& PolyList::operator -=(const PolyList& p)
{
    for(SList<Term>::Iterator w = p._poly.Begin(); w != nullptr; w++)
    {
        Term t = *w;
        *this -= t;
    }
    return *this;
}
PolyList& PolyList::operator *=(const PolyList& p)
{
    for(SList<Term>::Iterator w = p._poly.Begin(); w != nullptr; w++)
    {
        Term t = *w;
        *this *= t;
    }
    return *this;
}
PolyList& PolyList::operator /=(const PolyList& p)
{
    if(size(p) > size(*this))
    {
        _poly.~SList();
        _poly.Insert(Term());
        return *this;
    } //Checks if Divisor is bigger than Dividen

    //Long Division Algorhythm
    PolyList divi = *this;
    PolyList quotent;
    Term hold;

    do
    {
        hold = divi[1] / p[1];
        quotent += hold;
        divi -= p*hold;
        divi._fix_order();
    }while(hold._exp > 0);
    *this = quotent;
    return *this;
}

PolyList operator +(const PolyList& LHS, const PolyList& RHS)
{
    PolyList returnThis = LHS;
    returnThis += RHS;

    return returnThis;
}
PolyList operator -(const PolyList& LHS, const PolyList& RHS)
{
    PolyList returnThis = LHS;
    returnThis -= RHS;

    return returnThis;
}
PolyList operator *(const PolyList& LHS, const PolyList& RHS)
{
    if(size(LHS) >= size(RHS))
    {
        PolyList returnThis = LHS;
        returnThis *= RHS;

        return returnThis;
    }
    else
    {
        PolyList returnThis = RHS;
        returnThis *= LHS;

        return returnThis;
    }

}
PolyList operator /(const PolyList& LHS, const PolyList& RHS)
{
    PolyList returnThis = LHS;
    returnThis /= RHS;

    return returnThis;
}
PolyList operator %(const PolyList& LHS, const PolyList& RHS)
{
    PolyList div;
    div = (LHS / RHS);
    //if(div == PolyList()) {return LHS;}

    return LHS - (RHS*div);
}

bool operator ==(const PolyList& LHS, const PolyList& RHS)
{
    if(&LHS == &RHS) {return true;} // check if itself
    if(size(LHS) != size(RHS)) {return false;} //length of polynomial check

    for(int i = 1;i < size(LHS);i++)
    {
        if(LHS[i] != RHS[i]) {return false;}
    }

    return true;
}
bool operator !=(const PolyList& LHS, const PolyList& RHS)
{
    if(&LHS == &RHS) {return false;}
    if(size(LHS) != size(RHS)) {return true;}

    for(int i = 1;i < size(LHS);i++)
    {
        if(LHS[i] == RHS[i]) {return false;}
    }

    return true;
}
bool operator >(const PolyList& LHS, const PolyList& RHS)
{
    if(&LHS == &RHS) {return false;}
    if(size(LHS) > size(RHS)) {return true;}
    else {return false;}

    for(int i = 1;i < size(LHS);i++)
    {
        if(LHS[i] < RHS[i]) {return false;}
    }

    return true;
}
bool operator <(const PolyList& LHS, const PolyList& RHS)
{
    if(&LHS == &RHS) {return false;}
    if(size(LHS) < size(RHS)) {return true;}
    else {return false;}

    for(int i = 1;i < size(LHS);i++)
    {
        if(LHS[i] > RHS[i]) {return false;}
    }

    return true;
}

int size(const PolyList& p)
{
    int size = 0;
    for(SList<Term>::Iterator w = p._poly.Begin(); w != nullptr; w++)
    {
        size++;
    }
    return size;
}
Term PolyList::operator [](const int exp) const
{
    return _poly[exp];
}

ostream& operator << (ostream& outs, const PolyList& print_me)
{
    for(SList<Term>::Iterator w = print_me._poly.Begin(); w != nullptr; w++)
    {
        outs << *w;
        if(w != print_me._poly.End())
        {
            outs << " + ";
        }
    }

    return outs;
}
istream& operator >> (istream& ins, PolyList& insert)
{
    double coef;
    char x, car;
    int exp;
    insert = PolyList();

    do
    {
        ins >> coef >> x >> car >> exp;
        insert += Term(coef,exp);
    }while(exp != 0);

    return ins;
}

void PolyList::_fix_order()
{
    for(SList<Term>::Iterator w = _poly.Begin(); w != nullptr; w++)
    {
        if(w->_coef == 0)
        {
            _poly.Delete(w);
        }
    }
}












