#include <cmath>
#include <exception>
#include <iostream>
using namespace std;

struct Point2D {
  double x, y;
};

// Definieren sie hier ihre dist-Funktion:
double dist(Point2D p1, Point2D p2) {
  if (p1.x == p2.x && p1.y == p2.y)
    throw domain_error("Points a and b are identical!");
  double dx = p2.x - p1.x;
  double dy = p2.y - p1.y;
  return sqrt(dx * dx + dy * dy);
}

int main() {
  Point2D p1 = {3.5, 2.3};
  Point2D p2 = {7.42, 23.47};
  cout << dist(p1, p2) << endl;
  try {
    cout << dist(p1, p1) << endl;
  } catch (domain_error &e) {
      cout << "Fehler abgefangen!" << endl;
  }
}
