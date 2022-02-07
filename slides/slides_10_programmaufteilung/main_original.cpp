#include <iostream>
using namespace std;

bool is_prime(int number) {
  for (int i = 2; i < number / 2 + 1; i++) {
    if (number % i == 0)
      return false;
  }
  return true;
}

int main() {
  for (int i = 2; i < 100; i++) {
    if (is_prime(i)) {
      cout << i << " ist eine Primzahl" << endl;
    }
  }
}
