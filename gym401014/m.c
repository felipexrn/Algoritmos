#include <stdio.h>
 
long long convInt(double decimal) {
  long long inteiro = decimal;
  return inteiro;
}
 
int main() {
  int t, anos;
  double pa, pb, g1, g2;
  scanf("%i", &t);
  for (int i = 0; i < t; i++) {
    scanf("%lf", &pa);
    scanf("%lf", &pb);
    scanf("%lf", &g1);
    scanf("%lf", &g2);
    for (int j = 0; j < 102; j++) {
      anos = j;
      if (pa > pb) {
        break;
      } else {
        pa = convInt(pa * g1 / 100 + pa);
        pb = convInt(pb * g2 / 100 + pb);
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