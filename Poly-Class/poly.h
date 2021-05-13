#ifndef POLY_H
#define POLY_H
#include <iostream>
#include <cassert>
#include "Term.h"
#include "../includes/twod.h"
using namespace std;
class Poly
{
public:
    Poly(){
        _order = 0;
        _coefs = allocate<double>(_order+1);
        *_coefs = 0;
    }
    Poly(double* coefs, int order)
    {
        _order = order;
        _coefs = allocate<double>(order+1);
        init_1d(_coefs,order+1);
        copy(_coefs,coefs,order+1);
    }

        //the BIG 3
        Poly(const Poly& other)
        {
            *this = other;
        }
        Poly& operator =(const Poly& right)
        {
            if(&right == this)
            {
                return *this;
            }

            _coefs = allocate<double>(right.order()+1);
            _order = right.order();
            copy(_coefs,right._coefs,_order+1);
            return *this;
        }
        ~Poly()
        {
            delete [] _coefs;
            _order = 0;
        }

        friend bool operator ==(const Poly& lhs, const Poly& rhs)
        {
            if(lhs.order() != rhs.order())
            {
                return false;
            }

            for(int i = lhs.order(); i >= 0; i--)
            {
                if(lhs[i]._coef != rhs[i]._coef)
                {
                    return false;
                }
            }

            return true;
        }
        friend bool operator !=(const Poly& lhs, const Poly& rhs)
        {
            if(lhs.order() != rhs.order())
            {
                return true;
            }

            for(int i = lhs.order(); i >= 0; i--)
            {
                if(lhs[i]._coef != rhs[i]._coef)
                {
                    return true;
                }
            }

            return false;
        }
        friend bool operator >(const Poly& lhs, const Poly& rhs)
        {
            if(lhs.order() > rhs.order()) {return true;}
            else if (lhs.order() < rhs.order()) {return false;};

            for(int i = lhs.order(); i >= 0; i--)
            {
                if(lhs[i] < rhs[i]) {return false;}
            }
            return true;
        }
        friend bool operator <(const Poly& lhs, const Poly& rhs)
        {
            if(lhs.order() > rhs.order()) {return false;}
            else if (lhs.order() < rhs.order()) {return true;};

            for(int i = lhs.order(); i >= 0; i--)
            {
                if(lhs[i] > rhs[i]) {return false;}
            }
            return true;
        }

        Term operator[](int order) const
        {
            double* coef = _coefs;
            coef += order;
            return Term(*coef, order);
        }

        friend Poly operator +(const Poly& lhs, const Term& t)
        {
            Poly sum = lhs;

            if(t._exp > lhs.order())
            {
                sum._coefs = reallocate(sum._coefs,sum.order(),t._exp+1);
                sum._order = t._exp;

                init_1d(sum._coefs,t._exp+1);
                copy(sum._coefs,lhs._coefs,lhs.order()+1);

                *(sum._coefs + t._exp) += t._coef;
                sum.fix_order();
                return sum;
            }
            else
            {
                *(sum._coefs + t._exp) += t._coef;
                return sum;
            }
        }
        friend Poly operator +(const Poly& lhs, const Poly& rhs)
        {
            Poly sum;
            if(lhs.order() < rhs.order())
            {
                sum = rhs;
                for(int i = lhs.order(); i >= 0 ; i--)
                {
                    sum = sum + lhs[i];
                }
            }
            else
            {
                sum = lhs;
                for(int i = rhs.order(); i >= 0 ;i--)
                {
                    sum = sum + rhs[i];
                }
            }

            return sum;
        }

        friend Poly operator -(const Poly& p)
        {
            Poly Negev = p;
            for(int i = Negev.order(); i >= 0 ; i--)
            {
                *(Negev._coefs + i) = -Negev[i]._coef;
            }
            return Negev;
        }
        friend Poly operator -(const Poly& lhs, const Poly& rhs)
        {
            Poly Diff;
            if(lhs.order() < rhs.order())
            {
                Diff = rhs;
                Diff = Diff + (-lhs);
                //cout<< endl << "IN P-P" <<endl;
            }
            else
            {
                Diff = lhs;
                Diff = Diff + (-rhs);
                //cout<< endl << "IN P-P" <<endl;
            }
            Diff.fix_order();
           // cout << "   in p-p: diff: " << Diff << endl;
            return Diff;
        }

        friend Poly operator *(const Poly& lhs, const Term& t)
        {
            Poly product;

            init_1d(product._coefs,product.order());

            for(int i=lhs.order();i>= 0;i--)
            {
                Term hold = lhs[i]*t;
                product = product + hold;
            }
            return product;
        }
        friend Poly operator *(const Poly& lhs, const Poly& rhs)
        {
            Poly product = lhs;
            for(int i = rhs.order(); i >= 0; i--)
            {
                product = product + (lhs * rhs[i]);
            }
            //cout<< endl << "IN P*P" <<endl;
            return product;
        }

        friend Poly operator /(const Poly& lhs, const Poly& rhs)// subtraction + multiplication
        {
            Poly quotent;

            //Check if divisor is greater than dividen
            if(rhs.order() > lhs.order())
            {
                return quotent;
            }

            //Long Division Algorhythm
            Poly divi = lhs;
            Term hold;

            do
            {
                if(divi.order() >= rhs.order())
                {
                    hold = divi[divi.order()] / rhs[rhs.order()];
                    quotent = quotent + hold;
                    divi = divi - (rhs * hold);

                    divi.fix_order();
                }
            }while(hold._exp > 0);

            return quotent; //stops when < 0
        }
        friend Poly operator %(const Poly& lhs, const Poly& rhs)
        {
            Poly div;
            div = (lhs / rhs);
            return lhs - div * rhs;
        }

        friend ostream& operator <<(ostream& outs, const Poly& p)
        {
            for(int i = p.order();i >= 0; i--)
            {
                outs << p[i];
                if(p[i]._exp != p.order()+1 && p[i]._exp != 0)
                {
                    outs << " + ";
                }
            }
            return outs;
        }
        friend istream& operator >>(istream& ins, Poly& p)
        {
            Term t;
            init_1d(p._coefs,p.order()+1);
            do
            {
                ins >> t;
                if(p.order() < t._exp)
                {
                    p._coefs = reallocate(p._coefs,p.order(),t._exp+1);
                    p._order = t._exp;
                }

                p = p + t;
            }while(t._exp != 0);
            p.fix_order();
            return ins;
        }
        /*1. ins into TERM variable
         *2. add TERM compnents into Poly Variable
         *3. Check 0 and end loop
         *4. return ins
        */
        int order() const {return _order;}

    private:
        void fix_order()   //removes largest exponent with '0' coefficent
        {
            for(int i = order() ; i >= 0 ; i--)
            {
                if(*(_coefs + order()) == 0)
                {
                    shiftleft(_coefs,_coefs+_order,_order);
                }
            }
        }
        int _order;
        double* _coefs;
};

#endif // POLY_H
