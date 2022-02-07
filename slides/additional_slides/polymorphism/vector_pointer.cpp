#include <iostream>
#include <vector>
using namespace std;

class Basis {
public: virtual void print() { cout << "Hallo von der Basisklasse" << endl; }
};
class Abgeleitet : public Basis {
public: void print() { cout << "Hallo von der abgeleiteten Klasse 1" << endl; }
};

int main() {
  vector<Basis *> vec;
  Basis b1, b2;
  Abgeleitet a1, a2;
  vec.push_back(&b1);
  vec.push_back(&b2);
  vec.push_back(&a1);
  vec.push_back(&a2);

  for (auto &e : vec)
    (*e).print();
}
