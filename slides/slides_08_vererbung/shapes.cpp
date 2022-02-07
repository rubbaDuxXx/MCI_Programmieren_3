#include <iostream>
using namespace std;

class Rectangle {
private:
  double _width, _height, _xpos, _ypos;

public:
  Rectangle(double width, double height, double xpos, double ypos) {
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

  double get_area() { return _width * _height; }
};

class Square {
private:
  double _width, _height, _xpos, _ypos;

public:
  Square(double size, double xpos, double ypos) {
    _width = size;
    _height = size;
    _xpos = xpos;
    _ypos = ypos;
  }

  void set_size(double size) {
    _width = size;
    _height = size;
  }
  void set_xpos(double xpos) { _xpos = xpos; }
  void set_ypos(double ypos) { _ypos = ypos; }
  double get_width() { return _width; }
  double get_height() { return _height; }
  double get_xpos() { return _xpos; }
  double get_ypos() { return _ypos; }

  double get_area() { return _width * _height; }
};

class IsoscelesTriangle {
private:
  double _width, _height, _xpos, _ypos;

public:
  IsoscelesTriangle(double width, double height, double xpos, double ypos) {
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

  double get_area() { return (_width * _height) / 2; }
};

int main()
{
    Rectangle r(10,10,10,10);
    cout << r.get_area() << endl;
}

