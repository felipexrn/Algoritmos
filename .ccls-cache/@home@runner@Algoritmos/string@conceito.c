#include <stdio.h>
int main() {
  char nome[100];
  scanf(" %[^\n]s", nome);
  printf("%s", nome);
  return 0;
}