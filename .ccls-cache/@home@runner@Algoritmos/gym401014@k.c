#include <stdio.h>

int main() {
  int x1, y1, x2, y2, fim;
  fim = 1;
  while (fim == 1) {
    scanf("%i", &x1);
    scanf("%i", &y1);
    scanf("%i", &x2);
    scanf("%i", &y2);
    if (x1 + y1 + x2 + y2 == 0) {
      break;
    }
    if (x1 == x2 && y1 == y2) {
      printf("%i", 0);
    }
    else if ((x1 - x2) % 2 == 0 && (y1 - y2) % 2 == 0) {
      printf("%i", 1);
    }
    else if ((x1 - x2) % 2 != 0 && (y1 - y2) % 2 != 0) {
      printf("%i", 1);
    } else {
      printf("%i", 2);
    }
  }
  scanf("");
  return 0;
}