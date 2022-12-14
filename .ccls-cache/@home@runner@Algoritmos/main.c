#include <stdio.h>
#include <stdlib.h>
int main() {
  int *p;
  int t, i;
  scanf("%d", &t);
  p = (int*) malloc(sizeof(int)*t);
  
  for (i = 0; i < t; i++)
    scanf("%d", &p[i]);

  printf("{");
  for (i = 0; i < t; i++) {
    printf("%d", p[i]);
    if(i < t -1) printf(", ");
  }
  printf("}\n");

  printf("A: %d\n", p[0]);

  free(p);

  printf("B: %d\n", p[0]);
  
  return 0;
}