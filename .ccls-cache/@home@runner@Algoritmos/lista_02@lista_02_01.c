#include <stdio.h>
unsigned long pow(unsigned long numero, unsigned long potencia) {
  unsigned long p = 1;
  for (unsigned long i = 0; i < potencia; i++) {
    p *= numero;
  }
  return p;
}
int main() {
  unsigned long a, b, ans;
  scanf("%llu %llu", &a, &b);
  ans = pow(a, b);
  printf("%llu", ans);
  return 0;
}