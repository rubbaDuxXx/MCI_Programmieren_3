#include <iostream>
#include <vector>
using namespace std;

class Basis {
public:
  virtual void print() { cout << "Hallo von der Basisklasse" << endl; }
};
class Abgeleitet1 : public Basis {
public:
  void print() { cout << "Hallo von der abgeleiteten Klasse 1" << endl; }
};

int main() {
    // Vektor aus Zeigern    
}
