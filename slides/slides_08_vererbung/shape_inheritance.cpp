#include <iostream>
using namespace std;

class Shape {
private:
  double _width, _height, _xpos, _ypos;

public:
  Shape(double width, double height, double xpos, double ypos) {
    _width = width;
    _height = height;
    _xpos = xpos;
    _ypos = ypos;
  }

  void set_width(double width) { _width = width; }
  void set_height(double height) { _height = height; }
  void set_xpos(double xpos) { _xpos = xpos; }
  void set_ypos(double ypos) { _ypos = ypos; }
  double get_width() { return _width; }
  double get_height() { return _height; }
  double get_xpos() { return _xpos; }
  double get_ypos() { return _ypos; }

  double get_area() { return 0.0; }
};

class Rectangle : public Shape {
public:
  Rectangle(double width, double height, double xpos, double ypos)
      : Shape(width, height, xpos, ypos){}

  double get_area() { return get_width() * get_height(); }
};

class IsoscelesTriangle : public Shape {
public:
  IsoscelesTriangle(double width, double height, double xpos, double ypos)
      : Shape(width, height, xpos, ypos){}

  double get_area() { return (get_width() * get_height()) / 2; }
};

class Square : public Rectangle {
public:
  Square(double size, double xpos, double ypos)
      : Rectangle(size, size, xpos, ypos){};
};

int main() {
  Shape s(10, 10, 200, 200);
  cout << "Shape Area = " << s.get_area() << endl;
  Rectangle r(10, 10, 200, 200);
  cout << "Rectangle Area = " << r.get_area() << endl;
  IsoscelesTriangle t(10, 10, 200, 200);
  cout << "Isosceles Triangle Area = " << t.get_area() << endl;
  Square sq(10, 200, 200);
  cout << "Square Area = " << sq.get_area() << endl;
}
