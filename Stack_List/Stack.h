#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cassert>
#include "../Linked_List-Class/node.h"
using namespace std;

template <typename T>
class Stack{
public:
    class Iterator{
    public:
        friend class Stack;
        Iterator(){};

        Iterator(node<T>* &list):_list(list){}

        const T& operator *()
        {
            return _list->_item;
        }

        const T* operator ->() const
        {
            assert(_list);

            return &_list->_item;
        }

        friend Stack<T>::Iterator operator ++(Iterator i,int unused)
        {
            assert(i._list);

            Iterator hold;
            hold = i;
            i._list = i._list->_next;
            return hold;
        }

        friend bool operator ==(const Iterator &lhs, const Iterator &rhs)
        {
            return lhs._list == rhs._list;
        }

        friend bool operator !=(const Iterator &lhs, const Iterator &rhs)
        {
            return lhs._list != rhs._list;
        }


    private:
        node<T>* _list;
    };

    Stack()
    {
        _stack = new node<T>;
    }

    ~Stack()
    {
        _clear_list(_stack);
    }
    Stack(const Stack<T> &copyThis)
    {
        _stack = _copy_list(copyThis._stack);
        _size = copyThis._size;
    }
    Stack& operator =(const Stack& RHS)
    {
        if(&RHS == this) {return *this;}
        _clear_list(_stack);
        _stack = _copy_list(RHS._stack);
        return *this;
    }

    void Push(T insert)
    {
        _insert_head(_stack,insert);
        _size++;
    }

    const T Pop()
    {
        assert(_size);
        _size--;
        return _remove_head(_stack);
    }

    typename Stack<T>::Iterator Begin()
    {
        return Iterator(_stack);
    }

    typename Stack<T>::Iterator End() const
    {
        return Iterator(_last_node(_stack));
    }

    int Size() const
    {
        return _size;
    }

    void Print()
    {
        _print_list(_stack);
    }

    bool Empty()
    {
        if(_stack == nullptr) {return true;}
        else {return false;}
    }

private:
    node<T>* _stack;
    int _size = 0;
};



#endif // STACK_H
