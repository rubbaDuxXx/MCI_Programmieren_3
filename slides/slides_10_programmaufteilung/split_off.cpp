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

class Basis {
public:
  int a = 23;
  void print() { cout << "In base class: a = " << a << endl; }
};

class Inherited : public Basis {
public:
  int b = 42;
  void print() {
    cout << "In inherited class: a = " << a << " b = " << b << endl;
  }
};

int main() {
  cout << rangesum(10, 20) << endl;
  print_global_var();

  Basis b;
  Inherited i;
  b.print();
  i.print();
}
