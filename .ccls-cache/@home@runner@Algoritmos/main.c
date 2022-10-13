#include <stdio.h>

int main() {
  int c, n, tarifa, faturamento, ocupado, t = 10;
  int estacionamento[t];

  while (scanf("%d %d", &c, &n) != EOF) {
    tarifa = 10;
    faturamento = 0;
    ocupado = 0;

    for (int i = 0; i < t; i++) {
      estacionamento[i] = 0;
    }

    for (int i = 0; i < n; i++) {
      char e;
      int p, q;
      // e = 'C'; p = 1234; q = 2;
      scanf("%c %d %d", &e, &p, &q); // Lê evento, placa e tamanho do carro
      if (e == 'C') {                // evento de entrada de carro
        if (ocupado + q <=
            c) { // verifica se tem espaço livre no estacionamento  para o carro
          int temVaga = 1;
          int vaga = 0;
          for (int j = 0; j < c;
               j++) { // verifica espaço por espaço do estacionamento
            int zero = 0;
            for (int k = vaga + j; k < q;
                 k++) { // procura por um espaço livre igual ao carro
              if (estacionamento[k] == 0) {
                zero = 0;
              }
              if (estacionamento[k] > 0) {
                temVaga = 0;
                printf("%d", estacionamento[k]);
                vaga = k;
                break;
              }
            }

            if (temVaga == 1 || zero == 0) {
              for (int k = vaga; k < q; k++) {
                estacionamento[k] = p;
              }
              for (int k = 0; k < c; k++) {
                printf("%d ", estacionamento[k]);
              }
              printf("\n");
              ocupado += q;
              faturamento += tarifa;
              break;
            }
          }
        }
      } else { // evento de saída de carro
        for (int j = 0; j < c; j++) {
          if (estacionamento[j] == p) {
            estacionamento[j] = 0;
            if (estacionamento[j] != p) {
              break;
            }
          }
        }
      }
    }
    printf("%d\n", faturamento);
  }
  return 0;
}

/*
clang -g -Wno-everything -pthread -lm -O0 ./main.c -o "main-debug"
  */