#ifndef PLANE_H
#define PLANE_H
#include <iostream>
#include "plane.cpp"
using namespace std;

//Non-templated Functions
inline void plane_demo();

inline void print_plane(bool** plane, int* sizes);

inline void reserve(bool** plane, int* sizes, int lab, char station);

inline void cancel(bool** plane, int* sizes,int lab, char station);

inline void menu_plane(bool** plane, int* sizes);

//templated Functions

#endif // PLANE_H
