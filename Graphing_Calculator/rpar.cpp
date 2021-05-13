#include "rpar.h"

int rpar::type()
{
    return rPAR;
}

ostream& rpar::print(ostream &outs) const
{
    outs << ")";
    return outs;
}
