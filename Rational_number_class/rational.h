#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <string>
using namespace std;


class rational
{
public:
    rational();
    rational(int num, int denom);
        rational(int w);        //whole number

        //mutators / setters
        void set(int num, int denom);
        void set_num(int n);
        void set_denom(int d);

        //accessors / getters
        int get_num() const;
        int get_denom() const;

        //Debugs and Requirements
        friend void display_results(const rational &a,const rational &b);

        //error handling routines
        int error() const;      //return error state
        int check_error();      //checks for error cond and returns error code
                                //Edits _error
        string error_description();
                                //return a descriptive error message


        void clear();           //resets number to 0/1 and clears error state

        //will return object whose error state is set
        //   if one of the operands is in error.
        friend rational operator +(const rational &left, const rational &right);
        friend rational operator -(const rational &left, const rational &right);
        friend rational operator *(const rational &left, const rational &right);
        friend rational operator /(const rational &left, const rational &right);

        //will print UNDEFINED if num is in error.
        friend ostream& operator <<(ostream &outs, const rational &num);
        friend istream& operator >>(istream &ins, rational &num);

    private:
        int _n;                 //numerator
        int _d;                 //denominator
        int _error;             //error code

                                //ERROR CODE INDEX:
                                //0 = no error
                                //1 = undefind state
                                //2 = operands with undefined element

};

#endif // RATIONAL_H
