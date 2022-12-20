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
  printf("%d\n\n", p1.idade);

  struct pessoa amigos[3];
  char n0[] = "Gabriel";
  strcpy(amigos[0].nome, n0);
  amigos[0].altura = 1.83;
  amigos[0].idade = 35;

  char n1[] = "Cinara";
  strcpy(amigos[1].nome, n1);
  amigos[1].altura = 1.77;
  amigos[1].idade = 33;

  char n2[] = "Guaxa";
  strcpy(amigos[2].nome, n2);
  amigos[2].altura = 1.9;
  amigos[2].idade = 45;

  for (int i = 0; i < 3; i++) {
    printf("%s\n", amigos[i].nome);
    printf("%.2f\n", amigos[i].altura);
    printf("%d\n\n", amigos[i].idade);
  }
  
  return 0;
}
 