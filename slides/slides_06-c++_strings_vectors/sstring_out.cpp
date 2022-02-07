#include <iostream>
#include <sstream>
using namespace std;

int main() {
  stringstream str_stream;
  str_stream << "Die Antwort ist " << 42 << " !";
  string str = str_stream.str();

  cout << str << endl;
} // Ausgabe: Die Antwort ist 42 !
