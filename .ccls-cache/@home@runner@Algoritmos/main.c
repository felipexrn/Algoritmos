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
long get_max(long lista[], long t) {
  long maior = 0;
  for (int i = 0; i < t; i++) {
    if(lista[i] > maior) {
      maior = lista[i];
    }
  }
  return maior;
}
long get_index(long lista[], long t, long valor) {
  long indice = 0;
  for (int i = 0; i < t; i++) {
    if(lista[i] == valor) {
      indice = i;
      break;
    }
  }
  return indice;
}
void somar(long lista[], long t, long somas[], long x) {
  long soma = 0, i = 0, fatores = 0;
  while(fatores < 5) {
    long maior = get_max(lista, t);
    long indice = get_index(lista, t, maior);
    for (long j = 0; j < t; j++) {
      
      
    }
    if (soma + maior <= x) {
      soma += maior;
      somas[fatores] = indice+1;
      fatores++;
    }
    else lista[indice] = 0;
    i++;
    if (i >= t / 5) break;
    if (fatores == 5) break;
  }
  printf("soma %ld\n", soma);
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
  long t = 100, x = 18, numeros[t], somas[t]; 
  zerar(numeros, t);
  zerar(somas, t);
  numerar(numeros, t / 5);
  imprimir(numeros, t / 5);
  somar(numeros, t / 5, somas, x);
  imprimir(somas, t / 5);
  imprimir(numeros, t / 5);
  return 0;
}