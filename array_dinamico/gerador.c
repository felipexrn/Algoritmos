// este programa gera n números de 0 a n
// compile na pasta do arquivo com o comando: gcc gerador.c -o gerador
// execute o programa com o comando: ./gerador > entrada.txt
// dessa forma o programa gera uma entrada de números para ser usada posteriormente.
#include <stdio.h>

int main() {
  int i, n;
  scanf("%d", &n);
  printf("%d\n", n);
  for (i = 0; i < n; i++) {
    printf("%d\n", i);
  }
  return 0;
}