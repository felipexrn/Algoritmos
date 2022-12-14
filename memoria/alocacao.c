#include <stdio.h>
#include <stdlib.h>

int main() {
  int *n;
  int q = 10;
  n = (int*) malloc(sizeof(int) * q);
  *n = 10;
  printf("%p", &n);
  return 0;
}


