#include <stdio.h>
double pow(double ba, double po) {
  double resultado = 1;
  for (double i = 0; i < po; i++) {
    resultado *= ba;
  }
  return resultado;
}
void mostra_array(double array[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%.2lf", array[i]);
    if (i < n -1) {
      printf("%c", 9);
    }
  }
  printf("\n");
}
void a(double resultados[], double numeros[], int n) {
  for (int i = 0; i < n; i++) {
    resultados[i] = pow(2, numeros[i]) / 8 + 2 * numeros[i];
  }
}
void b(double resultados[], double numeros[], int n) {
  for (int i = 0; i < n; i++) {
    resultados[i] = 10 * numeros[i] + 50;
  }
}
void c(double resultados[], double numeros[], int n) {
  for (int i = 0; i < n; i++) {
    resultados[i] = 10 + 2 * pow(numeros[i], 2) + numeros[i];
  }
}
void d(double resultados[], double numeros[], int n) {
  for (int i = 0; i < n; i++) {
    int logaritmo = 0;
    for (int j = numeros[i]; j > 1; j /= 2) {
      logaritmo++;
    }
    resultados[i] = 100 + 20 * logaritmo;
  }
}
int main() {
  int n = 10;
  double numeros[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  double resultados[n];
  mostra_array(numeros, n);
  a(resultados, numeros, n);
  mostra_array(resultados, n);
  b(resultados, numeros, n);
  mostra_array(resultados, n);
  c(resultados, numeros, n);
  mostra_array(resultados, n);
  d(resultados, numeros, n);
  mostra_array(resultados, n);
  return 0;
}