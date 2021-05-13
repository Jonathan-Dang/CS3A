#include "mcount.h"
#include <iostream>
using namespace std;

MCount::MCount():counter(0000)
{
    //EMPTY
}

int MCount::add_1()
{
    MCount::counter += 1;
    return(MCount::counter);
}

int MCount::add_10()
{
    MCount::counter += 10;
    return(MCount::counter);
}

int MCount::add_100()
{
    MCount::counter += 100;
    return(MCount::counter);
}

int MCount::add_1000()
{
    MCount::counter += 1000;
    return(MCount::counter);
}

int MCount::reset()
{
    MCount::counter = 0;
    return(MCount::counter);
}

int MCount::count() const
{
    return(MCount::counter);
}

bool MCount::is_error() const
{
    if(MCount::counter > 9999)
    {
        return(true);
    }
    return(false);
}














