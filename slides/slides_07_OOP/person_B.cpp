#include <iostream>
#include <string>

using namespace std;

class Person {
private:
  int _alter;

public:
  string vorname, nachname, adresse;

  Person() {
    _alter = 0;
    vorname = "nicht gueltig";
    nachname = "nicht gueltig";
    adresse = "nicht gueltig";
  }

  Person(int palter, string pvorname, string pnachname, string padresse) {
    _alter = palter;
    vorname = pvorname;
    nachname = pnachname;
    adresse = padresse;
  }

  void print() {
    cout << "Alter: " << _alter << endl;
    cout << "Vorname: " << vorname << endl;
    cout << "Nachname: " << nachname << endl;
    cout << "Adresse: " << adresse << endl;
  }

  // Getter und Setter
  int get_alter() { return _alter; }
  void set_alter(int alter) { _alter = alter; }

  void geburtstag() { _alter++; }
};

Person read_data() {
  int alter;
  string vorname, nachname, adresse;

  cout << "Alter: ";
  cin >> alter;
  cout << "Vorname: ";
  cin >> vorname;
  cout << "Nachname: ";
  cin >> nachname;
  cout << "Adresse: ";
  cin >> adresse;

  return Person(alter, vorname, nachname, adresse);
}

int main() {
  Person p;
  p.print();
  Person p2(35, "Sebastian", "Stabinger", "Thaur");
  p2.print();
  p2.geburtstag();
  p2.print();
  cout << endl;
  Person p3 = read_data();
  p3.print();
}
