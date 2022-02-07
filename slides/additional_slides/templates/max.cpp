#include <iostream>
using namespace std;

template <typename T> T t_max(T a, T b) { // t_max weil es max schon gibt
  T ergebnis; // Wir koennen auch Variablen vom unbekannten Typ erzeugen
  if (a > b)
    ergebnis = a;
  else
    ergebnis = b;

  return ergebnis;
}

int main() {
  int a = 23, b = 42;
  double c = 34.2, d = 1.3;
  cout << "max int = " << t_max(a, b) << endl;
  cout << "max double = " << t_max(c, d) << endl;
  // Was passiert wenn wir Typen mixen?
  // cout << "max int/double = " << t_max(a, c) << endl;
}
