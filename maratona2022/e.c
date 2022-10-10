#include <stdio.h>
int main() {
  long long n;
  scanf("%lld", &n);
  long long t = 0;
  long long f[t];
  long long primeiro;
  scanf("%lld", &primeiro);
  f[0] = primeiro;
  t++;
  for (long long i = 1; i < n; i++) {
    long long b;
    scanf("%lld", &b);
    for (long long j = 0; j < t; j++) {
      if (f[j] - b == 1) {
        f[j] = b;
        break;
      } else {
        f[j+1] = b;
        t++;
      }
    }
  }
  printf("%lld", t);
  return 0;
}