#include <iostream>
using namespace std;

class Basis {
public:
  int a;
  void print() { cout << "Basisklasse mit Nummer " << a << endl; }
};

class Abgeleitet : public Basis {
public:
  int b;
    void print() { cout << "Abgeleitete Klasse mit Nummern " << a
                        << " und " << b << endl; }
};

int main() {
  Abgeleitet ab;
  ab.a = 42; ab.b = 23;
  ab.print(); // Abgeleitete Klasse mit Nummer 42 und 23
  Basis bc = ab;
  bc.print(); // Basisklasse mit Nummer 42
  Basis &b = ab;
  b.print(); // Basisklasse mit Nummer 42
}
