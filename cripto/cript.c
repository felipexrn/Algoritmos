#include <stdio.h>

int main() {
  char caracter, chave = 'a';
  while (scanf("%c", &caracter) != -1) {
    printf("%c", caracter - chave);
  }
  return 0;
}