#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
using namespace std;

enum Type : int {NUM = 2, OPER = 3, lPAR = 1, rPAR = 4, VARI = 10, LOG = 5};

class Token
{
public:
    Token(){};

    virtual int type();

    virtual ostream& print(ostream &outs) const;

    virtual int prec() const;
                //This is so that my compiler doesn't scream at me

    //Double << operators just for my convienence.

    friend ostream& operator <<(ostream& outs, const Token& t);

    friend ostream& operator <<(ostream& outs, const Token* t);
};

#endif // TOKEN_H
