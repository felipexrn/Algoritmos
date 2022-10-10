#include <stdio.h>

int main() {
  int n, m;
  scanf("%i", &n);
  int vn[n];
  for (int i = 0; i < n; i++) {
    int p;
    scanf("%i", &p);
    vn[i] = p;
  }
  scanf("%i", &m);
  int vm[m];
  for (int i = 0; i < m; i++) {
    int p;
    scanf("%i", &p);
    vm[i] = p;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vn[i] == vm[j]) {
        vn[i] = 0;
        break;
      }
    }
    if (vn[i] > 0) {
      if (i < n -1) {
        printf("%i ", vn[i]);
      } else {
        printf("%i\n", vn[i]);
      }
    }
  }  
  return 0;
}