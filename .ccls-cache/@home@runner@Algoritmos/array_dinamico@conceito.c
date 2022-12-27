#include <stdio.h>
#include <stdlib.h>

void listar(int* p, int qtd) {
  for (int i = 0; i < qtd; i++) {
    printf("%d ", p[i]);
  }
  printf("\n");
}

void arraycopy(int* p, int* t, int max) {
  int i;
  for (i = 0; i < max; i++) {
    t[i] = p[i];
  }
}

void add(int* p, int* qtd ,int max, int valor) {
  if(*qtd == max) {
    int *t;
    max += 10;
    t = (int*) malloc(sizeof(int) * max);
    arraycopy(p, t, max-10);
    p = t;
    free(t);
  }

  p[*qtd] = valor;
  *qtd += 1;
}


int main() {
  int *p;
  int max = 10;
  int qtd = 0;
  p = (int*) malloc(sizeof(int) * max);

  add(p, &qtd, max, 1);
  add(p, &qtd, max, 2);
  add(p, &qtd, max, 3335);
  add(p, &qtd, max, 4);
  add(p, &qtd, max, 9);
  add(p, &qtd, max, 10);
  add(p, &qtd, max, -1);
  add(p, &qtd, max, 150);
  add(p, &qtd, max, 14);
  add(p, &qtd, max, 15);
  add(p, &qtd, max, 777);
  
  listar(p, qtd);
  
  

  
  return 0;
}