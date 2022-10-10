#include <stdio.h>

int main() {
  long int n;
  scanf("%li", &n);
  if (n % 2 == 0) {
    n += 2;
  } else {
    n++;
  }
  printf("%li", n);
  return 0;
}