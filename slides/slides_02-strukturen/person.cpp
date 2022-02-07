#include <iostream>
#include <string>

using namespace std;

class person {
private:
  int _alter;

public:
  string vorname, nachname, adresse;

  person() {
    _alter = 0;
    vorname = "nicht gueltig";
    nachname = "nicht gueltig";
    adresse = "nicht gueltig";
  }

  person(int palter, string pvorname = "nicht gueltig",
         string pnachname = "nicht gueltig", string padresse = "nicht gueltig") {
    _alter = palter;
    vorname = pvorname;
    nachname = pnachname;
    adresse = padresse;
  }

  int get_alter() { return _alter; }

  void print() {
    cout << "Vorname: " << vorname << endl;
    cout << "Nachname: " << nachname << endl;
    cout << "Adresse: " << adresse << endl;
    cout << "Alter: " << _alter << endl;
  }

  void geburtstag() { _alter++; }
};

person daten_eingabe() {
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
  person tmp(alter, vorname, nachname, adresse);
  return tmp;
}

int main() {
  person p1;
  person p2(35, "Sebastian", "Stabinger");
  p1.print();
  cout << endl;
  p2.print();
  p2.geburtstag();
  p2.print();
  p2.vorname = "Alexander";
  p2.print();
  cout << p2.get_alter();
  person p3 = daten_eingabe();
  p3.print();
}
