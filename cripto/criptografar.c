#include <stdio.h>

int main() {
   
  char entrada[50];
  scanf(" %[^\n]s", entrada); // entrada
  FILE *arqe = fopen(entrada, "rt");
  
  char saida[50];
  scanf(" %[^\n]s", saida); // saida
  FILE *arqs = fopen(saida, "wt");

  char caracter, chave;
  scanf("%c", &chave); // chave

  int cripto;
  scanf("%d", &cripto); // 1 = criptografa, 0 = descriptografa

  if (cripto) {
    while (fscanf(arqe, "%c", &caracter) != -1) {
      fprintf(arqs, "%c", caracter - chave);
    }
  } else {
    while (fscanf(arqe, "%c", &caracter) != -1) {
      fprintf(arqs, "%c", caracter + chave);
    }
  }
  fclose(arqe);
  fclose(arqs);
  return 0;
}