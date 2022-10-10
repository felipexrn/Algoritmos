#include <stdio.h>
int main(){
  int fim = 1;
  while (fim) {
    int n;
    scanf("%d", &n);
    if (n == 0) {
      break;
    } else {
      int h[n + 2];
      int picos = 0;
      for (int i = 0; i < n + 2; i++) {
        int hn;
        if (i < n) {
          scanf("%d", &hn);
          h[i] = hn;
        }
        if (i == n - 1) {
          h[i + 1] = h[0];
          h[i + 2] = h[1];
        }
        if (i > 1) {
          if (h[i - 2] > h[i - 1] && h[i] > h[i - 1] || h[i - 2] < h[i - 1] && h[i] < h[i - 1]) {
            picos += 1;
          }
        }
      }
      printf("%d\n", picos);
    }
  }
  return 0;
}