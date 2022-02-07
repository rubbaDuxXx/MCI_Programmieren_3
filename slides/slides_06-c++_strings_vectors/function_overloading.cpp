#include <iostream>

// int wird quadriert
int f(int a) { return a * a; }
// Bei double wird 10 hinzugezählt
double f(double a) { return a + 10; }
// short wird verdoppelt
short f(short a) { return a * 2; }

int main() {
  int a = 5;
  double b = 10;
  short c = 4;

  std::cout << "int: " << f(a) << " ";
  std::cout << "double: " << f(b) << " ";
  std::cout << "short: " << f(c) << " ";
}
