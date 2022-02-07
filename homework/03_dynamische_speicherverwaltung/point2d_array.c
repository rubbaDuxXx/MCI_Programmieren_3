#include <stdio.h>
#include <stdlib.h>

typedef struct Point2D {
  double x, y;
} Point2D;

// Definieren sie hier ihre filledarray-Funktion:
Point2D *filledarray(int size, double x, double y) {
  size = 10;
  Point2D *arr = malloc(sizeof(Point2D) * size);
  for (int i = 0; i < size; i++) {
    arr[i].x = x;
    arr[i].y = y;
  }
  return arr;
}

int main() {
  Point2D *p = filledarray(1024 * 1024, 23.12, 42.47);
  printf("%f %f\n", p[1024 * 1024 - 1].x, p[1024 * 1024 - 1].y);
  free(p);
  p = NULL;
}
