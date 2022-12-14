#include <stdio.h>
#include <stdlib.h>

int main() {
  int *n;
  int q = 10;
  n = (int*) malloc(sizeof(int) * q);
  n[0] = 10;
  printf("%d", n[0]);
  return 0;
}


