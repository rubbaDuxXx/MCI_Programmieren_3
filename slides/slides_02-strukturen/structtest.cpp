#include <iostream>
using namespace std;

struct Point {
  int x;
  int y;
};

void print(Point p) { cout << "x=" << p.x << ", y=" << p.y << endl; }

Point addpoints(Point p1, Point p2) {
  Point res = {p1.x + p2.x, p1.y + p2.y};
  return res;
}

int main() {
  Point p = {2, 3};
  print(p);
  // Direkte Angabe eines Werts ist auch möglich!
  print(addpoints(p, Point{1, 2}));
}
