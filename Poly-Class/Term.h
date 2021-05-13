#ifndef TERM_H
#define TERM_H
#include <iostream>
#include <cassert>
using namespace std;
struct Term{
    double _coef = 0;
    int _exp = 0;

    Term(double coef = 0, int exp = 0):_coef(coef),_exp(exp){}

    Term& operator +=(const Term& rhs)
    {
        assert(_exp == rhs._exp);
        _coef += rhs._coef;
        return *this;
    }
    Term& operator -=(const Term& rhs)
    {
        assert(_exp == rhs._exp);
        _coef -= rhs._coef;
        return *this;
    }
    Term& operator *=(const Term& rhs)
    {
        _coef *= rhs._coef;
        _exp += rhs._exp;
        return *this;
    }
    Term& operator /=(const Term& rhs)
    {
        if(_exp < rhs._exp)
        {
            _coef = 0;
            _exp = 0;
            return *this;
        }
        _coef /= rhs._coef;
        _exp -= rhs._exp;
        return *this;
    }

    friend bool operator ==(const Term& lhs, const Term& rhs)
    {
        return lhs._exp == rhs._exp;
    }
    friend bool operator !=(const Term& lhs, const Term& rhs)
    {
        return lhs._exp != rhs._exp;
    }
    friend bool operator >(const Term& lhs, const Term& rhs)
    {
        return lhs._exp > rhs._exp;
    }
    friend bool operator <(const Term& lhs, const Term& rhs)
    {
        return lhs._exp < rhs._exp;
    }

    //used in Poly division operator
    friend Term operator / (const Term& lhs, const Term& rhs)
    {
        int exp = lhs._exp - rhs._exp;
        double coef = lhs._coef / rhs._coef;

        if(lhs._exp < rhs._exp)
        {
            return Term();
        }
        return (Term(coef,exp));
    }
    friend Term operator * (const Term& lhs, const Term& rhs)
    {
        int exp = lhs._exp + rhs._exp;
        double coef = lhs._coef * rhs._coef;

        return (Term(coef,exp));
    }
    friend Term operator + (const Term& lhs, const Term& rhs)
    {
        assert(lhs._exp == rhs._exp);

        double sum = lhs._coef + rhs._coef;

        return Term(sum,lhs._exp);
    }
    friend Term operator - (const Term& lhs, const Term& rhs)
    {
        assert(lhs._exp == rhs._exp);

        double diff = lhs._coef - rhs._coef;

        return Term(diff,lhs._exp);
    }
    Term operator -()
    {
        double negative = this->_coef;
        this->_coef = -negative;
        return *this;
    }

    friend ostream& operator <<(ostream& outs, const Term& t)
    {
        if(t._exp > 0)
        {
            if(t._coef == 1);
            else
            {
                outs << t._coef;
            }
        }
        else
        {
            outs << t._coef;
        }
        if(t._exp == 0);
        else if(t._exp == 1) {outs << "x";}
        else
        {
            outs << "x^";
            outs << t._exp;
        }

        return outs;
    }
    friend istream& operator >>(istream& ins, Term& t)
    {
        char x,car;
        double coef = 0;
        int exp = 0;
        ins >> coef >> x >> car >> exp;

        t = Term(coef,exp);

        return ins;
    }
};
#endif // TERM_H
