#include "mcigraph.hpp"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int cx = 32, cy = 24; // aktuelle Position der Spielfigur

  while (running()) {
    for (int x = 0; x < 1024; x += 16) // Fülle das ganze Fenster mit Gras
      for (int y = 0; y < 768; y += 16)
        draw_image("grass.bmp", x, y);

    // Bewege Figur je nach Tastendrücken
    if (is_pressed(KEY_LEFT)) cx--;
    if (is_pressed(KEY_RIGHT)) cx++;
    if (is_pressed(KEY_UP)) cy--;
    if (is_pressed(KEY_DOWN)) cy++;

    draw_image("character.bmp", cx * 16, cy * 16); // Setze die Spielfigur
    present();
  }
  return 0;
}
