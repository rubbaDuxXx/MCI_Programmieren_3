#include <stdio.h>
#include <stdlib.h>

typedef struct Point2D{
    double x,y;  
} Point2D;

// Definieren sie hier ihre zeropoint-Funktion:
Point2D *zeropoint(){
    Point2D *p = malloc(sizeof(Point2D));
    p->x = 0;
    p->y = 0;
    return p;
}

int main()
{
    Point2D *p = zeropoint();
    printf("%f %f\n", p->x, p->y);
    free(p);
    p=NULL;
}
