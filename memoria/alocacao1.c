#include <stdio.h>
#include <stdlib.h>
int main() {
  int *n;
  int q = 10;
  n = (int*) malloc(sizeof(int) * q);
  n[0] = 10;
  n[1] = 2;
  n[2] = 3;
  n[3] = -1;
  n[4] = 12;
  n[5] = -123;
  n[6] = 15;
  n[7] = 7;
  n[8] = 0;
  n[9] = 4;
  int indice;
  scanf("%d", &indice);
  printf("%d", n[indice]);
  return 0;
}


