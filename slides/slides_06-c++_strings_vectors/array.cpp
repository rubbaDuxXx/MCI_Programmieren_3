#include <iostream>
#include <array>
using namespace std;

void output_array(array<int, 10> arr) {
  for (auto e : arr)
    cout << e << " ";
  cout << endl;
}

int main() {
  array<int, 10> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  output_array(a);
}
