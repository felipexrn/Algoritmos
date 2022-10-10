#include <stdio.h>

int main(){
  int d[31], e[31];
  while (1) {
    for (int i = 0; i < 31; i++) {
      d[i] = 0;
      e[i] = 0;
    }
    int n;
    scanf("%d", &n);
    char m[n];
    for (int i = 0; i < n; i++) {
      int t;
      char p;
      scanf("%d %c", &t, &p);
      if (p == 'D') {
        d[t-30] += 1;
      } else if (p == 'E') {
        e[t-30] += 1;
      }
    }
    int pares = 0;
    for (int i = 0; i < 31; i++) {
      if ((d[i] + e[i]) / 2 > 0 && d[i] > 0 && e[i] > 0) {
        pares += (d[i] + e[i]) / 2;
      }
    }
    printf("%d\n", pares);
  }
  return 0;
}