/*
* Author: Jonathan Dang
* Project: Fun with Pointers
* Purpose: Using the Pointer variable to copy array elements to another array
*/
#include <iostream>
using namespace std;

void copy(int* dest, int* src, int size);
void print(int* array, int size);
bool is_array_empty(int* array);
const int CAPACITY = 10;
//const bool DEBUG = true;

int main()
{
    int array1[CAPACITY+1] = {1,2,3,4,5,6,7,8,9,10};
    int array2[CAPACITY+1] = {};
    int array3[CAPACITY+1] = {10,9,8,7,6,5,4,3,2,1};

    cout << endl << "Fun with Pointers Extra Credit Project"
         << endl << endl;
    cout << "Original Arrays:" << endl;
    cout << "Array 1: ";
    print(array1,10);
    cout << "Array 2 is left empty." << endl
         << "Array 3: ";
    print(array3,10);

    cout << "============================" << endl;

    cout << "Appending Arrays Test" << endl;
    if(is_array_empty(array1))              //Checking if the array
    {                                       //is empty first
        cout << "ERROR: Array is empty." << endl;
    }
    else
    {
        copy(array2,array1,8);              //Copies content of array 1
        print(array1,10);                   //to array 2   [Appending]
        print(array2,8);
    }


    cout << "============================" << endl;

    cout << "Replacing Arrays Test" <<endl;
    if(is_array_empty(array1))              //Checking if the array
    {                                       //is empty first
        cout << "ERROR: Array is empty." << endl;
    }
    else
    {
        copy(array3,array1,5);              //Copies content of array 1
        print(array1,10);                   //to array 3   [Replacing]
        print(array3,10);
    }

    cout << "============================" << endl;

    int array1_2[CAPACITY+1] = {1,2,3,4,5,6,7,8,9,10};
    int array2_2[CAPACITY+1] = {};          //resetting the array to run this
                                            //test
    cout << "Attempting to Copy empty array to a pre-existing array" << endl;
    if(is_array_empty(array2_2))            //Checking if the array
    {                                       //is empty first
        cout << "ERROR: Array is empty." << endl;
    }
    else
    {
        copy(array1_2,array2_2,10);         //Note that this will never
        print(array2_2,10);                 //run because array2 is empty
        print(array1_2,10);
    }

    cout << "=============END============" << endl;
    cout << endl << endl << endl;
}

void copy(int* dest, int*src, int size)
{
    int incre = 0;
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
            cout << "               DEBUG: copy: incre: |"<<incre<<"|"<<endl;
        }
        cout << endl;*/
        dest++;
        src++;
        incre++;
    }while(incre != size);

}

void print(int* array, int size)
{
    int incre = 0;
    cout << "Array Output: ";
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
    }while(incre != size);
    cout << endl;
}

bool is_array_empty(int* array)
{
    if(*array == NULL) return(true);
    else return(false);
}
