#include "mcigraph.hpp"

int mandelbrot(double x0, double y0) {
  double x = 0.0, y = 0.0;
  int i = 0;
  while (x * x + y * y <= 4 && i++ < 32) {
    double xtemp = x * x - y * y + x0;
    y = 2 * x * y + y0;
    x = xtemp;
  }
  return i;
}

int main(int argc, char *argv[]) {
  while (running()) {
    // Calculate Mandelbrot
    for (int y = 0; y < 768; y++)
      for (int x = 0; x < 1024; x++) {
        // Scale pixel coordinates to mandel brot range
        double x0 = x / 1024.0 * 3.5 - 2.5;
        double y0 = y / 768.0 * 2.8 - 1.4;
        // Calculate number of iterations until divergence
        int col = mandelbrot(x0, y0);
        draw_point(x, y, col * 8, col * 8, col * 8);
      }
    present();
  }
  return 0;
}

// Compile (Linux and MacOS):
// g++ -std=c++11 -lpthread mandelbrot.cpp -I/usr/include/SDL2 -D_REENTRANT -L/usr/lib -pthread -lSDL2
