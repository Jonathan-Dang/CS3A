#ifndef LPAR_H
#define LPAR_H
#include "token.h"

class lpar: public Token
{
public:
    //CNTR
    lpar(): Token() {};

    //TYPE
    int type();

    //PRINT
    ostream& print(ostream& outs) const;
};

#endif // LPAR_H
