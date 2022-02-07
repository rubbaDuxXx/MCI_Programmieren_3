#include <stdio.h>

int sumerror = 0;
int sum(int start, int stop) {
  if (start > stop) {
    sumerror = -1; // Wir haben ein Problem!
    return 0;
  }
  int sum = 0;
  for (int i = start; i <= stop; i++)
    sum += i;
  sumerror = 0; // Alles war ok
  return sum;
}

int main() {
  int s = sum(10, 20);
  if (sumerror == 0) printf("Summe ist %d\n", s);
  else printf("Fehler beim Berechnen der Summer\n");
  s = sum(30, 10);
  if (sumerror == 0) printf("Summe ist %d\n", s);
  else printf("Fehler beim Berechnen der Summer\n");
}
