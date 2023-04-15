#include <stdio.h>
int main() {
  printf("1000000 "); // N
  for(int i = 0; i < 1000000; i++) {
    printf("1000000000 "); // A[i]
  }
  printf("\n");
  return 0;
}

/*
windows:
compila teste
  gcc teste.c -o teste
gera o arquivo de teste:
  .\teste > teste.txt
compila problema: 
  gcc problema.c -o problema
executar o problema lendo o teste
  .\problema < teste.txt

linux:
compila teste
  gcc teste.c -o teste
gera o arquivo de teste:
  ./teste > teste.txt
compila problema: 
  gcc problema.c -o problema
executar o problema lendo o teste
  ./problema < teste.txt
*/