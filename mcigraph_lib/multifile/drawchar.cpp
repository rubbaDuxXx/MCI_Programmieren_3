#include "drawchar.hpp"

void drawchar(int x, int y) {
  // Setze einen Charakter in die Mitte
  draw_image("character.bmp", x * 16, y * 16);
}
