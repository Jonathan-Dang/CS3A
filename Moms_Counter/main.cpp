/*Author: Jonathan Dang
 *Project: Mom's Counter
 *Purpose: Demonstrate an intermediate or above level of understanding of
 *         classes and how to use them.
*/
#include <iostream>
#include "mcount.h"
using namespace std;

void test_MCounter();

int main()
{
    test_MCounter();
    cout << "=============END==========="<<endl;
    return 0;
}

void test_MCounter()
{
    char command;
    MCount activate;

    cout << "--------" << endl << "| "
         << activate.count()<<" |"<< endl << "--------" << endl;
    cout << "[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it" <<endl;
    cin >> command;
    while(toupper(command) != 'X')
    {
        switch(toupper(command))
        {
        case('A'):
            activate.add_1000();
            break;
        case('S'):
            activate.add_100();
            break;
        case('D'):
            activate.add_10();
            break;
        case('F'):
            activate.add_1();
            break;
        case('R'):
            activate.reset();
            break;
        }

        cout << "--------" << endl << "| ";
        if(activate.is_error())
        {
            cout << "ERROR";
        }
        else
        {
            cout << activate.count();
        }
        cout <<" |"<< endl << "--------" << endl;

        cout << "[A] 1000  [S] 100   [D] 10   [F] 1    [R]eset:   e[X]it" <<endl;
        cin >> command;
    }
}
