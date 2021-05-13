/* Author: Jonathan Dang
 * Project: Vectors
 * Purpose: 64 bit version to match compatibility
 */
#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
    cout << "=========================================================\n";
    Vector<int> v(15);
        v.set_size(10);
        //=====this is where all the testing begins=====
        cout << "This is the initialized vector: ";
        cout << v << endl;
        //testing all the functions at,front,back
        v.insert(4,32);
        cout << "This is the vector after the insert function: ";
        cout << v << endl;
        cout << "Testing the [at()]... Number at index 4 is: "<< v.at(4) << endl;
        cout << "Testing the [front()]... the first number at position 0: " << v.front() << endl;
        cout << "Testing the [back()]... the last number at the last position: " << v.back() << endl;
        cout << "Testing the [push_back(item)]... Array after appended the number 57 : ";
        v.push_back(57);
        cout << v << endl;
        cout << "Testing the [pop_back()]... Deleting the number " << v.pop_back() <<": ";
        cout << v << endl;
        cout << "Testing the [erase()]... Erasing the first index: ";
        v.erase(0);
        cout << v << endl;
        cout << "Testing the [index_of()]... The index of 32 is at index: " << v.index_of(32) << endl;
        Vector<int> v1(20);
        v1.set_size(15);
        cout << "Is v and v1 equal? : ";
        if(v1==v){
            cout << "True" << endl;
        }else{
            cout << "False" << endl;
        }
        Vector<int> v2(v);
        cout << "is v and v2 equal? : ";
        if(v2==v){
            cout << "True" << endl;
        }else{
            cout << "False" << endl;
        }
        //Testing the += operator
        v += 172;
        cout << "Testing the += operator and <<. This is the vector after appending 172: ";
        cout << v << endl;

        for(int i = 0; i < 1000; i++)
        {
            v += 1;
        }
    cout << "=============================END=========================\n";
    return 0;
}
