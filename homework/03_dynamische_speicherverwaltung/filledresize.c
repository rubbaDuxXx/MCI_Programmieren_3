#include <stdio.h>
#include <stdlib.h>

typedef struct Point2D {
  double x, y;
} Point2D;

// Definieren sie hier ihre filledresize-Funktion:
Point2D *filledresize(Point2D *arr, int size, int newsize, double x, double y) {
  arr = realloc(arr, sizeof(Point2D) * newsize);
  for (int i = size; i < newsize; i++) {
    arr[i].x = x;
    arr[i].y = y;
  }
  return arr;
}

int main() {
  Point2D *arr = malloc(sizeof(Point2D) * 1024);
  arr[1023].x = 42;
  arr[1023].y = 23;
  arr = filledresize(arr, 1024, 1024 * 1024, 12.4, 13.6);
  printf("%f %f %f %f %f %f\n", arr[1023].x, arr[1023].y, arr[1024].x,
         arr[1024].y, arr[1024 * 1024 - 1].x, arr[1024 * 1024 - 1].y);
  free(arr);
  arr = NULL;
}
