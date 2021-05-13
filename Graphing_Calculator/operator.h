#ifndef OPERATOR_H
#define OPERATOR_H
#include "token.h"
#include <string.h>

enum Precidence : int {PLUS_MINUS = 0, MULTI_DIVI = 1, EXPO = 2, FUNC = 3
                      , FACTORIAL = 6};

class Operator: public Token
{
public:
    Operator(string oper);

    int type();

    ostream &print(ostream &outs) const;

    int prec() const;

    string op();

    friend ostream& operator <<(ostream& outs, const Operator& t);

    friend ostream& operator <<(ostream& outs, const Operator* t);

    //Boolean Operators comparing Precidence

    friend bool operator >=(const Operator& LHS, const Operator& RHS);

    friend bool operator >(const Operator& LHS, const Operator& RHS);

    friend bool operator ==(const Operator& LHS, const Operator& RHS);
private:
    string _operator;
    int _precidence;
};

#endif // OPERATOR_H
