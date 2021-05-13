#ifndef VARIABLE_H
#define VARIABLE_H
#include "token.h"
using namespace std;

class Variable: public Token
{
public:
    Variable():Token(){};
    int type();
    ostream& print(ostream &outs) const;
    friend ostream& operator <<(ostream& outs, const Variable& v);
    friend ostream& operator <<(ostream& outs, const Variable* v);
};

#endif // VARIABLE_H
