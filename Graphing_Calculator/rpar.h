#ifndef RPAR_H
#define RPAR_H
#include "token.h"

class rpar : public Token
{
public:
    rpar(): Token() {};

    int type();

    ostream& print(ostream& outs) const;
};

#endif // RPAR_H
