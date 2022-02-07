#include <stdio.h>
#include <stdlib.h>

typedef struct Point2D {
  double x, y;
} Point2D;

// Definieren sie hier ihre diagsum-Funktion:
Point2D diagsum(int rows, int columns, Point2D arr[][columns]) {
  Point2D res = {0.0, 0.0};
  for (int i = 0; i < rows; i++) {
    res.x += arr[i][i].x;
    res.y += arr[i][i].y;
  }
  return res;
}

int main() {
  int rows = 10;
  int columns = 10;
  Point2D arr[rows][columns];
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < columns; c++) {
      arr[r][c].x = c;
      arr[r][c].y = r;
    }
  }

  Point2D dsum = diagsum(rows, columns, arr);
  printf("%f %f\n", dsum.x, dsum.y);
}
