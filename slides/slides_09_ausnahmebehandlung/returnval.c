#include <stdio.h>
#include <stdlib.h>

int do_something() {
  if (rand() % 5 == 0)
    return -1; // Ein Fehler ist aufgetreten
  else
    return 0; // Alles OK
}

int main() {
  for (int i = 0; i < 10; i++) {
    int returnvalue = do_something();
    if (returnvalue == 0)
      printf("Alles OK\n");
    else if (returnvalue == -1)
      printf("In do_something ist ein Fehler aufgetreten.\n");
  }
}
