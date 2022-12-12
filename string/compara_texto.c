// compara duas strings ignorando 
#include <stdio.h>
int main() {
  char texto1[100];
  char texto2[100];
  scanf(" %[^\n]s", texto1);
  scanf(" %[^\n]s", texto2);
  int i = 0;
  char dif[] = "Não são iguais";
  char igu[] = "São iguais";
  int iguais = 1;
  while(texto1[i++] != 0) {
    if (texto1[i] != texto2[i] &&
      texto1[i] - texto2[i] != 32 &&
      texto1[i] - texto2[i] != -32) {
      iguais = 0;
      break;
    }
  }
  if (iguais) printf("%s\n", igu);
  else printf("%s\n", dif);
  return 0;
}