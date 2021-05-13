#ifndef LIST_H
#define LIST_H
#include "node.h"
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class List{
public:

    class Iterator{
    public:
        friend class List;

        Iterator(node<T>* p = nullptr):_ptr(p){}

        const T& operator *() const
        {
            assert(_ptr);

            return _ptr->_item;
        }

        friend Iterator operator ++(Iterator& i, int unused)
        {
            assert(i._ptr);
            Iterator hold;
            hold = i;
            i = i._ptr->_next;
            return hold;
        }

        Iterator operator ++()
        {
            assert(_ptr);
            this = this->next();
            return *this;
        }

        const node<T>* operator ->()const
        {
            assert(_ptr);
            return &(_ptr->_item);
        }

        T* operator ->()
        {
            assert(_ptr);
            return &(_ptr->_item);
        }

        friend bool operator ==(const Iterator& LHS
                                , const Iterator& RHS)
        {
            if(LHS._ptr == RHS._ptr) {return true;}
            else {return false;}
        }

        friend bool operator !=(const List<T>::Iterator& LHS
                                , const List<T>::Iterator& RHS)
        {
            if(LHS._ptr != RHS._ptr) {return true;}
            else {return false;}
        }

        Iterator next()
        {
            assert(_ptr != nullptr);
            return Iterator(_ptr->_next);
        }

    private:
        node<T>* _ptr;
    };

    List()
    {
        _Hptr = new node<T>;
        _clear_list(_Hptr);
    }

    ~List()
    {
        _clear_list(_Hptr);
    }
    List(const List<T> &copyThis)
    {
        _Hptr = _copy_list(copyThis._Hptr);
    }
    List& operator =(const List& RHS)
    {
        if(&RHS == this) {return *this;}
        _clear_list(_Hptr);
        _Hptr = _copy_list(RHS._Hptr);
        return *this;
    }


    typename List<T>::Iterator InsertHead(const T& item)
    {
        return Iterator(_insert_head(_Hptr, item));
    }

    typename List<T>::Iterator InsertAfter(T i, List<T>::Iterator afterThis)
    {
        return Iterator(_insert_after(_Hptr,afterThis._ptr,i));
    }

    typename List<T>::Iterator InsertBefore(T i, List<T>::Iterator beforeThis)
    {
        return Iterator(_insert_before(_Hptr,beforeThis._ptr,i)) ;
    }

    typename List<T>::Iterator InsertSorted(T i, bool ascending)
    {
        return Iterator(_insert_sorted(_Hptr,i,ascending));
    }

    T Delete(List<T>::Iterator& Node)
    {
        return _remove_node(_Hptr,Node._ptr);
    }

    T Remove_head()
    {
        return _remove_head(_Hptr);
    }

    void Print()
    {
        _print_list(_Hptr);
    }

    typename List<T>::Iterator Search(const T &key)
    {
        return Iterator(_search_list(_Hptr,key));
    }

    typename List<T>::Iterator Prev(List<T>::Iterator position)
    {
        return Iterator(_previous_node(_Hptr, position._ptr));
    }

    T& operator[](int index) const
    {
        return _at(_Hptr,index);
    }

    typename List<T>::Iterator Begin() const
    {
        return Iterator(_Hptr);
    }

    typename List<T>::Iterator End() const
    {
        return Iterator(_last_node(_Hptr));
    }

    friend ostream& operator <<(ostream& outs, const List<T>& l)
    {
        return _print_list(l._Hptr, outs);
    }


private:
    node<T>* _Hptr;
};

#endif // LIST_H
