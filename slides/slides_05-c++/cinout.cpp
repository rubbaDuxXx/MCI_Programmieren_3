#include <iostream>
#include <string>

int main() {
  std::string vorname;
  std::cout << "Vorname: ";
  std::cin >> vorname;
  std::string nachname;
  std::cout << "Nachname: ";
  std::cin >> nachname;
  int wiederholungen;
  std::cout << "Wiederholungen: ";
  std::cin >> wiederholungen;

  for (int i = 0; i < wiederholungen; i++) {
    std::cout << "Hallo " << vorname << " " << nachname << std::endl;
  }
}
