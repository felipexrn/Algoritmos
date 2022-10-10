#include <stdio.h>

int main() {
  int n, r;
  int o = scanf("%i %i", &n, &r);
  int v1[n];
  int v2[r];

  for (int i = 0; i < n; i++) {  
    v1[i] = i+1;
  }
  
  for (int i = 0; i < r; i++) {
    int m;    
    o = scanf("%i", &m);
    for (int j = 0; j < n; j++) {
      if (v1[j] == m) {
        v1[j] = 0;
      }
    }
  }
  int tamo_vivo = 0;
  for (int i = 0; i < n; i++) {
    tamo_vivo += v1[i];
    if (v1[i] > 0) {
      printf("%i ", v1[i]);
    }
  }
  if (tamo_vivo == 0) {
    printf("*");
  }
  return 0;
}