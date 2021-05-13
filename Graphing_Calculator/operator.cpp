#include "operator.h"

Operator::Operator(string oper)
{
    Token();
    if(oper == "+" || oper == "-")
    {
        _operator = oper;
        _precidence = PLUS_MINUS;
    }
    else if(oper == "*" || oper == "/")
    {
        _operator = oper;
        _precidence = MULTI_DIVI;
    }
    else if(oper == "^")
    {
        _operator = oper;
        _precidence = EXPO;
    }
    else if(oper == "sin" || oper == "cos" || oper == "tan")
    {
        _operator = oper;
        _precidence = FUNC;
    }
    else if(oper[0] == 'l' || oper[0] == 'L')
    {
        _operator = oper;
        _precidence = FUNC;
    }
    else
    {
        _precidence = 0;
    }
}

int Operator::type()
{
    return OPER;
}

ostream& Operator::print(ostream& outs) const
{
    outs << _operator;
    return outs;
}

string Operator::op()
{
    return _operator;
}

int Operator::prec() const
{
    return _precidence;
}

ostream& operator <<(ostream& outs, const Operator& t)
{
    return t.print(outs);
}

ostream& operator <<(ostream& outs, const Operator* t)
{
    return t->print(outs);
}

bool operator >=(const Operator& LHS, const Operator& RHS)
{
    return LHS.prec() >= RHS.prec();
}

bool operator >(const Operator& LHS, const Operator& RHS)
{
    return LHS.prec() > RHS.prec();
}

bool operator ==(const Operator& LHS, const Operator& RHS)
{
    return LHS.prec() == RHS.prec();
}
