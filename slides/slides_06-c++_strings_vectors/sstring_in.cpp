#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
  string s = "23 42 47";
  stringstream str_stream(s); // oder direkt str_stream("23 42 47")
  int a, b, c;
  str_stream >> a >> b >> c; // Einlesen der Daten

  cout << "a=" << a << " b=" << b << " c=" << c << endl;
} // Ausgabe: a=23 b=42 c=47
