#include <stdio.h>
int decaimento(int tempo, int massa) {
  for (int i = massa; i > 1; i = i >> 2) {
    tempo+=tempo;
  }
  return tempo;
}
int main() {
  int tempo, massa;
  scanf("%d %d", &tempo, &massa);
  tempo = decaimento(tempo, massa);
  printf("%d", tempo);
  return 0;
}