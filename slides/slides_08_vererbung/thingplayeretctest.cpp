#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Thing {
private:
  int _xpos, _ypos;
  string _image;

public:
  Thing(int xpos, int ypos, string image) {
    _xpos = xpos;
    _ypos = ypos;
    _image = image;
  }

  int get_xpos() { return _xpos; }
  int get_ypos() { return _ypos; }
  void set_xpos(int x) { _xpos = x; }
  void set_ypos(int y) { _ypos = y; }

  void draw() {
    cout << "Draw " << _image << " at " << _xpos << " " << _ypos << endl;
  }
};

class Player : public Thing {
private:
  int _health;

public:
  Player(int xpos, int ypos, int health, string image)
      : Thing(xpos, ypos, image) {
    _health = health;
  }

  void move_up() { set_ypos(get_ypos() - 1); }
  void move_down() { set_ypos(get_ypos() + 1); }
  void move_left() { set_xpos(get_xpos() - 1); }
  void move_right() { set_xpos(get_xpos() - 1); }

  void draw() { // Erweitere draw Funktion von Thing
    Thing::draw();
    cout << "Player Life : " << _health << endl;
  }
};

class Shopkeep : public Thing {
private:
  vector<string> _inventory;

public:
  Shopkeep(int xpos, int ypos, string image, vector<string> inventory)
      : Thing(xpos, ypos, image) {
    _inventory = inventory;
  }

  vector<string> get_inventory() { return _inventory; }
};

class Object : public Thing {
private:
  bool _solid;

public:
  Object(int xpos, int ypos, string image, bool solid)
      : Thing(xpos, ypos, image) {
    _solid = solid;
  }

  bool issolid() { return _solid; }
};

int main() {
    Player p(23, 34, 200, "player.bmp");
    p.draw();
}
