#include "number.h"

int Number::type()
{
    return NUM;
}

ostream& Number::print(ostream &outs) const
{
    if(_num != 2.71828)
    {
        outs << _num;
    }
    else
    {
        outs << "e";
    }
    return outs;
}

double Number::num()
{
    return _num;
}

ostream& operator <<(ostream& outs, const Number& n)
{
    return n.print(outs);
}

ostream& operator <<(ostream& outs, const Number* n)
{
    return n->print(outs);
}
