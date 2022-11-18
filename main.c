#include <stdio.h>
#include <time.h>
void resetar(int repetidos[], int t) {
  for(int i = 0; i < t; i++) {
    repetidos[i] = 0;
  }
}
void configurar(int aleatorios[], int t) {
  clock_t tempo;
  for(int i = 0; i < t; i++) {
    tempo = clock();
    aleatorios[i] = 1 + (int) tempo % 10;
  }
}
void contar(int aleatorios[], int repetidos[], int t) {
  for(int i = 1; i <= t; i++) {
    repetidos[aleatorios[i-1]-1] += 1;
  }
}
void mostrar(int repetidos[], int t) {
  for(int i = 0; i < t; i++) {
    if(repetidos[i] > 0) {
      printf("%d apareceu %d vezes\n", i+1, repetidos[i]);
    } 
  }
}
void printar(int array[], int t) {
  for(int i = 0; i < t; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
int main() {
  int t = 10, repetidos[t], aleatorios[t]; 
  resetar(repetidos, t);
  configurar(aleatorios, t);
  contar(aleatorios, repetidos, t);
  mostrar(repetidos, t);
  printar(repetidos, t);
  printar(aleatorios, t);
  return 0;
}