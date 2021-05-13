#include "slist_test.h"
#include <random>


void test_SList_class()
{
    char command;
    SList<int> list(false);
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0,100);


    for(int i = 0; i < 10; i++)
    {
        list.Insert(distribution(generator));
    }

    SList<int>::Iterator cursor = list.Begin();
    cout << "//======================================================//\n";
    Print_cursor(list,cursor);

    cout << endl
         << "[R]andom [I]nsert [D]elete [S]earch "
            "[P]revious  [N]ext  [H]ome  [E]nd e[X]it \n";
    cin >> command;
    command = toupper(command);
    cout << endl << endl;


    while(command != 'X')
    {
        switch(command)
        {
        case('R'):
        {
            int input = distribution(generator);
            cursor = list.Insert(input);
            break;
        }
        case('I'):
        {
            cout << "Input Value: ";
            int i;
            cin >> i;
            cursor = list.Insert(i);
            break;
        }
        case('D'):
        {
            if(list.Begin() != nullptr)
            {
                list.Delete(cursor);
            }
            cursor = list.Begin();
            break;
        }
        case('S'):
        {
            cout << "Insert Search Term: \n";
            int search = 0;
            cin >> search;
            cursor = list.Search(search);
            if(cursor == nullptr)
            {
                cout << "NOT IN THIS LIST \n";
                cursor = list.Begin();
            }
            break;
        }
        case('P'):
        {
            if(cursor != list.Begin())
            {
                cursor = list.Prev(cursor);
            }
            break;
        }
        case('N'):
        {
            if(cursor != nullptr)
            {
                cursor++;
            }
            break;
        }
        case('H'):
        {
            cursor = list.Begin();
            break;
        }
        case('E'):
        {
            cursor = list.End();
            break;
        }
        }

        cout << "//======================================================//\n";

        Print_cursor(list,cursor);
        cout << endl << "[R]andom [I]nsert [D]elete "
                        "[S]earch [P] Previous  [N] Next  "
                        "[H]ome  [E]nd  e[X]it\n";
        cin >> command;
        command = toupper(command);
        cout << endl << endl;
    }
    cout << "GOODBYE\n";
}


template<typename T>
ostream& Print_cursor(const SList<T> list
                      , typename SList<T>::Iterator cursor
                      , ostream& outs)
{
    outs << "H->";
    for(typename SList<T>::Iterator w = list.Begin(); w!=nullptr ; w++)
    {
        if(cursor == w)
        {
           outs << "{" <<*w << "}->";
        }
        else
        {
            outs << "[" << *w << "]->";
        }
    }
    outs<<"|||";
    return outs;
}









