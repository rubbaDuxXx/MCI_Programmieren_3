#include <iostream>
using namespace std;

class Basisklasse {
private:
  int _i1;
  int _i2;

public:
  Basisklasse(int i1, int i2) {
    _i1 = i1;
    _i2 = i2;
  }

  int sum() { return _i1 + _i2; }
};

class AbgeleiteteKlasse : public Basisklasse {
private:
  int _i3;

public:
  AbgeleiteteKlasse(int i1, int i2, int i3) : Basisklasse(i1, i2) { _i3 = i3; }

  int sum() { return Basisklasse::sum() + _i3; }
};

int main() {
    AbgeleiteteKlasse a(11, 10, 2);
    cout << a.sum() << endl;
}
