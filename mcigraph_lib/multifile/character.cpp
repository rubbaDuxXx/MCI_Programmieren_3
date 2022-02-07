#include "../mcigraph.hpp"
#include "drawchar.hpp"
#include <cstdlib>
using namespace std;
int main() {

  int cx = 32, cy = 24;
  
  while (running()) {
    // Fülle das ganze Fenster mit Gras
    for (int x = 0; x < 1024; x += 16) {
      for (int y = 0; y < 768; y += 16) {
        draw_image("grass.bmp", x, y);
      }
    }
    if (is_pressed(KEY_LEFT)) // Bewege Figur je nach Tastendrücken
      cx--;
    if (is_pressed(KEY_RIGHT))
      cx++;
    if (is_pressed(KEY_UP))
      cy--;
    if (is_pressed(KEY_DOWN))
      cy++;

    if (cx < 0)
      cx = 0;
    else if (cx > 63)
      cx = 63;
    if (cy < 0)
      cy = 0;
    else if (cy > 47)
      cy = 47;

    drawchar(cx, cy);

    // Anzeigen des gezeichneten Bilds am Bildschirm
    present();
  }
}
