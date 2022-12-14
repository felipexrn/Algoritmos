#include <stdio.h>
#include <stdlib.h>
#include<time.h>
void ordena_array(int numeros[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (numeros[j] < numeros[j - 1]) {
        int menor = numeros[j];
        numeros[j] =  numeros[j - 1];
        numeros[j - 1] = menor;
      }
    } 
  }
}
void cria_array(int numeros[], int n) {
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    numeros[i] = rand()%10;
  }
}
void mostra_array(int numeros[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d", numeros[i]);
    if (i < n -1) {
      printf(" ");
    }
  }
  printf("\n");
}
int main() {
  clock_t inicio,fim;
  int n;
  scanf("%d", &n);
  int numeros[n];
  cria_array(numeros, n);
  mostra_array(numeros, n);
  inicio = clock();
  ordena_array(numeros, n);
  fim = clock();
  mostra_array(numeros, n);
  double tempo = ((double)(fim-inicio)) / (CLOCKS_PER_SEC/1000);
  printf("entrada %d (%.4lf ms)\n",n, tempo);
  return 0;
}