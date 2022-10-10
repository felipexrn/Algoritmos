#include <stdio.h>

int primo(long int num) {
  int primo = 1;
  for (long int i = 2; i < num; i++) {
    if (num % i == 0) {
      primo = 0;
      break;
    }
  }
  return primo;
}

int main() {
  long int n;
  scanf("%li", &n);
  if (primo(n) == 1 && n != 1) {
    printf("Sim");
  } else {
    printf("Nao");
  }
  return 0;
}