#include <iostream>
#include <exception>
using namespace std;

void ein_fehler() {
  // Wir haben immer einen Fehler
  throw runtime_error("Oh nein, ein Fehler!!");
}

int main() {
    cout << "Alles OK" << endl;
    ein_fehler();
    cout << "Immer noch alles OK" << endl;
}
