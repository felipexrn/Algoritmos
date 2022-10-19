#include <stdio.h>

int menor(int n1, int n2) {
  int men = n1;
  if (men > n2) {
    men = n2;
  }
  return men;
}

int main(){
  int d[61], e[61];
  int n, t, pares;
  char p;
  while (scanf("%d", &n) != EOF) {
    for (int i = 30; i < 61; i++) {
      d[i] = 0;
      e[i] = 0;
    }

    for (int i = 0; i < n; i++) {
      scanf("%d %c", &t, &p);
      if (p == 'D') {
        d[t] += 1;
      } else if (p == 'E') {
        e[t] += 1;
      }
    }
    pares = 0;
    for (int i = 30; i < 61; i++) {
      if (d[i] > 0 && e[i] > 0) {
        int par = menor(d[i], e[i]);
        pares += par;
      }
    }
    printf("%d\n", pares);
  }
  return 0;
}