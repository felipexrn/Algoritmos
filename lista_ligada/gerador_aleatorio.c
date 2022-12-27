// este programa gera n números de 0 a m-1
// compile na pasta do arquivo com o comando: gcc gerador_aleatorio.c -w -o gerador
// execute o programa com o comando: ./gerador_aleatorio > entrada.txt
// dessa forma o programa gera uma entrada de números para ser usada posteriormente.

#include <stdio.h> // biblioteca de entrada e saída
#include <stdlib.h> // biblioteca de alocacao e de liberacao
#include <time.h> // biblioteca de tempo

int main() {  
  int i, n, m;
  scanf("%d %d", &n, &m); // lê a quantidade e faixa de valores a serem gerados
  printf("%d\n", n); // imprime quantidade de valores
  srand(time(NULL)); // reseta semente para gera números aleatórios
  for (i=0; i < n; i++) {
    printf("%d\n", rand() % m); // imprime número aleatório gerado 
  }
  return 0;
}