#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void resetar(int repetidos[], int t) {
  for(int i = 0; i < t; i++) {
    repetidos[i] = 0;
  }
}
void configurar(int aleatorios[], int t) {
  for(int i = 0; i < t; i++) {
    srand(time(NULL));
    aleatorios[i] = rand() / 100000 + 1;
  }
}
void contar(int aleatorios[], int repetidos[], int t) {
  for(int i = 0; i < t; i++) {
    repetidos[aleatorios[i]] += 1;
  }
}
void mostrar(int repetidos[], int t) {
  for(int i = 0; i < t; i++) {
    if(repetidos[i] > 0) {
      printf("%d apareceu %d vezes\n", i, repetidos[i]);
    } 
  }
}
int main() {
  int t = 100000, repetidos[t], aleatorios[t]; 
  resetar(repetidos, t);
  configurar(aleatorios, t);
  contar(aleatorios, repetidos, t);
  mostrar(repetidos, t);
  return 0;
}