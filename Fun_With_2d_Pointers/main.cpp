/*Author: Jonathan Dang
 *Project: Fun with 2d Pointers
 *Purpose: To Create a library of 2d pointer functions
 *
 *NOTE: Project's Functions are not plemented into another file
 */
#include <iostream>
#include <../includes/twod.h>
using namespace std;

void init_test();

int main()
{
    cout<<endl<<endl<<endl;
    init_test();
    cout<<endl<<"======================END======================"<<endl;
    return 0;
}

void init_test()
{
    int array_sizes[5] = {5,3,3,4,-1};
    int** ptr2_INT = allocate<int>(array_sizes);
    init(ptr2_INT,array_sizes);
    print(ptr2_INT,array_sizes);
    read(ptr2_INT,array_sizes,10,10);
    write(ptr2_INT,array_sizes,10,10,10);
    print(ptr2_INT,array_sizes);
}
