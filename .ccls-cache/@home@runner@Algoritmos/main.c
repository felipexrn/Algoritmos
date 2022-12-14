#include <stdio.h>
#include <stdlib.h>

int main() {
  int *n, t, i;
  scanf("%d", &t);
  n = (int *)malloc(sizeof(int) * t);
  if (n == NULL) {
    fprintf(stderr, "ERRO ao alocar memória\n");
    exit(1);
  } else {
    fprintf(stderr, "Alocou memória\n");
  }
  for (i = 0; i < t; i++)
    scanf("%d", &n[i]);

  printf("{");
  for (i = 0; i < t; i++) {
    printf("%d", n[i]);
    if(i < t -1) printf(", ");
  }
    
  printf("}\n");

  return 0;
}