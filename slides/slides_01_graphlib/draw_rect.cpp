#include "mcigraph.hpp"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  while (running()) {
    // Zeichne 100 zufällige, gefüllte Rechtecke mit zufälliger Farbe
    for (int i = 0; i < 100; i++) {
      int x = rand() % 1024;
      int y = rand() % 768;
      int width = rand() % 1024 - x;
      int height = rand() % 768 - y;
      int red = rand() % 256;
      int green = rand() % 256;
      int blue = rand() % 256;

      draw_rect(x, y, width, height, false, red, green, blue);
    }
    present();
  }

  return 0;
}
