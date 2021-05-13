#include "rational.h"

rational::rational()
{
    _n = 0;
    _d = 1;
    _error = 0;
}

rational::rational(int num, int denom)
{
    _n = num;
    _d = denom;
    check_error();
}

rational::rational(int w)
{
    _n = w;
    _d = 1;
}

void rational::set(int num, int denom)
{
    _n = num;
    _d = denom;
    check_error();
}

void rational::set_num(int n)
{
    _n = n;
}

void rational::set_denom(int d)
{
    _d = d;
}

int rational::get_num() const
{
    return(_n);
}

int rational::get_denom() const
{
    return(_d);
}

void display_results(const rational &a,const rational &b)
{
    rational sum, diff, prod, div;
    sum = a+b;
    diff = a-b;
    prod = a*b;
    div = a/b;
    sum.check_error();
    diff.check_error();
    prod.check_error();
    div.check_error();
    cout << a <<" + "<< b << " = " << sum << endl;
    cout << a <<" - "<< b << " = " << diff << endl;
    cout << a <<" * "<< b << " = " << prod << endl;
    cout << a <<" / "<< b << " = " << div << endl;
}

int rational::error() const
{
    return(_error);
}

int rational::check_error()
{
    if(_d == 0)
    {
        _error = 1;
    }
    else
    {
        _error = 0;
    }
    return(_error);
}

string rational::error_description()
{
    string error_message;
    if(_error == 1)
    {
        error_message = "Undefined";
    }
    if(_error == 2)
    {
        error_message = "Rationals computed with undefined elements";
    }
    //

    return(error_message);
}

void rational::clear()
{
    _n = 0;
    _d = 1;
    _error = 0;
}

rational operator +(const rational &left, const rational &right)
{
    rational sum;
    int n,d;
    if(left.error()||right.error())
    {
        sum._d = 0;
        sum._error = 2;
    }
    else
    {
        if(left._d == right._d)
        {
            n = right._n + left._n;
            sum = rational(n,right._d);
        }
        else
        {
            d = right._d * left._d;
            int hold = right._n * left._d;
            n = left._n * right._d;
            n += hold;
            sum = rational(n,d);
        }
    }
    return sum;
}

rational operator -(const rational &left, const rational &right)
{
    rational diff;
    int n,d;

    if(left.error()||right.error())
    {
        diff._d = 0;
        diff._error = 2;
    }
    else
    {
        if(right._d == left._d)
        {
            n = right._n - left._n;
            diff = rational(n,right._d);
        }
        else
        {
            d = right._d * left._d;
            int hold = right._n * left._d;
            n = left._n * right._d;
            n = hold - n;
            diff = rational(n,d);
        }
    }

    return diff;
}

rational operator *(const rational &left, const rational &right)
{
    rational product;
    int n,d;

    if(right.error()||left.error())
    {
        product._d = 0;
        product._error = 2;
    }
    else
    {
        n = right._n * left._n;
        d = right._d * left._d;
        product = rational(n,d);
    }

    return product;
}

rational operator /(const rational &left, const rational &right)
{
    rational dividen;

    if(right.error()||left.error())
    {
        dividen._d = 0;
        dividen._error = 2;
    }
    else
    {
        dividen = right;
        int hold = dividen._n;
        dividen._n = dividen._d;
        dividen._d = hold;
        dividen = left * dividen;

    }

    return dividen;
}

ostream& operator <<(ostream &outs, const rational &num)
{
    if(num.error())
    {
        outs << "UNDEFINED";
    }
    else
    {
        outs << num._n << "/" << num._d;
    }
    return outs;
}

istream& operator >>(istream &ins, rational &num)
{
    int n, d;
    char slash;
    ins >> n >> slash >> d;
    num = rational(n,d);
    num.check_error();
    return ins;
}


