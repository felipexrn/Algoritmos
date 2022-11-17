#include <stdio.h>
unsigned long infeccao(unsigned long populacao) {
  unsigned long dias = 0;
  unsigned long infectados = 1;
  for (unsigned long i = infectados; i < populacao; i = i << 2) {
    dias++;
  }
  return dias;
}
int main() {
  unsigned long populacao;
  scanf("%lu", &populacao);
  printf("%lu", infeccao(populacao));
  return 0;
}