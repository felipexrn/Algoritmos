#include <stdio.h>
#include <time.h>
void resetar(int repetidos[], int t) {
  for(int i = 0; i < t; i++) {
    repetidos[i] = 0;
  }
}
void configurar(int aleatorios[], int t) {
  clock_t inicio, fim;
  inicio = clock();
  for(int i = 0; i < t; i++) {
    fim = clock();
    aleatorios[i] = (int) 1 + (fim - inicio) % 1000000;
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
  int t = 1000000, repetidos[t], aleatorios[t]; 
  resetar(repetidos, t);
  configurar(aleatorios, t);
  contar(aleatorios, repetidos, t);
  mostrar(repetidos, t);
  return 0;
}