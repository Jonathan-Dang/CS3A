#include <iostream>
using namespace std;

template <typename T>
void delete_repeat(T* a, int& size);

template <typename T>
T* find(T* a, T b, int size);

template <typename T>
void shift_left(T* array, T* pos, int& size);

template <typename T>
void print(T* array, int size);

//const bool DEBUG = true;

int main()
{
    cout << "=======================================================" << endl;
    cout << "            Test #1, int arrays" << endl;
    int CAP1 = 10;
    int arrayTest[] = {1,2,3,4,5,1,2,3,4,5};
    print(arrayTest,10);
    delete_repeat(arrayTest,CAP1);
    /*if(DEBUG)
    {
        cout << "           DEBUG: main: CAP1:|" << CAP1 << endl;
    }*/
    cout << "DELETED REPEATS: ";
    print(arrayTest,CAP1);
    cout << "=======================================================" << endl;
    cout << "            Test #2, char arrays" << endl;
    int CAP2 = 10;
    char arrayTest2[] = {'a','b','c','b','c','b','d','e','f','g'};
    print(arrayTest2,CAP2);
    delete_repeat(arrayTest2,CAP2);
    /*if(DEBUG)
    {
        cout << "           DEBUG: main: CAP2:|" << CAP2 << endl;
    }*/
    cout << "DELETED REPEATS: ";
    print(arrayTest2,CAP2);
    cout << "=======================================================" << endl;
    cout << "            Test #3, multi-repeated int arrays" << endl;
    int CAP3 = 10;
    int arrayTest3[] = {1,2,1,2,1,2,1,2,1,3};
    print(arrayTest3,CAP3);
    delete_repeat(arrayTest3,CAP3);
    /*if(DEBUG)
    {
        cout << "           DEBUG: main: CAP3:|" << CAP3 << endl;
    }*/
    cout << "DELETED REPEATS: ";
    print(arrayTest3,CAP3);
    cout << "=======================================================" << endl;
    cout << "            Test #4, double arrays" << endl;
    int CAP4 = 10;
    double arrayTest4[] = {1.1,1.1,2.0,2.0,5.0,5.0,5.5,6.0,6.6,10.0};
    print(arrayTest4,CAP4);
    delete_repeat(arrayTest4,CAP4);
    /*if(DEBUG)
    {
        cout << "           DEBUG: main: CAP4:|" << CAP4 << endl;
    }*/
    cout << "DELETED REPEATS: ";
    print(arrayTest4,CAP4);
    cout << "=======================================================" << endl;
    cout << "            Test #5, odd numbered arrays" << endl;
    int CAP5 = 9;
    int arrayTest5[] = {1,8,2,1,2,3,4,5,6};
    print(arrayTest5,CAP5);
    delete_repeat(arrayTest5,CAP5);
    /*if(DEBUG)
    {
        cout << "           DEBUG: main: CAP5:|" << CAP5 << endl;
    }*/
    cout << "DELETED REPEATS: ";
    print(arrayTest5,CAP5);
    cout << "==========================END==========================" << endl;
    return 0;
}

template <typename T>
void delete_repeat(T* array, int& size) //Function receives an array and a
{                                       //integer size and defines 3 pointers
    T* last;                            //within the function. It then makes a
    T* current;                         //while loop to constantly use find,
                                        //checking if it is a nullptr. If it
    current = array;                    //isn't it will shift left at the
    last = array;                       //location and decrease the size.
    last += size;
    while(current < last)
    {
        if(find(array,*current,size) == nullptr)
        {
            current++;
        }
        else
        {
            shift_left(array,(find(array,*current,size)),size);
            last--;
            /*if(DEBUG)
            {
                cout << "           DEBUG:delete_repeat:size:|" << size
                     << "|" << endl;
            }
            if(DEBUG)
            {
                cout << "           DEBUG:delete_repeat:*last:|" << *last
                     << "|" << endl;
            }*/

        }
    }
}

template <typename T>
T* find(T* array, T key, int size) //Function is getting an array[pointer]
{                                      //and checking if the dereference is
    int incre = 0;                     //same as the key, if it is it will
    T* hold = nullptr;                 //return the address, if not then it
    while(incre != size)               //will set the address to nullptr.
    {
        /*if(DEBUG)
        {
            cout << "           DEBUG:find: *array:|" << *array << "|" <<endl;
        }*/
        if(*array == key)
        {
            if(hold == nullptr)
            {
                hold = array;
                array++;
            }
            else
            {
                return(array);
            }
        }
        else
        {
            array++;
        }
        incre++;
    }
    return(nullptr);
}

template <typename T>
void shift_left(T* array, T* pos, int& size)
{                                      //Function will set address of array to
    array += size;                     //address of given position and
    T* hold;                           //increment pos 1 up, then will set
                                       //elements left one and then reduce
                                       //size by 1 unit.
    hold = pos;
    hold++;
    while(pos < array)                 //CHANGELOG: Error occuring when
    {                                  //attempting to change size variable.
        *pos = *hold;                  //size variable remains unchanged even
        pos++;                         //when passed by reference.
        hold++;
    }
    size--;
    /*if(DEBUG)
    {
        cout << "           DEBUG:shift_left:*size:|" << size
             << "|" << endl;
    }*/

}

template <typename T>
void print(T* array, int size)
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

