#include <iostream>

namespace ns1 {
int f(int a) { return 2 * a; }
  namespace ns2 {
    int f(int a) { return a * a; }
  }
}

int main() {
  std::cout << "ns1::f(5) = " << ns1::f(5) << " ";
  std::cout << "ns1::ns2::f(5) = " << ns1::ns2::f(5) << std::endl;
  // Ausgabe: ns1::f(5) = 10 ns1::ns2::f(5) = 25
}
