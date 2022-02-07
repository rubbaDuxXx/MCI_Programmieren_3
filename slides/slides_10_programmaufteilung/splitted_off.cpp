#include "split.hpp"
#include <iostream>
using namespace std;

int main() {
  cout << rangesum(10, 20) << endl;
  print_global_var();

  Basis b;
  Inherited i;
  b.print();
  i.print();
}
