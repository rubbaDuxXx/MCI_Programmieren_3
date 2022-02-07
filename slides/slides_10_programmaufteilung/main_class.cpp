#include "average.hpp"
#include <iostream>
using namespace std;

int main() {
  Average avg;
  avg.add(12.3);
  avg.add(11.7);
  avg.add(13.7);
  cout << avg.get_avg() << endl;
}
