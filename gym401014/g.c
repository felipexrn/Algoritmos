#include <stdio.h>

int main() {
  long long a11, a21, a12, a22, p1, p2, ans;
  scanf("%lli", &a11);
  scanf("%lli", &a21);
  scanf("%lli", &a12);
  scanf("%lli", &a22);
  scanf("%lli", &p1);
  scanf("%lli", &p2);
  long long m1 = (a11 * p1 + a21 * p2) / (p1 + p2);
  long long m2 = (a12 * p1 + a22 * p2) / (p1 + p2);
  if (m1 >= m2) {
    ans = 1;
  } else {
    ans = 2;
  }
  printf("%lli", ans);
  return 0;
}