#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <cassert>
#include "../Linked_List-Class/List.h"
using namespace std;

template <typename T>
class Queue{
public:
    class Iterator{
    public:
        friend class Queue;
        Iterator(typename List<T>::Iterator q):_q(q){}

        const T& operator *() const
        {
            return *_q;
        }

        T operator *()
        {
            return *_q;
        }

        T* operator ->()
        {
            return _q.operator->();
        }

        const T* operator ->() const
        {
            return _q.operator->();
        }

        friend Iterator operator ++(Iterator& i, int unused)
        {
            Iterator hold(i);
            i._q++;
            return hold;
        }

        Iterator& operator ++()
        {
            _q++;

            return *this;
        }

        friend bool operator ==(const Iterator& LHS, const Iterator& RHS)
        {
            return LHS._q == RHS._q;
        }

        friend bool operator !=(const Iterator& LHS, const Iterator& RHS)
        {
            return LHS._q != RHS._q;
        }


    private:
        typename List<T>::Iterator _q;
    };

    Queue()
    {
        _size = 0;
        _rear = nullptr;
    }

    ~Queue(){};
    Queue(const Queue<T> &copyThis)
    {
        _Q = copyThis._Q;
        _rear = _Q.End();
        _size = copyThis._size;
    }
    Queue& operator =(const Queue& RHS)
    {
        if(&RHS == this) {return *this;}
        _Q = RHS._Q;
        _rear = _Q.End();
        _size = RHS._size;
        return *this;
    }

    const T Pop()
    {
        assert(_size);
        T i = _Q.Delete(_rear);
        if(_size > 1)
        {
            _rear = _Q.End();
        }

        _size--;
        return i;
    }

    void Push(T insert)
    {
        _Q.InsertHead(insert);
        _rear = _Q.End();
        _size++;
    }

    void Print()
    {
        return _Q.Print();
    }

    typename Queue::Iterator Begin() const
    {
        return Iterator(_Q.Begin());
    }

    typename Queue::Iterator End() const
    {
        return Iterator(nullptr);
    }

    int Size() {return _size;}

    bool Empty()
    {
        return _size == 0;
    }

private:
    List<T> _Q;
    typename List<T>::Iterator _rear;
    int _size;
};



#endif // QUEUE_H
