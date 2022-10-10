#include <stdio.h>

int main() {
  long int a, b, menor, mdc;
  scanf("%li", &a);
  scanf("%li", &b);
  menor = b;
  if (a - b <= 0) {
    menor = a;
  }
  for (long int i = 1; i <= menor; i++) {
    if (a % i == 0 && b % i == 0) {
      mdc = i;
    }
  }
  printf("%li", mdc);
  return 0;
}