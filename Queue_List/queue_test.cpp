#include "queue_test.h"
#include <random>

void test_Queue()
{
    char command;
    Queue<int> S;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0,100);

    for(int i = 0; i < 10; i++)
    {
        S.Push(i);
    }
    S.Print();
    cout << "P[o]p P[u]sh [R]andom E[x]it \n";
    cin >> command;
    command = tolower(command);

    while(command != 'x')
    {
        switch(command)
        {
        case('r'):
        {
            S.Push(distribution(generator));
            break;
        }
        case('o'):
        {
            if(S.Empty()) {break;}
            int removed = S.Pop();
            cout << "Removed: " << removed << endl;
            break;
        }
        case('u'):
        {
            cout << "Input Value: ";
            int insert;
            cin >> insert;
            S.Push(insert);
            cout << endl;
            break;
        }
        }
        S.Print();
        cout << "P[o]p P[u]sh [R]andom E[x]it \n";
        cin >> command;
        command = tolower(command);
    }
}


