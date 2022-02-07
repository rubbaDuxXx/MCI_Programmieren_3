#include "mcigraph.hpp"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int c1x = 32, c1y = 24; // aktuelle Position der Spielfigur 1
  int c2x = 16, c2y = 16; // aktuelle Position der Spielfigur 2

  while (running()) {
    for (int x = 0; x < 1024; x += 16) // Fülle das ganze Fenster mit Gras
      for (int y = 0; y < 768; y += 16)
        draw_image("grass.bmp", x, y);

    // Bewege Figur je nach Tastendrücken
    if (is_pressed(KEY_LEFT)) c1x--;
    if(c1x == c2x && c1y == c2y) c1x++;
    if (is_pressed(KEY_RIGHT)) c1x++;
    if(c1x == c2x && c1y == c2y) c1x--;
    if (is_pressed(KEY_UP)) c1y--;
    if(c1x == c2x && c1y == c2y) c1y++;
    if (is_pressed(KEY_DOWN)) c1y++;
    if(c1x == c2x && c1y == c2y) c1y--;
    if (is_pressed(KEY_A)) c2x--;
    if(c1x == c2x && c1y == c2y) c2x++;
    if (is_pressed(KEY_D)) c2x++;
    if(c1x == c2x && c1y == c2y) c2x--;
    if (is_pressed(KEY_W)) c2y--;
    if(c1x == c2x && c1y == c2y) c2y++;
    if (is_pressed(KEY_S)) c2y++;
    if(c1x == c2x && c1y == c2y) c2y--;

    draw_image("character.bmp", c1x * 16, c1y * 16); // Setze die Spielfigur 1
    draw_image("char2.bmp", c2x * 16, c2y * 16); // Setze die Spielfigur 2
    present();
  }
  return 0;
}
