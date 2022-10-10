#include <stdio.h>

int main() {
  int h1, m1, h2, m2, fim;
  fim = 1;
  while(fim == 1) {
    scanf("%i", &h1);
    scanf("%i", &m1);
    scanf("%i", &h2);
    scanf("%i", &m2);
    if (h1 + m1 + h2 + m2 == 0) {
      break;
    } else {
      h1 = h1 * 60;
      h2 = h2 * 60;
      int deitar = h1 + m1;
      int levantar = h2 + m2;
      int ans;
      if (deitar <= levantar) {
        ans =  levantar - deitar;
      } else {
        ans = 1440 + levantar- deitar;
      }
      printf("%i\n", ans); 
    }
  }
  return 0;
  }