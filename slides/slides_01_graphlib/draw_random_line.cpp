#include "mcigraph.hpp"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  while (running()) {

    // Zeichne 100 zufällige Linien mit zufälliger Farbe
    for (int i = 0; i < 100; i++) {
      int x1 = rand() % 1024;
      int y1 = rand() % 768;
      int x2 = rand() % 1024;
      int y2 = rand() % 768;
      int red = rand() % 256;
      int green = rand() % 256;
      int blue = rand() % 256;

      draw_line(x1, y1, x2, y2, red, green, blue);
    }
    present();
  }

  return 0;
}
