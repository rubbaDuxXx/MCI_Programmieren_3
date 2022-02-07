#include "mcigraph.hpp"

int main(int argc, char *argv[]) {
  while (running()) {
    draw_line(100, 100, 500, 100, 255, 0, 0);
    draw_line(500, 100, 500, 500, 0, 255, 0);
    draw_line(500, 500, 100, 500, 0, 0, 255);
    draw_line(100, 500, 100, 100, 255, 0, 255);
    present();
  }
  return 0;
}
