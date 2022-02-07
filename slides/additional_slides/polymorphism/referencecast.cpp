#include <iostream>
using namespace std;

struct A {
  int a;
};

struct B : A {
  int b;
};

int main() {
  B b;
  A &a = b;
  cout << a.a << endl;

  A a2 = b;
  cout << a2.a << endl;
}
