
#include <iostream>
using namespace std;

class tempconv {
private:
  double _kelvin;

public:
  tempconv() { _kelvin = 0; }  // Standardkonstruktor

  // Memberfunktionen zum Setzen der Temperatur
  void set_kelvin(double kelvin) { _kelvin = kelvin; }
  void set_celsius(double celsius) { _kelvin = celsius + 273.15; }
  void set_fahrenheit(double fahrenheit) {
    _kelvin = (fahrenheit + 459.67) * (5.0 / 9.0);
  }

  // Memberfunktionen zum Auslesen der Temperatur
  double get_kelvin() { return _kelvin; }
  double get_celsius() { return _kelvin - 273.15; }
  double get_fahrenheit() {
    return _kelvin * (9.0 / 5.0) - 459.67;
  }
}; // Ende der tempconv-Klasse

int main() {
  tempconv a;
  cout << "Anfang:" << endl;
  cout << "Temp: " << a.get_kelvin() << "K" << endl;
  cout << "Temp: " << a.get_celsius() << "C" << endl;
  cout << "Temp: " << a.get_fahrenheit() << "F" << endl << endl;

  a.set_celsius(-40);
  cout << "-40C = " << a.get_fahrenheit() << "F" << endl;
}
