#ifndef POLYLIST_H
#define POLYLIST_H
#include "../Sorted_list/slist.h"
#include "../Poly-Class/Term.h"
#include <iostream>
using namespace std;

class PolyList
{
public:
    PolyList();

    PolyList& operator -=(const Term& t);
    PolyList& operator /=(const Term& t);
    PolyList& operator *=(const Term& t);
    PolyList& operator +=(const Term& t);

    friend PolyList operator +(const PolyList& p, const Term& t);
    friend PolyList operator -(const PolyList& p, const Term& t);
    friend PolyList operator *(const PolyList& p, const Term& t);
    friend PolyList operator /(const PolyList& p, const Term& t);

    PolyList& operator -=(const PolyList& p);
    PolyList& operator +=(const PolyList& p);
    PolyList& operator /=(const PolyList& p);
    PolyList& operator *=(const PolyList& p);

    friend PolyList operator +(const PolyList& RHS, const PolyList& LHS);
    friend PolyList operator -(const PolyList& RHS, const PolyList& LHS);
    friend PolyList operator *(const PolyList& RHS, const PolyList& LHS);
    friend PolyList operator /(const PolyList& RHS, const PolyList& LHS);
    friend PolyList operator %(const PolyList& RHS, const PolyList& LHS);

    friend bool operator ==(const PolyList& LHS, const PolyList& RHS);
    friend bool operator !=(const PolyList& LHS, const PolyList& RHS);
    friend bool operator >(const PolyList& LHS, const PolyList& RHS);
    friend bool operator <(const PolyList& LHS, const PolyList& RHS);

    friend int size(const PolyList& p);
    Term operator [](const int exp) const;

    friend ostream& operator << (ostream& outs, const PolyList& print_me);
    friend istream& operator >> (istream& ins, PolyList& insert);
private:
    SList<Term> _poly;
    void _fix_order();

    //Ascending booling: True = Ascending, False = Descending
    //Unique boolian: True = only one, False = multiples
};

#endif // POLYLIST_H
