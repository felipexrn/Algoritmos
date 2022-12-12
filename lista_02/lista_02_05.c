#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
void imprimir(long lista[], long t) {
  for (long i = 0; i < t; i++) {
    printf("%ld", lista[i]);
    if (i < t - 1) {
      printf(" ");
    }
  }
  printf("\n");
}
void maior_soma(long lista[], long t, long x,
                long somas[]) { // créditos para Igor por este algorítmo
  long maior = 0;
  for (long i = 0; i < t; i++) {
    for (long j = 1 + i; j < t; j++) {
      for (long k = 1 + j; k < t; k++) {
        for (long l = 1 + k; l < t; l++) {
          for (long m = 1 + l; m < t; m++) {
            long soma = lista[i] + lista[j] + lista[k] + lista[l] + lista[m];
            if (soma <= x) {
              maior = soma;
              somas[0] = lista[i];
              somas[1] = lista[j];
              somas[2] = lista[k];
              somas[3] = lista[l];
              somas[4] = lista[m];
            }
          }
        }
      }
    }
  }
}
int main() {
  /*
  long t = 11, x = 850, somas[5], numeros[11] = {2321, 321, 24, 291, 19, 301,
  502, 10020, 30201, 2001, 10};
  */

  long t = 37, x = 1500, numeros[t], somas[5];
  zerar(numeros, t);
  numerar(numeros, t);
  // imprimir(numeros, t);
  clock_t inicio, fim;
  inicio = clock();
  maior_soma(numeros, t, x, somas);
  fim = clock();
  double tempo = ((double)(fim - inicio)) / (CLOCKS_PER_SEC / 1000.0);
  printf("(%.4lf ms) ", tempo);
  imprimir(somas, 5);
  return 0;
}
/*
Teste 01:

Entrada:
11 850
2321 321 24 291 19 301 502 10020 30201 2001 10

Saída:
24 291 19 502 10
  */