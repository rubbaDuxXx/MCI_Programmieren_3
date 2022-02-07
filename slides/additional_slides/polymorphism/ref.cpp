#include <iostream>
using namespace std;

void swap(int& first, int& second) {
  int tmp = first;
  first = second;
  second = tmp;
}

int main() {
  int a = 20;
  int b = 40;
  int& ra = a;
  int& rb = b;
  cout << "a = " << a << ", b = " << b << endl;
  swap(ra, rb);
  cout << "a = " << a << ", b = " << b << endl;
}
