#include "mcigraph.hpp"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  while (running()) {

    // Zeichne an jeder Koordinate einen Punkt mit zufälliger Farbe
    for (int x = 0; x < 1024; x++) {
      for (int y = 0; y < 768; y++) {
        int red = rand() % 255;
        int green = rand() % 255;
        int blue = rand() % 255;

        draw_point(x, y, red, green, blue);
      }
    }
    present();
  }

  return 0;
}
