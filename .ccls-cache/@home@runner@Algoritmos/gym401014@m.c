#include <stdio.h>
 
int main() {
  int t, anos;
  double g1, g2;
  long long pa, pb;
  scanf("%i", &t);
  for (int i = 0; i < t; i++) {
    scanf("%lld", &pa);
    scanf("%lld", &pb);
    scanf("%lf", &g1);
    scanf("%lf", &g2);
    for (int j = 0; j < 102; j++) {
      anos = j;
      if (pa > pb) {
        break;
      } else {
        pa += (long long) pa * g1 / 100;
        pb += (long long) pb * g2 / 100;
      }
    }
    if (anos > 100) {
      printf("Mais de 1 seculo.\n");
    } else {
      printf("%i anos.\n", anos);
    }
  }
  return 0;
}