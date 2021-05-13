#ifndef TEST_POLY_LIST_H
#define TEST_POLY_LIST_H
#include <iostream>
#include "polylist.h"
using namespace std;
void test_div(const PolyList& p, const PolyList& q);

void test_poly_list()
{
    PolyList p;
    PolyList q;
    p += Term(5,8);
    p += Term(6,2);
    p *= Term(2,3);
    p -= Term(3,2);
    p -= Term(3,2);
    p *= Term(3,2);
    q = p;
    p += Term(3,4);
    p += Term(3,0);
    cout << endl << endl << endl << "test div: " << endl;
    char command;
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

void test_div(const PolyList& p, const PolyList& q){
    PolyList r = p / q;
    cout<<p<<" / "<<q<<endl;
    cout<<"      = "<<r;
    cout<<"  rem = "<<p % q<<"  ";
    //if r = p / q then r * q + p % q should be equal to p:
    if((r * q + p % q) == p){
        cout<<"VERIFIED"<<endl;
    }
    else{
        cout<<endl<<"   ***VERIFICATION FAILED"<<endl;
        cout<<"   r * q: "<<r * q<<endl;
        cout<<"   r: " << r << endl;
        cout<<"   q: " << q << endl;
        cout<<"   p: " << p << endl;
        cout<<"   p % q: "<<p % q<<endl;
        cout<<"   r * q + p % q: "<<r * q + p % q<<"=/="<<p<<endl;
    }
}

#endif // TEST_POLY_LIST_H
