#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <cassert>
#include "twod.h"
using namespace std;

const int DEFAULT_CAP = 100;

template <class T>
class Vector{
public:

    Vector<T>(unsigned int capacity = DEFAULT_CAP);

    // big three:
    Vector(const Vector& RHS);
    Vector& operator=(const Vector& RHS);
    ~Vector();

    //member access functions:
    const T operator [](const unsigned int index) const;
    T& operator [](const unsigned int index);
    T& at(const int index);       //return reference to item at position index
    const T at(const int index) const;//return a const item at position index
    T& front() const;             //return item at position 0.
    T& back() const;              //return item at the last position


    //Push and Pop functions:
    Vector& operator +=(const T& item); //push_back
    void push_back(const T item);      //append to the end
    T pop_back();                       //remove last item and return it


    //Insert and Erase:
    void insert(const int insert_here, const T& insert_this); //insert at pos
    void erase(const int erase_index);        //erase item at position
    int index_of(const T& item);        //search for item. retur index.

    //size and capacity:
    void set_size(int size);            //enlarge the vector to this size
    void set_capacity(int capacity);    //allocate this space
    int size() const {return _size;}    //return _size
    int capacity() const {return _capacity;} //return _capacity

    bool empty() const;                 //return true if vector is empty

    //Boolean Functions
    template <class U>
    friend bool operator ==(const Vector<U>& LHS, const Vector<U>& RHS);

    template <class U>
    friend bool operator !=(const Vector<U>& LHS, const Vector<U>& RHS);

    //OUTPUT:
    template <class U>
    friend ostream& operator <<(ostream& outs, const Vector<U>& _a);
private:
    int _size;
    int _capacity;
    T* _vector;
};

//===========================================================================//
//                          Vector Class Definitions                         //
//===========================================================================//

template <typename T>
Vector<T>::Vector(unsigned int capacity)
{
    _vector = nullptr;
    _capacity = capacity;
    _vector = allocate<T>(_capacity);
    _size = 0;
}

template <typename T>
Vector<T>::Vector(const Vector& RHS)
{
    _vector = nullptr;
    _vector = allocate<T>(RHS.capacity());
    _capacity = RHS.capacity();
    _size = RHS.size();
    copy(_vector,RHS._vector,RHS._size);
}

template <typename T>
Vector<T>& Vector<T>::operator =(const Vector<T>& RHS)
{
    if(this == &RHS) {return *this;}

    deallocate(_vector);
    _capacity = RHS.capacity();
    _size = RHS.size();    
    _vector = allocate<T>(RHS.capacity());
    copy(_vector,RHS._vector,RHS.size());
    return *this;
}

template <typename T>
Vector<T>::~Vector<T>()
{
    deallocate(_vector); //delete [] array
}

template <typename T>
const T Vector<T>::operator [](const unsigned int index) const
{
    assert(index >= 0 || index < _size);

    T value;
    T* hold = _vector;
    hold += index;
    value = *hold;
    return value;
}

template <typename T>
T& Vector<T>::operator [](const unsigned int index)
{
    assert(index >= 0 || index < _size);

    T* hold = _vector;
    hold += index;
    return *hold;
}

template <typename T>
T& Vector<T>::at(int index)
{
    assert(index >= 0 || index < _size);

    T* hold = _vector;
    hold += index;
    return *hold;
}

template <typename T>
const T Vector<T>::at(int index) const
{
    assert(index >= 0 || index < _size);

    T* hold = _vector;
    hold += index;
    return *hold;
}

template <typename T>
T& Vector<T>::front() const
{
    assert(_vector);

    return *_vector;
}

template <typename T>
T& Vector<T>::back() const
{
    assert(empty());

    T* hold = _vector;
    hold += _size-1;
    return *hold;
}

template <typename T>
Vector<T>& Vector<T>::operator +=(const T& item)
{
    push_back(item);
    return *this;
}

template <typename T>
void Vector<T>::push_back(const T item)
{
    if(_size >= _capacity)
    {
        set_capacity(_capacity*2);
    }
    else
    {
        T* hold = _vector + _size++;
        *hold = item;
    }
}

template <typename T>
T Vector<T>::pop_back() //Deletes end of array, returns it
{
    T* hold = _vector;
    T value;
    assert(_size);

    hold += _size-1;
    value = *hold;
    hold = nullptr;
    _size--;
    if(_size < _capacity/2 && (_capacity/2))
    {
        _vector = reallocate(_vector,_size,_capacity/2);
        _capacity /= 2;
    }
    return value;
}

template <typename T>
void Vector<T>::insert(const int insert_here, const T& insert_this)
{
    assert(insert_here < _capacity && insert_here >= 0);

    if(insert_here >= _size)
    {
        push_back(insert_this);
    }
    else
    {
        if(_size >= _capacity)
        {
            T* hold = nullptr;
            hold = allocate<T>(_capacity*2);
            copy(hold,_vector,_size);
            delete [] _vector;
            _vector = hold;
            _capacity *= 2;
        }
        T* hold = _vector + insert_here;
        shift_right((_vector + _size++)-1, hold);
        *hold = insert_this;
    }

}

template <typename T>
void Vector<T>::erase(const int erase_index)
{
    assert(erase_index >= 0 || erase_index < _capacity);
    if(erase_index == _size-1)
    {
        pop_back();
    }
    else
    {
        T* hold = _vector + erase_index;
        shift_left(hold,(_vector + _size-1));
        _size--;
    }
}

template <typename T>
int Vector<T>::index_of(const T& item)
{
    int index = -1;
    for(int i = 0; i != _capacity; i++)
    {
        if(item == Vector<T>::operator[](i))
        {
            return index;
        }
        index++;
    }
    return -1;
}

template <typename T>
void Vector<T>::set_size(int size)
{
    if(size > _capacity)
    {
        set_capacity(_capacity*2);
    }
    _size = size;
}

template <typename T>
void Vector<T>::set_capacity(int capacity)
{
    if(capacity > _size)
    {
        _capacity = capacity;
        T* hold = nullptr;
        hold = allocate<T>(_capacity*2);
        copy(hold,_vector,_size);
        delete [] _vector;
        _vector = hold;
        _capacity *= 2;
    }

}

template <typename T>
bool Vector<T>::empty() const
{
    return _size;
}

template <class U>
bool operator ==(const Vector<U>& LHS, const Vector<U>& RHS)
{
    if(LHS.size() != RHS.size()) {return false;}

    for(int i = 0; i < LHS.size(); i++)
    {
        if(LHS[i] != RHS[i])
        {
            return false;
        }
    }

    return true;
}


template <class U>
ostream& operator <<(ostream& outs, const Vector<U>& _a)
{
    for(int i = 0; i <= _a.size(); i++)
    {
        outs << _a[i];
        if(i == _a.size())
        {
            outs << " |";
        }
        else
        {
            outs << " ";
        }
    }

    return outs;
}

#endif // VECTOR_H
