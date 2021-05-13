/*Author: Jonathan Dang
 *Project: Rational Number Class
 *Purpose: Creation of the rational numbers class
*/
#include <iostream>
#include "rational.h"
using namespace std;

void test_rational();

int main()
{
    test_rational();
    return 0;
}

void test_rational()
{
    rational a, b;
    a = rational(1,2);
    b = rational(1,4);
    char command = 'z';

    while(toupper(command) != 'X')
    {
        display_results(a,b);
        cout << "[A] [B]   e[X]it \n :";
        cin >> command;
        switch(toupper(command))
        {
        case('A'):
            cout << "A: ";
            cin >> a;
            break;
        case('B'):
            cout <<"B: ";
            cin >> b;
            break;
        }
    }
}
