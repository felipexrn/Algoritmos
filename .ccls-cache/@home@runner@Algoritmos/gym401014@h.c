#include <stdio.h>

int main() {
  long int n;
  scanf("%li", &n);
  for (long int i = 1; i < n; i++) {
    if (n % i == 0) {
      printf("%li ", i);
    }
  }
  printf("%li", n);
  return 0;
}