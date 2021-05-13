#include "node_test.h"
#include "node.h"

void _test_node()
{
    node<int>* head_ptr=nullptr;
    cout << endl << "Initializing node list: \n";
    for (int i=0; i<10; i++)
    {
        _insert_head(head_ptr, i*10);
        _print_list(head_ptr);
        cout<<endl;
    }
    cout << "Initial Node List: \n";
    _print_list(head_ptr);
    cout << endl;
    cout << "Insert After 30: \n";
    _insert_after(head_ptr,_search_list(head_ptr,30),69420);
    _print_list(head_ptr);
    cout<<endl;
    cout << "Insert Before 40: \n";
    _insert_before(head_ptr,_search_list(head_ptr,40),69420);
    _print_list(head_ptr);
    cout<<endl;
    cout << "DELETED NODE: "<< _remove_node(head_ptr,_search_list(head_ptr,40)) << endl;
    _print_list(head_ptr);
    cout<<endl;
    cout << "DELETED HEAD: "<< _remove_head(head_ptr) << endl;
    _print_list(head_ptr);
    cout<<endl;
    cout << "~DELETED THE ENTIRE LIST~\n";
    _clear_list(head_ptr);
    _print_list(head_ptr);
    for (int i=0; i<10; i++)
    {
        _insert_head(head_ptr, i*10);
    }
    cout << endl;
    cout << "~COPYING THE ENTIRE LIST~\n";
    node<int>* Hptr = nullptr;
    Hptr = _copy_list(head_ptr);
    cout << "Initial List: \n";
    _print_list(head_ptr);
    cout << endl;
    cout << "Copied List: \n";
    _print_list(Hptr);
    cout << endl;
    cout << "Target value held in position 4 is: \n";
    cout << _at(head_ptr,4) << endl;
    cout << "List but in reverse: \n";
    _printlist_backwards(head_ptr);
    cout << endl << endl;

    cout << "Initial List: \n";
    _print_list(head_ptr);
    node<int>* w = _where_this_goes(head_ptr,55,false);
    cout << endl << "Insert after: " <<w->_item << " for value 55."<< endl;
    cout << "Inputing value 55 into the list: \n";
    _insert_sorted(head_ptr,55,false);
    _print_list(head_ptr);
}
