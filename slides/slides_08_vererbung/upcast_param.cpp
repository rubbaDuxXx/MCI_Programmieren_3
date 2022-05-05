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

void callmyprint(Basis &b) { b.print(); }

int main() {
  Abgeleitet ab;
  ab.a = 42; ab.b = 23;
  ab.print(); // Abgeleitete Klasse mit Nummern 42 und 23
  callmyprint(ab); // Basisklasse mit Nummer 42
  // ab wird implizit in Basis konvertiert
}
