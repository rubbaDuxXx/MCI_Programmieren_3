#include "mcigraph.hpp"

int main(int argc, char *argv[]) {
  while (running()) {
    draw_rect(200, 300, 200, 100);
    present();
  }

  return 0;
}
