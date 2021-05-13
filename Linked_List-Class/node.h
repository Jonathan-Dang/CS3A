#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
struct node{
  T _item;
  node<T>* _next;

  node(const T& item=T(), node<T>* next = nullptr):
                    _item(item), _next(next){}

    friend ostream& operator<<(ostream& outs, const node<T> n)
    {
        outs<<n._item;
        return outs;
    }
};

//===========================================================================//
//                            NODE FUNCTION CALLS                            //
//===========================================================================//

template<typename T>
node<T>* _insert_head(node<T>*& head_ptr, const T& item);

template<typename T>
ostream& _print_list(node<T>* head_ptr, ostream& outs = cout);

template <typename T>
void _printlist_backwards(node<T> *head);

template <typename T>
T _remove_node(node<T>*& head, node<T>* deleteThis);

template <typename T>
node<T>* _previous_node(node<T>* head, node<T>* prevToThis);

template <typename T>
T _remove_head(node<T>*& headptr);

template <typename T>
node<T>* _search_list(node<T>* head, T key);

template <typename T>
node<T>* _insert_after(node<T>*& head, node<T> *afterThis, T insertThis);

template <typename T>
node<T>* _insert_before(node<T>*& head, node<T>* beforeThis, T insertThis);

template <typename T>
void _clear_list(node<T>*& head);

template <typename T>
node<T>* _copy_list(node<T>* head);

template <typename T>
T& _at(node<T>* head, int pos);

//===========================================================================//
//                         SORTED LIST FUNCTION CALLS                        //
//===========================================================================//
template <typename T>
node<T>* _last_node(node<T>* head);

template <typename T>
node<T>* _where_this_goes(node<T>* head, T item, bool ascending=true);

template <typename T>
node<T>* _insert_sorted(node<T>* &head, T item, bool ascending=true);

template <typename T>
node<T>* _insert_sorted_and_add(node<T>* &head, T item, bool ascending=true);

//===========================================================================//


//===========================================================================//
//                         NODE FUNCTION DEFINITIONS                         //
//===========================================================================//

template<typename T>
node<T>* _insert_head(node<T>*& head_ptr, const T& item)
{
    node<T>* temp = new node<T>(item);
    temp->_next = head_ptr;
    head_ptr = temp;

    return head_ptr;
}

template <typename T>
node<T>* _insert_after(node<T>*& head, node<T> *afterThis, T insertThis)
{
    node<T>* w = head;
    while(w != afterThis) {w = w->_next;}

    node<T>* newnode = new node<T>(insertThis);

    newnode ->_next = w->_next;
    w->_next = newnode;

    return newnode;
}

template <typename T>
node<T>* _insert_before(node<T>*& head, node<T>* beforeThis, T insertThis)
{
    node<T>* w = head;
    while(w->_next != beforeThis) {w = w->_next;}

    node<T>* newnode = new node<T>(insertThis);

    newnode ->_next = w->_next;
    w->_next = newnode;

    return newnode;
}

template <typename T>
node<T>* _search_list(node<T>* head, T key)
{
    node<T>* w = head;
    while(w->_next != nullptr)
    {
        if(w->_item == key) {return w;}
        w = w->_next;
    }

    return nullptr;
}

template<typename T>
ostream& _print_list(node<T>* head_ptr, ostream& outs)
{
    outs<<"H->";
    for (node<T>* w = head_ptr; w->_next != nullptr; w=w->_next)
    {
        outs<<"["<<*w<<"]->";
    }
    outs<<"|||\n";
    return outs;
}

template <typename T>
void _printlist_backwards(node<T> *head)
{
    node<T>* w = head;
    node<T>* Hptr = new node<T>;
    _remove_head(Hptr);

    while(w->_next != nullptr)
    {
        _insert_head(Hptr,w->_item);
        w = w->_next;
    }
    _insert_head(Hptr,w->_item);

    _print_list(Hptr);
    _clear_list(Hptr);
    delete Hptr;
}

template <typename T>
node<T>* _previous_node(node<T>* head, node<T>* prevToThis)
{
    node<T>* w = head;
    while(w->_next != prevToThis) {w = w->_next;}
    return w;
}

template <typename T>
T _remove_node(node<T>*& head, node<T>* deleteThis)
{
    assert(head != nullptr);
    if(deleteThis == head) {return _remove_head(head);}

    node<T>* w = deleteThis;
    (_previous_node(head,deleteThis))->_next = w->_next;
    T hold = w->_item;
    _remove_head(w);

    return hold;
}

template <typename T>
T _remove_head(node<T>*& headptr)
{
    assert(headptr != nullptr);

    node<T>* w = headptr->_next;
    T hold = headptr->_item;
    delete headptr;
    headptr = w;

    return hold;
}

template <typename T>
T& _at(node<T>* head, int pos)
{
    node<T>* w = head;
    for(int i = 0; i != pos-1; i++)
    {
        assert(w != nullptr);
        w = w->_next;
    }
    return w->_item;
}

template <typename T>
void _clear_list(node<T>*& head)
{
    while(head != nullptr)
    {
        _remove_head(head);
    }
}

template <typename T>
node<T>* _copy_list(node<T>* dest, node<T> *src)
{
    //
}

//---------------------------------------------------------------------------//
//                        SORTED LIST FUNCTIONS (nodes)                      //
//---------------------------------------------------------------------------//
template <typename T>
node<T>* _last_node(node<T>* head)
{
    node<T>* w = head;
    if(w)
    {
        while(w->_next != nullptr) {w = w->_next;}
    }
    return w;
}

template <typename T>
node<T>* _where_this_goes(node<T>* head, T item, bool ascending)
{
    if(head == nullptr)
    {
        return head;
    }

    node<T>* w = head;
    node<T>* w2 = head->_next;

    while(w2 != nullptr)
    {
        if(ascending)
        {
            if(item < w2->_item)
            {
                return w;
            }
            w = w->_next;
            w2 = w2->_next;
        }
        else
        {
            if(item > w2->_item)
            {
                return w;
            }
            w = w->_next;
            w2 = w2->_next;
        }
    }
    return w;
}

template <typename T>
node<T>* _insert_sorted(node<T>* &head, T item, bool ascending)
{
    node<T>* w = _where_this_goes(head,item,ascending);
    if(w == nullptr)
    {
        return _insert_head(head,item);
    }

    if(ascending)
    {
        return _insert_after(head,w,item);
    }
    else
    {
        return _insert_after(head,w,item);
    }
}

template <typename T>
node<T>* _insert_sorted_and_add(node<T>* &head, T item,
                                bool ascending)
{
    node<T>* ptr = _where_this_goes(head,item,ascending);
    if(ptr->_item == item)
    {
        ptr->_item += item;
        return ptr;
    }
    else
    {
        return _insert_sorted(head,item,ascending);
    }
}

















#endif // NODE_H
