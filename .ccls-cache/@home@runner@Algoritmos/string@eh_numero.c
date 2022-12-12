// verifica se string de até 10000 carateres é número.
#include <stdio.h>
#include <string.h>
int main() {
  char texto[10000];
  scanf(" %[^\n]s", texto);
  char not_num[] = "não eh numero";
char eh_num[] = "eh numero";
  int i = 0;
  int numero = 1;
  while(texto[i] != 0) {
    if (texto[i] < 48 || texto[i] > 57) {
      numero = 0;
      break;
    }
    i++;
  }
  numero? printf("%s", eh_num): printf("%s", not_num);
  return 0;
}
