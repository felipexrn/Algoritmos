#include <stdio.h>
#include <math.h>
void mostra_array(int array[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d", array[i]);
    if (i < n -1) {
      printf(" ");
    }
  }
  printf("\n");
}
void a(int resultados[], int numeros[], int n) {
  for (int i = 0; i < n; i++) {
    resultados[i] = pow(2,numeros[i]) / 8 + 2 * numeros[i];
  }
}
void b(int resultados[], int numeros[], int n) {
  for (int i = 0; i < n; i++) {
    resultados[i] = 10 * numeros[i] + 50;
  }
}
void c(int resultados[], int numeros[], int n) {
  for (int i = 0; i < n; i++) {
    resultados[i] = 10 + 2 * pow(numeros[i], 2) + numeros[i];
  }
}
void d(int resultados[], int numeros[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = numeros[i]; j > 1; j /= 2) {
      resultados[i] = 100 + 20 * j;
    }
  }
}
int main() {
  int n = 10;
  int numeros[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int resultados[n];
  mostra_array(numeros, n);
  a(resultados, numeros, n);
  mostra_array(resultados, n);
  b(numeros, numeros, n);
  mostra_array(resultados, n);
  c(numeros, numeros, n);
  mostra_array(resultados, n);
  d(numeros, numeros, n);
  mostra_array(resultados, n);
  return 0;
}