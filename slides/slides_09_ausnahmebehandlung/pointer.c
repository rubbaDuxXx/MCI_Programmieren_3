#include <stdio.h>

int sum(int start, int stop, int *error) {
    if (start > stop) {
        *error = -1; // Wir haben ein Problem!
        return 0;
    }
    int sum = 0;
    for (int i = start; i <= stop; i++)
        sum += i;
    *error = 0; // Alles war ok
    return sum;
}

int main() {
    int sumerror = 0;
    int s = sum(10, 20, &sumerror);
    if (sumerror == 0) printf("Summe ist %d\n", s);
    else printf("Fehler beim Berechnen der Summer\n");
    s = sum(30, 10, &sumerror);
    if (sumerror == 0) printf("Summe ist %d\n", s);
    else printf("Fehler beim Berechnen der Summer\n");
}
