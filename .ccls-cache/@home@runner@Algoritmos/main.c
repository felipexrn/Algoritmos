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
void somar(long lista[], long t, long somas[], long x) {
  
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
  long t = 1000000, x = 5, numeros[t], somas[t]; 
  zerar(numeros, t);
  zerar(somas, t);
  numerar(numeros, t / 10);
  imprimir(numeros, t);
  somar(numeros, t, somas, x);
  imprimir(somas, t);
  return 0;
}