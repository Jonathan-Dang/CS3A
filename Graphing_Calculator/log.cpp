#include "log.h"
#include "string.h"
#include <cmath>

Log::Log(double base, double exponent):Token()
{
    if(base <= 1)
    {
        _base = -1;
        _exponent = -1;
    }
    else if(exponent <= 0)
    {
        _base = -1;
        _exponent = -1;
    }
    else
    {
        _base = base;
        _exponent = exponent;
    }
}

Log::Log(double base, string variable):Token()
{
    if(base <= 1)
    {
        _base = -1;
    }
    else
    {
        _base = base;
        _exponent = 0;
        _variable = true;
        _expression = variable;
    }
}

int Log::type()
{
    return LOG;
}

int Log::prec() const
{
    return 3;//Its a function technically...
}

ostream& Log::print(ostream &outs) const
{
    if(_base == 2.71828)
    {
        if(_variable)
        {
            outs << "Ln(x)";
            return outs;
        }
        else
        {
            outs << "Ln(" << _exponent << ")";
            return outs;
        }
    }
    else
    {
        if(_variable)
        {
            outs << "Log[" << _base << "](x)";
            return outs;
        }
        else
        {
            outs << "Log[" << _base << "](" << _exponent << ")";
            return outs;
        }

    }
}

ostream& operator <<(ostream& outs, const Log L)
{
    L.print(outs);
    return outs;
}


ostream& operator <<(ostream& outs, const Log* L)
{
    L->print(outs);
    return outs;
}
