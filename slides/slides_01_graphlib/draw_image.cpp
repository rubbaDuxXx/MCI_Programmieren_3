#include "mcigraph.hpp"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  while (running()) {

    // Fülle das ganze Fenster mit Gras
    for (int x = 0; x < 1024; x += 16) {
      for (int y = 0; y < 768; y += 16) {
        draw_image("grass.bmp", x, y);
      }
    }
    // Setze einen Charakter in die Mitte
    draw_image("character.bmp", 32 * 16, 24 * 16);
    present();
  }

  return 0;
}
