#include <iostream>
#include "mcigraph.hpp"

using namespace std;

const int x_tilecount = 1024 / 16;
const int y_tilecount = 768 / 16;

int main() {
  int x = 10, y = 10;

  // auto background = "../tiles/3_16.bmp";

  ___MCILOOPSTART___
// for (int x = 0; x < x_tilecount; x++) {
//   for (int y = 0; y < y_tilecount; y++) {
//     draw_image(background, x * 16, y * 16);
//   }
// }

//  draw_image("../tiles/char1.bmp", x * 16, y * 16);

#define POINTS_COUNT 4
  // bstatic SDL_Point points[POINTS_COUNT] = {
  // {320, 200}, {300, 240}, {340, 240}, {320, 200}};

  SDL_SetRenderDrawColor(g.ren, 0, 0, 0, SDL_ALPHA_OPAQUE);
  // SDL_RenderDrawLines(g.ren, points, POINTS_COUNT);
  // SDL_RenderDrawLine(g.ren, 0, 0, 100, 100);
  for (int i = 0; i < 768; i += 10) {
    draw_line(0, 0, 1024, i, 50, 234, 50);
    draw_line(1024, 0, 0, i, 50, 50, 234);
  }

  if (is_pressed(KEY_LEFT) || is_pressed(KEY_A))
    if (x > 0)
      x--;
  if (is_pressed(KEY_RIGHT) || is_pressed(KEY_D))
    if (x < x_tilecount - 1)
      x++;
  if (is_pressed(KEY_UP) || is_pressed(KEY_W))
    if (y > 0)
      y--;
  if (is_pressed(KEY_DOWN) || is_pressed(KEY_S))
    if (y < y_tilecount - 1)
      y++;

  ___MCILOOPEND___
}
