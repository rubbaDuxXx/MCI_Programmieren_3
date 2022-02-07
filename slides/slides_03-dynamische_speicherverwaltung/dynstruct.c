#include <stdio.h>
#include <stdlib.h>

typedef struct Complex {
  double real, imag;
} Complex;

Complex* 

typedef struct ComplexArray {
  Complex *arr;
  int size;
} ComplexArray;

ComplexArray initcomplexarray(int size) {
    ComplexArray carr;
    carr.arr = malloc(sizeof(Complex) * size);
    carr.size = size;
    return carr;
}

int main() {

}
