#include <iostream>
#include <string>
using namespace std;

int main() {
  double a = 42.4;
  cout << "a = " << a << endl;
  int b = static_cast<int>(a);
  cout << "b = " << b << endl;

  string t = to_string(b);
  cout << "t = " << t << endl;
}
