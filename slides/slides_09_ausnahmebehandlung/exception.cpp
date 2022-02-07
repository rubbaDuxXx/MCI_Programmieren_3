#include <exception>
#include <iostream>
using namespace std;

void do_something() {
  if (rand() % 5 == 0)
    throw runtime_error("We got a 0, and we don't like it!");
}

int main() {
  for (int i = 0; i < 10; i++) {
    try {
      do_something();
      cout << "Alles OK!" << endl;
    } catch (exception &e) {
      cout << "Some error occured with the message: " << endl;
      cout << e.what() << endl;
    }
  }
}
