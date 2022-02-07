#include "split.hpp"
#include <iostream>
using namespace std;

int globalvar = 12;

int rangesum(int start, int stop) {
    int sum = 0;
    for (int i = start; i <= stop; i++) {
        sum += i;
    }
    return sum;
}

void print_global_var() { cout << "Global Variable is " << globalvar << endl; }

void Basis::print() { cout << "In base class: a = " << a << endl; }

void Inherited::print() {
  cout << "In inherited class: a = " << a << " b = " << b << endl;
}
