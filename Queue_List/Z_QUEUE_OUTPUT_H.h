#ifndef Z_QUEUE_OUTPUT_H_H
#define Z_QUEUE_OUTPUT_H_H
/*

  ALL TESTS VERIFIED
====================


H->[9]->[8]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->[0]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 0
H->[9]->[8]->[7]->[6]->[5]->[4]->[3]->[2]->[1]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 1
H->[9]->[8]->[7]->[6]->[5]->[4]->[3]->[2]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 2
H->[9]->[8]->[7]->[6]->[5]->[4]->[3]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 3
H->[9]->[8]->[7]->[6]->[5]->[4]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 4
H->[9]->[8]->[7]->[6]->[5]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 5
H->[9]->[8]->[7]->[6]->|||
P[o]p P[u]sh [R]andom E[x]it
oo
Removed: 6
H->[9]->[8]->[7]->|||
P[o]p P[u]sh [R]andom E[x]it
Removed: 7
H->[9]->[8]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 8
H->[9]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 9
H->|||
P[o]p P[u]sh [R]andom E[x]it
o
H->|||
P[o]p P[u]sh [R]andom E[x]it
o
H->|||
P[o]p P[u]sh [R]andom E[x]it
o
H->|||
P[o]p P[u]sh [R]andom E[x]it
o
H->|||
P[o]p P[u]sh [R]andom E[x]it
r
H->[0]->|||
P[o]p P[u]sh [R]andom E[x]it
r
H->[13]->[0]->|||
P[o]p P[u]sh [R]andom E[x]it
r
H->[76]->[13]->[0]->|||
P[o]p P[u]sh [R]andom E[x]it
r
H->[46]->[76]->[13]->[0]->|||
P[o]p P[u]sh [R]andom E[x]it
r
H->[53]->[46]->[76]->[13]->[0]->|||
P[o]p P[u]sh [R]andom E[x]it
r
H->[22]->[53]->[46]->[76]->[13]->[0]->|||
P[o]p P[u]sh [R]andom E[x]it
r
H->[4]->[22]->[53]->[46]->[76]->[13]->[0]->|||
P[o]p P[u]sh [R]andom E[x]it
r
H->[68]->[4]->[22]->[53]->[46]->[76]->[13]->[0]->|||
P[o]p P[u]sh [R]andom E[x]it
r
H->[68]->[68]->[4]->[22]->[53]->[46]->[76]->[13]->[0]->|||
P[o]p P[u]sh [R]andom E[x]it
r
H->[94]->[68]->[68]->[4]->[22]->[53]->[46]->[76]->[13]->[0]->|||
P[o]p P[u]sh [R]andom E[x]it
r
H->[38]->[94]->[68]->[68]->[4]->[22]->[53]->[46]->[76]->[13]->[0]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 0
H->[38]->[94]->[68]->[68]->[4]->[22]->[53]->[46]->[76]->[13]->|||
P[o]p P[u]sh [R]andom E[x]it
u
Input Value: 10

H->[10]->[38]->[94]->[68]->[68]->[4]->[22]->[53]->[46]->[76]->[13]->|||
P[o]p P[u]sh [R]andom E[x]it
u
Input Value: 2000000

H->[2000000]->[10]->[38]->[94]->[68]->[68]->[4]->[22]->[53]->[46]->[76]->[13]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 13
H->[2000000]->[10]->[38]->[94]->[68]->[68]->[4]->[22]->[53]->[46]->[76]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 76
H->[2000000]->[10]->[38]->[94]->[68]->[68]->[4]->[22]->[53]->[46]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 46
H->[2000000]->[10]->[38]->[94]->[68]->[68]->[4]->[22]->[53]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 53
H->[2000000]->[10]->[38]->[94]->[68]->[68]->[4]->[22]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 22
H->[2000000]->[10]->[38]->[94]->[68]->[68]->[4]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 4
H->[2000000]->[10]->[38]->[94]->[68]->[68]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 68
H->[2000000]->[10]->[38]->[94]->[68]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 68
H->[2000000]->[10]->[38]->[94]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 94
H->[2000000]->[10]->[38]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 38
H->[2000000]->[10]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 10
H->[2000000]->|||
P[o]p P[u]sh [R]andom E[x]it
o
Removed: 2000000
H->|||
P[o]p P[u]sh [R]andom E[x]it
x
=========END========

*/
#endif // Z_QUEUE_OUTPUT_H_H
