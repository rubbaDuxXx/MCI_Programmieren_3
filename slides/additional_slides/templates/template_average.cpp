#include <iostream>
using namespace std;

template <typename Sum, typename Count> class average {
private:
  Sum _sum = 0;
  Count _count = 0;

public:
  void add(Sum val) { _sum += val; _count++; }

  Sum avg() { if (_count == 0) return 0; else return _sum / _count; }
};

int main() {
  average<float, int> a;
  cout << "a " << a.avg() << endl;
  a.add(23);
  a.add(27);
  cout << "a " << a.avg() << endl;
}
