#include <iostream>

class C1 {
public:
  int i;
  C1() { i = 23; }
};

class C2 : public C1 {
public:
  int j;
  C2() { j = 42; }
};

int main() {
  C2 c;
  std::cout << c.i << " " << c.j << std::endl; // Output: 23 42
}
