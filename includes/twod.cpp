#include <iostream>
#include "twod.h"
using namespace std;
//Non-Templated Functions

inline int array_size(int* array) //counts elements of size array [subset of allocate]
{
    int rows = 0;
    rows = sizeof(array);
    return(rows);
}

inline bool is_valid(int* sizes, int row, int col)//checks if coords are valid
{
    int row_amount = array_size(sizes);

    if(row <= row_amount-1 && row > 0)
    {
        for(int i=0;i<row_amount;i++)
        {
            if(col <= *sizes && col > 0) return(true);
            sizes++;
        }
    }

    return(false);
}

//Templated Functions
template <typename T>
inline T* allocate(int size) //allocates 1d memory [ptr -> value]
{
    T* array = new T[size];
    return(array);
}

template <typename T>
inline T** allocate(int* sizes) //allocates 2d memory [ptr -> ptr]
{
    int rows = array_size(sizes);
    T** ptr_array = new T*[rows];
    T** walker = ptr_array;
    while(*sizes != -1)
    {
        *walker = allocate<T>((*sizes)+1);
        walker++;
        sizes++;
    }
    *walker = nullptr;
    return(ptr_array);
}

template <typename T>
inline void print(T** array, int* sizes) //prints entire **ptr sequence
{
    T** walker = array;
    while(*sizes != -1)
    {
        print(*walker,*sizes);
        walker++;
        sizes++;
    }
}

template <typename T>//Subset of print2d
inline void print(T* array, int size)
{
    int incre = 0;
    while(incre != size)
    {
        cout << "   " << *array << "   |";
        array++;
        incre++;
    }
    cout << endl;
}

template <typename T>
inline void init(T** array, int* size, T init_value)  //fills up entire **ptr with
{                                              //whatever I want
    T** walkerR = array;
    T* walkerC;
    T** last = walkerR;
    last += array_size(size);

    if(init_value == T())
    {
        while(walkerR < last)
        {
            walkerC = *walkerR;
            if(*size != -1)
            {
                init_value += 10;
                for (int i = 0;i<*size;i++)
                {
                    *walkerC = init_value+i;
                    walkerC++;
                }
            }
            walkerR++;
            size++;
        }
    }
    else
    {
        while(walkerR < last)
        {
            walkerC = *walkerR;
            if(*size != -1)
            {
                for (int i = 0;i<*size;i++)
                {
                    *walkerC = init_value;
                    walkerC++;
                }
            }
            walkerR++;
            size++;
        }
    }
}

template <typename T> //obtains the address of a value at specified coords
inline T* get(T** array, int* sizes, int rows, int col)
{
    T** ptr_row = array;
    T* ptr_col;
    if((is_valid(sizes,rows,col)))
    {
        ptr_row += (rows-1);
        ptr_col = *ptr_row;
        ptr_col += (col-1);
        return(&(*ptr_col));
    }
    else return(nullptr);
}

template <typename T>//prints contents of coords
inline void read(T** array, int* sizes, int rows, int col)
{
    T* address = get(array,sizes,rows,col);
    if(address == nullptr) cout << "Out of Range" << endl;
    else
    {
        cout << "The value at this location is: " << *address << endl;
    }
}

template <typename T>//writes/overrides contents at specified coords
inline void write(T** array, int* sizes, int rows, int col, T entry)
{
    T* address = get(array,sizes,rows,col);
    if(address == nullptr) cout << "Out of Range" << endl;
    else
    {
        *address = entry;
    }
}

template <typename T>//Deletes all contents of a pointer-pointer
inline void deallocate(T**& array, T* sizes)
{
    T**& walker = array;
    T* col_walker;

    while(*sizes != -1)
    {
        col_walker = *walker;
        delete [] col_walker;
        sizes++;
        walker++;
    }

    delete [] array;
    delete [] walker;
    delete array;
    delete walker;
}
