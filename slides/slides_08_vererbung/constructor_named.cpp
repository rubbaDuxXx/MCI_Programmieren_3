#include <iostream>
using namespace std;

class C1 {
public:
  int a;
  C1(int pa) {
    a = pa;
    cout << "Konstruktor C1: " << pa << endl;
  }
};

class C2 : public C1 {
public:
  int b;
  C2(int pa, int pb) : C1(pa) {
    b = pb;
    cout << "Konstruktor C2: " << pa << " " << pb << endl;
  }
};

class C3 : public C2 {
public:
  int c;
  C3(int pa, int pb, int pc) : C2(pa, pb) {
    c = pc;
    cout << "Konstruktor C3: " << pa << " " << pb << " " << pc << endl;
  }
};

int main() {
  C3 c(1, 2, 3);
  cout << endl << "a:" << c.a << " b:" << c.b << " c:" << c.c << endl;
}
