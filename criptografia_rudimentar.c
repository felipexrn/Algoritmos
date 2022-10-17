#include <stdio.h>

int print(char lista[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    printf("%c", lista[i]);
  }
  printf("\n");
  return 0;
}

int encriptar(char mensagem[], int tamanho, char encriptada[], char chave) {
  for (int i = 0; i < tamanho; i++) {
    char letra;
    scanf("%c", &letra);
    mensagem[i] = letra;
    encriptada[i] = letra ^ chave;
  }
  return 0;
}

int main() {
  int t;
  char chave;
  scanf("%d %c", &t, &chave);
  char m1[t];
  char m2[t];
  encriptar(m1, t, m2, chave);
  print(m1, t);
  print(m2, t);

}