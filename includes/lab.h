#ifndef LAB_H
#define LAB_H
#include<iostream>
#include "lab.cpp"
using namespace std;

//Non-templated Functions
inline void lab_demo();

inline void login(int** labs, int lab, int station, int id);

inline void logout(int** labs, int* sizes, int id);

inline void menu_lab(int** labs, int* sizes);

inline void print_lab(int** labs, int* sizes);
//templated Functions

#endif // LAB_H
