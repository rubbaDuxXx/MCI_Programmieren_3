#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> vec;
  cout << "Größe von vec: " << vec.size() << endl;
  vec.push_back(23);
  vec.push_back(13);
  vec.push_back(42);
  vec.push_back(7);
  cout << "Größe von vec: " << vec.size() << endl;
  // For-each 
  for (auto e : vec)
    cout << e << " ";
}
