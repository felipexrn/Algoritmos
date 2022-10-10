#include <stdio.h>

int main() {
  double a, b, ans;
  scanf("%lf", &a);
  scanf("%lf", &b);
  ans = (a + b) / 2;
  printf("%.5f", ans);
  return 0;
}