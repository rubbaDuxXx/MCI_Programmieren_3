#include <iostream>
using namespace std;

class Basis {
public: virtual void print() { cout << "Hallo von der Basisklasse" << endl; }
};
class Abgeleitet1 : public Basis {
public: void print() { cout << "Hallo von der abgeleiteten Klasse 1" << endl; }
};
class Abgeleitet2 : public Basis {
public: void print() { cout << "Hallo von der abgeleiteten Klasse 2" << endl; }
};

void print_with_introduction(Basis &a) {
  cout << "Unsere Klasse möchte folgendes sagen: " << endl;
  a.print();
}

int main() {
  Basis b; Abgeleitet1 a1; Abgeleitet2 a2;

  print_with_introduction(b);
  print_with_introduction(a1);
  print_with_introduction(a2);
}
