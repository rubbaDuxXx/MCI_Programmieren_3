#include <stdio.h>
#include <stdlib.h>

typedef struct Point2D {
  double x, y;
} Point2D;

// Definieren sie hier ihre filledresize-Funktion:
Point2D *randpoint() {
  Point2D *p = malloc(sizeof(Point2D));
  p->x = rand() % 100000 / 100.0;
  p->y = rand() % 100000 / 100.0;
  return p;
}

int main() {
  double sumx = 0;
  double sumy = 0;
  Point2D *pnt = NULL;
  for (int i = 0; i < 1000; i++) {
    pnt = randpoint();
    sumx += pnt->x;
    sumy += pnt->y;
  }
  printf("Durchschnittliche Koordinate: x=%f, y=%f\n", sumx / 1000,
         sumy / 1000);
}


