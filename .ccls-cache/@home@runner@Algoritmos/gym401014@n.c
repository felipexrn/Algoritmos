#include <stdio.h>

int decompor(long int n1, long int n2) {
  int igual = 1;
  while (igual == 1 && n2 != 0) {
    if (n1 % 2 == n2 % 2 && n1 > 0) {
      n1 = n1 / 10;
      n2 = n2 / 10;
    } else {
      igual = 0;
    }
  }
  return igual;
}

int main() {
  long int a, b;
  scanf("%li", &a);
  scanf("%li", &b);
  if (decompor(a, b) == 1) {
    printf("encaixa");
  } else {
    printf("nao encaixa");
  }
  return 0;
}