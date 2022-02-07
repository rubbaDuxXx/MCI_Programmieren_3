#include <iostream>
using namespace std;

void ein_fehler() {
  // Wir haben einfach immer einen Fehler
  throw 23; // Wirf 23 als Ausnahme
}

int main() {
  try {
    ein_fehler();
  } catch (int &i) {
    cout << i << endl;
  }
}
