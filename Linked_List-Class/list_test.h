#ifndef LIST_TEST_H
#define LIST_TEST_H

#include <iostream>
#include "node.h"
#include "List.h"
using namespace std;

void test_List_class();

template<typename T>
ostream& Print_cursor(const List<T> list
                      , typename List<T>::Iterator cursor
                      , ostream& outs = cout);

#endif // LIST_TEST_H
