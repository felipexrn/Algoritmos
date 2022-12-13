#include <stdio.h>
#include <string.h>

int main() {
  char nome[100];
  scanf(" %[^\n]s", nome);
  int i = 1;
  char espaco = ' ';
  if (nome[0] >= 'a' && nome[0]<= 'z') {
      nome[0] -= espaco;
    }
  while(nome[i] != 0) {
    
    if (nome[i-1] != espaco) {
      if (nome[i] >= 'A' && nome[i] <= 'Z') {
        nome[i] += espaco; 
      }
    } else {
      if (nome[i] >= 'a' && nome[i]<= 'z') {
        nome[i] -= espaco;
      }
    }
    i++;
  }
  printf("%s", nome);
  return 0;
}