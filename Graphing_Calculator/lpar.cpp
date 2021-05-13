#include "lpar.h"

int lpar::type()
{
    return lPAR;
}

ostream& lpar::print(ostream& outs) const
{
    outs << "(";
    return outs;
}
