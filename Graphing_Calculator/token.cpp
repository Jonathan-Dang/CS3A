#include "token.h"

int Token::type()
{
    // THere is no Type
    return 0;
}

ostream& Token::print(ostream& outs) const
{
    outs << "T";
    return outs;
}

int Token::prec() const
{
    return 0;
}

ostream& operator <<(ostream& outs, const Token& t)
{
    return t.print(outs);
}

ostream& operator <<(ostream& outs, const Token* t)
{
    return t->print(outs);
}
