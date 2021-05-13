#ifndef NUMBER_H
#define NUMBER_H
#include "token.h"
#include <iostream>
using namespace std;

class Number: public Token
{
public:
    Number(double num): Token(), _num(num){};

    ostream& print(ostream& outs) const;

    int type();

    double num();

    friend ostream& operator <<(ostream& outs, const Number& n);

    friend ostream& operator <<(ostream& outs, const Number* n);
private:
    double _num;
};

#endif // NUMBER_H
