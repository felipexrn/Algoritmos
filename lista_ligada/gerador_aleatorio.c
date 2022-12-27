// este programa gera n números de 0 a m-1
// compile na pasta do arquivo com o comando: gcc gerador.c -o gerador
// execute o programa com o comando: ./gerador > entrada.txt
// dessa forma o programa gera uma entrada de números para ser usada posteriormente.

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#include <stdio.h>

int main() {  
  int i, n, m;
  scanf("%d %d", &n, &m);
  printf("%d\n", n);
  
  srand(time(NULL));
  for (i=0; i < n; i++)
  {
    printf("%d\n", rand() % m);
  }
  return 0;
}