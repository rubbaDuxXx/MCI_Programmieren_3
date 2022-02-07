#include <iostream>
using namespace std;

int main() {
  double d = 12.32;
  cout << "Adresse von d = " << &d << endl;
  double *dp = &d; // Verweist auf Speicheradresse von d
  cout << "Wert von dp = " << dp << endl;
  int *ip = (int *)dp; // Verweist auch auf Speicheradresse von d
  cout << "Wert von ip = " << ip << endl;
  cout << "Wert auf den dp verweist (double an Adresse " << dp << " ) = " << *dp
       << endl;
  cout << "Wert auf den ip verweist (int an Adresse " << ip << " ) = " << *ip
       << endl;
}
