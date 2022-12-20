#include <stdio.h>
#include <string.h>
struct pessoa {
  char nome[50];
  float altura; 
  int idade;
};

int main() {
  struct pessoa p1;
  char n[] = "Felipe Xavier";
  strcpy(p1.nome, n);
  p1.altura = 1.75;
  p1.idade = 30;
  printf("%s\n", p1.nome);
  printf("%.2f\n", p1.altura);
  printf("%d\n", p1.idade);
  return 0;
}
 