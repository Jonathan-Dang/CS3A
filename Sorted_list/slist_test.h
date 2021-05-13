#ifndef SLIST_TEST_H
#define SLIST_TEST_H


#include <iostream>
#include "../Linked_List-Class/node.h"
#include "slist.h"
using namespace std;

void test_SList_class();

template<typename T>
ostream& Print_cursor(const SList<T> list
                      , typename SList<T>::Iterator cursor
                      , ostream& outs = cout);

#endif // SLIST_TEST_H
