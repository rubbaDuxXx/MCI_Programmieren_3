#include <iostream>
using namespace std;

class HelloWorldBasis {
public:
  int num1 = 42;
  void print() { cout << "Hallo: Basisklasse " << num1 << endl; }
};

class HelloWorldAbgeleitet : public HelloWorldBasis {
public:
  int num2 = 23;
  void print() {
    HelloWorldBasis::print();
    cout << "Hallo: Abgeleitete Klasse " << num1 << endl;
  }
};

int main() {
  HelloWorldAbgeleitet w2;
  w2.print();
  // Output:
  // Hallo : Basisklasse 42
  // Hallo : Abgeleitete Klasse 42
}
