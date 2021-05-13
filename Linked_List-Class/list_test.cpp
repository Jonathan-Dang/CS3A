#include "list_test.h"
#include "List.h"
#include "node.h"
#include <random>

void test_List_class()
{
    char command;
    List<int> list;

    default_random_engine generator;
    uniform_int_distribution<int> distribution(0,100);

    for(int i = 0; i < 10; i++)
    {
        list.InsertHead(distribution(generator));
    }
    List<int>::Iterator cursor = list.Begin();
    cout << "//======================================================//\n";
    Print_cursor(list,cursor);

    cout << endl
         << "[R]andom [A]fter  [B]efore [D]elete [S]earch "
            "[P]revious  [N]ext  [H]ome  [E]nd e[X]it \n";
    cin >> command;
    command = toupper(command);
    cout << "//======================================================//\n";
    cout << endl << endl;


    while(command != 'X')
    {
        switch(command)
        {
        case('R'):
        {
            int input = distribution(generator);
            cursor = list.InsertHead(input);
            break;
        }
        case('A'):
        {
            cout << "Insert Value: \n";
            int i = 0;
            cin >> i;
            cursor = list.InsertAfter(i,cursor);
            break;
        }
        case('B'):
        {
            cout << "Insert Value: \n";
            int i = 0;
            cin >> i;
            cursor = list.InsertBefore(i,cursor);
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
            if(cursor->_next != nullptr)
            {
                cursor = cursor->_next;
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
        cout << endl << "[R]andom [A]fter  [B]efore [D]elete "
                        "[S]earch [P] Previous  [N] Next  "
                        "[H]ome  [E]nd  e[X]it\n";
        cin >> command;
        command = toupper(command);
        cout << "//======================================================//\n";
        cout << endl << endl;
    }
    cout << "GOODBYE\n";
}



template<typename T>
ostream& Print_cursor(const List<T> list
                              , typename List<T>::Iterator cursor
                              , ostream& outs)
{
    outs << "H->";
    for(typename List<T>::Iterator w = list.Begin(); w!=nullptr ; w = w->_next)
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
