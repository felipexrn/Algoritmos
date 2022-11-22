#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void zerar(long lista[], long t) {
  for (long i = 0; i < t; i++) {
    lista[i] = 0;
  }
}
void numerar(long lista[], long t) {
  srand(time(NULL));
  for (long i = 0; i < t; i++) {
    long numero = rand() % t;
    lista[i] = numero + 1;
  }
}
long * maior(long lista[], long t) {
  static long retorno[] = {0, 0};
  for (int i = 0; i < t; i++) {
    if(lista[i] > retorno[0]) {
      retorno[0] = lista[i];
      retorno[1] = i;
    }
  }
  return retorno;
}
void somar(long lista[], long t, long somas[], long x) {
  long soma = 0, i = 0, fatores = 0;
  while(soma < x) {
    if(soma + lista[i] <= x) {
      soma += lista[i];
      somas[fatores] = lista[i];
      fatores++;
    }
    i++;
    if (i >= t / 5) break;
  }
}
void imprimir(long lista[], long t) {
  for (long i = 0; i < t; i++) {
    printf("%ld", lista[i]);
    if (i < t - 1) {
      printf(" ");
    }
  }
  printf("\n");
}
int main() {
  long t = 100, x = 15, numeros[t], somas[t]; 
  zerar(numeros, t);
  zerar(somas, t);
  numerar(numeros, t / 5);
  imprimir(numeros, t);
  somar(numeros, t, somas, x);
  imprimir(somas, t);
  return 0;
}