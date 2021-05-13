/* Author: Jonathan Dang
 *Project: Polynomial Class
 *Purpose: To create a working Polynomial Class
*/
#include <iostream>
#include "poly.h"
#include "../includes/twod.h"
using namespace std;

void test_div(const Poly& p, const Poly& q);

void test_POLY();

int main()
{
    cout << endl << endl << endl << "==============================" << endl;
    test_POLY();
    cout << endl << endl << endl << "===============END===============" << endl;
    return 0;
}

void test_div(const Poly& p, const Poly& q){
    Poly r = p / q;
    cout<<p<<" / "<<q<<endl;
    cout<<"      = "<<r;
    cout<<"  rem = "<<p % q<<"  ";
    //if r = p / q then r * q + p % q should be equal to p:
    if(r * q + p % q == p){
        cout<<"VERIFIED"<<endl;
    }
    else{
        cout<<endl<<"   ***VERIFICATION FAILED"<<endl;
        cout<<"   r * q: "<<r * q<<endl;
        cout<<"   p % q: "<<p % q<<endl;
        cout<<"   r * q + p % q: "<<r * q + p % q<<"=/="<<p<<endl;
    }
}

void test_POLY()
{
    char command;
    Poly p, q;
    double a[5] = {1,2,3,4,5};
    double f[3] = {2,3,4};
    p = Poly(a,4);
    q = Poly(f,2);
    cout << p << endl;
    cout << q << endl;
    test_div(p,q);
    cout <<" [P]  [Q] e[X]it " << endl;
    cin >> command;
    while(toupper(command) != 'X')
    {
        switch(toupper(command))
        {
        case('P'):
            cout << p << endl;
            cin >> p;
            break;
        case('Q'):
            cout << q << endl;
            cin >> q;
            break;
        }
        test_div(p,q);
        cout << p << endl;
        cout << q << endl;
        cout <<" [P]  [Q] e[X]it " << endl;
        cin >> command;
    }
}
