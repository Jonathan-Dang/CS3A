#ifndef SLIST_H
#define SLIST_H
#include "../Linked_List-Class/node.h"
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class SList{
public:

    class Iterator{
    public:
        friend class SList;

        Iterator(node<T>* ptr = nullptr):_ptr(ptr){}

        const T operator *()
        {
            assert(_ptr);

            return _ptr->_item;
        }

        friend Iterator operator ++(Iterator& i, int unused)
        {
            assert(i._ptr);
            Iterator hold = i;
            i = i._ptr->_next;
            return hold;
        }

        Iterator& operator ++()
        {
            _ptr++;

            return *this;
        }


        bool is_null()
        {
            return _ptr == nullptr;
        }

        const T* operator ->() const
        {
            assert(_ptr);

            return &_ptr->_item;
        }

        T* operator ->()
        {
            assert(_ptr);

            return &_ptr->_item;
        }

        friend bool operator ==(const Iterator &left, const Iterator &right)
        {
            return left._ptr == right._ptr;
        }

        friend bool operator !=(const Iterator &left, const Iterator &right)
        {
            return left._ptr != right._ptr;
        }

    private:
        node<T>* _ptr;
    };

    SList(bool ascending=true, bool unique =false)
        :_ascending(ascending),_unique(unique)
    {
        _Hptr = new node<T>;
        _clear_list(_Hptr);
    }

    ~SList<T>()
    {
        _clear_list(_Hptr);
    }
    SList(const SList<T> &copyThis)
    {
        _Hptr = _copy_list(copyThis._Hptr);
        _unique = copyThis._unique;
        _ascending = copyThis._ascending;
    }
    SList& operator =(const SList& RHS)
    {
        if(&RHS == this) {return *this;}
        _clear_list(_Hptr);
        _Hptr = _copy_list(RHS._Hptr);
        _unique = RHS._unique;
        _ascending = RHS._ascending;
        return *this;
    }

    typename SList<T>::Iterator Insert(T i)
    {
        return Iterator(_insert_sorted(_Hptr,i,_ascending));
    }

    T Delete(SList<T>::Iterator Node)
    {
        return _remove_node(_Hptr,Node._ptr);
    }

    T Remove_head()
    {
        return _remove_head(_Hptr);
    }

    void Print() const
    {
        _print_list(_Hptr);
    }

    typename SList<T>::Iterator Search(const T &key)
    {
        return Iterator(_search_list(_Hptr,key));
    }

    typename SList<T>::Iterator Prev(SList<T>::Iterator position)
    {
        return Iterator(_previous_node(_Hptr, position._ptr));
    }

    typename SList<T>::Iterator Insert_and_Add(const T& item)
    {
        if(_unique)
        {
            return Iterator(_insert_sorted_and_add(_Hptr,item,_ascending));
        }
        else
        {
            return Iterator(_insert_sorted(_Hptr,item,_ascending));
        }
    }

    T& operator[](int index)
    {
        return _at(_Hptr,index);
    }

    const T& operator[](int index) const
    {
        return _at(_Hptr,index);
    }

    typename SList<T>::Iterator Begin() const
    {
        return Iterator(_Hptr);
    }

    typename SList<T>::Iterator End() const
    {
        return Iterator(_last_node(_Hptr));
    }

    friend ostream& operator <<(ostream& outs, const SList<T>& l)
    {
        return _print_list(l._Hptr, outs);
    }


private:
    node<T>* _Hptr;
    bool _ascending;
    bool _unique;
};

#endif // SLIST_H
