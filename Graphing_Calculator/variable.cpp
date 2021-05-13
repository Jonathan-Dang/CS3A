#include "variable.h"

int Variable::type()
{
    return VARI;
}

ostream& Variable::print(ostream &outs) const
{
    outs << "x";
    return outs;
}

ostream& operator <<(ostream& outs, const Variable& v)
{
    v.print(outs);
    return outs;
}

ostream& operator <<(ostream& outs, const Variable* v)
{
    v->print(outs);
    return outs;
}
