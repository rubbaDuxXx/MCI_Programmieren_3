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
  void print() { cout << "Hallo: Abgeleitete Klasse " << num1 << endl; }
};

int main() {
  HelloWorldBasis w1;
  w1.print(); // Output: Hallo : Basisklasse 42
  HelloWorldAbgeleitet w2;
  w2.print();  // Output: Hallo : Abgeleitete Klasse 42
  cout << "num = " << w2.num1 << endl;  // 42
  cout << "num2 = " << w2.num2 << endl; // 23
}
