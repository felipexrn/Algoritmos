#include <stdio.h>
#include <time.h>
int eh_primo(long numero, long divisor) {
  int resposta = 1;
  while(divisor < numero) {
    if (numero % divisor == 0) {
      resposta = 0;
      break;
      }
    divisor++;
  }
  return resposta;
}
void print(int resposta, long n, clock_t inicio, clock_t fim) {
  if (resposta) printf("%ld eh primo", n);
  else printf("%ld nao eh primo", n);
  double tempo = ((double)(fim-inicio)) / (CLOCKS_PER_SEC/1000.0);
  printf(" (%.4lf ms)\n",tempo);
}
int main() {
  clock_t inicio,fim;
  long n, d = 2;
  while(scanf("%ld", &n) > 0) {
    inicio = clock();
    int resposta = eh_primo(n, d);
    fim = clock();
    print(resposta, n, inicio, fim);
    d = 2;
  }
  return 0;
}