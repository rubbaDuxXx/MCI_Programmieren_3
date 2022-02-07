#include <iostream>
#include "prime.hpp"
using namespace std;

int main() {
  for (int i = 2; i < 100; i++) {
    if (is_prime(i)) {
      cout << i << " ist eine Primzahl" << endl;
    }
  }
}
