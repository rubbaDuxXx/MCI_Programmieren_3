#include <iostream>
using namespace std;

class average {
private:
  double _sum;
  int _count;

public:
  double avg;

  average() { // Standardkonstruktor
    _sum = 0;
    _count = 0;
    avg = 0;
  }

  average(double sum, int count) { // Weiterer Konstruktor
    _sum = sum;
    _count = count;
    avg = _sum / _count;
  }

  void add(double val) {
    _sum += val;
    _count++;
    avg = _sum / _count;
  }
};

int main() {
  average a;
  average b(12, 6);
  cout << "a " << a.avg << endl;
  cout << "b " << b.avg << endl;
  a.add(23);
  a.add(27);
  a.add(71);
  cout << "a " << a.avg << endl;
}
