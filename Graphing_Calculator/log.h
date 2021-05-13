#ifndef LOG_H
#define LOG_H
#include "token.h"
#include "string.h"
class Log : public Token
{
public:
    //CNTR
    Log(double base, double exponent);
    Log(double base, string variable = "x");

    //Virtual Stuff
    int type();
    int prec() const;
    ostream &print(ostream &outs) const;

    //Own Class Functions
    friend ostream& operator <<(ostream& outs, const Log L);
    friend ostream& operator <<(ostream& outs, const Log* L);
    double base() const {return _base;}
    double exponent() const {return _exponent;}
    bool variable() const {return _variable;}
private:
    double _base = 1;
    double _exponent = 1;
    string _expression;
    bool _variable = false;
};

#endif // LOG_H
