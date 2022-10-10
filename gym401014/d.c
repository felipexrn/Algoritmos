#include <stdio.h>

int main() {
  int a, b, c, d;
  scanf("%i", &a);
  scanf("%i", &b);
  c = b - a;
  d = c % 60; // segundos
  c = c / 60; // minutos
  printf("%.2d:%i", c, d);
  return 0;
}