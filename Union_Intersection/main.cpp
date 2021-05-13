/*
 *Author: Jonathan Dang
 *Project: Union Intersection
 *Purpose: Combines two int arrays and copy the new array into a new one
 *          and detects and displays intersections between the two arrays.
 *
 *Notes: Union returns a crashing value, which disables the ability to run
 *      both the Union function and the Intersection function at the
 *      same time.
 */
#include <iostream>
using namespace std;

void copy(int* dest, int* src, int size);

void Union(int left[], int left_size, int right[], int right_size, int result[]
           , int& result_size);

void intersection(int left[], int left_size, int right[], int right_size,
                  int result[], int& result_size);

void test_Union();

void test_Intersection();

template <typename T>
void print(T* array, int size);

const bool DEBUG = true;
int main()
{
    cout << "=========================" << endl;
    test_Intersection();
    cout << "===========END===========" << endl;
    return 0;
}

void copy(int* dest, int* src, int size)
{
    int* last;
    last = src;
    last += size;
    /*if(DEBUG)
    {
        cout << "   DEBUG: COPY INITIATED" << endl;
    }*/
    do
    {
        *dest = *src;
        /*if(DEBUG)
        {
            cout << "               DEBUG: copy: *dest: |"<<*dest<<"|"<<endl;
        }
        if(DEBUG)
        {
            cout << "               DEBUG: copy: *src: |"<<*src<<"|"<<endl;
        }
        if(DEBUG)
        {
            cout << "           DEBUG: copy: size:|" << size << endl;
        }
        cout << endl;*/
        dest++;
        src++;
    }while(src < last);

}

template <typename T>
void print(T* array, int size)
{
    int incre = 0;
    //cout << "Array Output: ";
    do
    {
        cout << *array << " ";
        /*if(DEBUG)
        {
            cout << "               DEBUG: print: array: |"<<array<<"|"<<endl;
        }
        if(DEBUG)
        {
            cout << "               DEBUG: print: size: |"<<size<<"|"<<endl;
        }*/
        array++;
        incre++;
    }while(incre < size);
    cout << endl;
    /*if(DEBUG)
    {
        cout << "   DEBUG: PRINT INITIATED" << endl;
    }*/

}

void Union(int left[], int left_size, int right[], int right_size, int result[]
           , int& result_size)
{
    int* lastL = left + left_size;
    int* lastR = right + right_size;
    int* Al = left;
    int* Ar = right;
    int* dest = result;
    /*if(DEBUG)
    {
        cout << "   DEBUG: UNION INITIATED" << endl;
    }*/

    while(Al < lastL && Ar < lastR)
    {
        result_size++;
        if(*Al < *Ar)
        {
            *dest = *Al;
            Al++;
            dest++;
        }
        else if(*Ar < *Al)
        {
            *dest = *Ar;
            Ar++;
            dest++;
        }
        else
        {
            *dest = *Ar;
            Ar++;
            Al++;
            dest++;
        }
    }

    if(right_size == left_size)
    {
        result_size++;
        if(*Ar > *Al)
        {
            copy(dest,Ar,1);
        }
        else
        {
            copy(dest,Al,1);
        }
    }
    else if(Al < lastL)
    {
        int LOsize = left_size - right_size;
        result_size = result_size + LOsize;
        copy(dest,Al,LOsize);
        if(DEBUG) cout<<" DEBUG: Al < lastL" << endl;
    }
    else
    {
        int LOsize = right_size - left_size;
        result_size = result_size + LOsize;
        copy(dest,Ar,LOsize);
        if(DEBUG) cout << " DEBUG: Ar < lastR" << endl;
    }
}

void Intersection(int left[], int left_size, int right[], int right_size,
                  int result[], int& result_size)
{
    int* lastL = left + left_size;
    int* lastR = right + right_size;
    int* aL = left;
    int* aR = right;
    int* dest = result;
    /*if(DEBUG)
    {
        cout << "   DEBUG: INTERSECTION INITIATED" << endl;
    }*/

    while(aL < lastL && aR < lastR)
    {
        if(*aL == *aR)
        {
            result_size++;
            *dest = *aL;
            aL++;
            aR++;
            dest++;
        }
        else if(*aL < *aR)
        {
            aL++;
        }
        else
        {
            aR++;
        }
    }
}

void test_Union()
{
    int Left[20] = {5,10,15,20,25,30};
    int Right[20] =  //{5,10,15,20,25,30};
    {3,10,13,20,23,28}; //,30,33,35,36,37,38,39,40,41,42,43};
    int u_size = 0;
    int* u_array = new int[u_size];

    cout << "The Union of :" <<endl;
    print(Left,6);
    cout << " and " << endl;
    print(Right,6);
    cout << " is " << endl;
    Union(Left,6,Right,6,u_array,u_size);
    print(u_array,u_size);
}

void test_Intersection()
{
    int Left[20] = {5,10,15,20,25,30};
    int Right[20] = {3,10,13,20,23,28,30,33,35};
    int i_size = 0;
    int* i_array = new int[i_size];

    cout << "The Intersections of:" << endl;
    print(Left,6);
    cout << " and " << endl;
    print(Right,9);
    cout << " is " << endl;
    Intersection(Left,6,Right,9,i_array,i_size);
    print(i_array,i_size);
}
