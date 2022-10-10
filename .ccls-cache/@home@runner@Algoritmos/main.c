#include <stdio.h>

int main() {
  int c, n, fim;
  do {
    // código
    int tarifa = 10;
    int faturamento = 0;
    int estacionamento[n];
    int tamanhos[n];
    int ocupado = 0;

    int fim = scanf("%d %d", &c, &n);

    for (int i = 0; i < n; i++) {
      estacionamento[i] = 0;
      tamanhos[i] = 0;
    }

    for (int i = 0; i < n; i++) {
      char e;
      int p, q;
      scanf("%c %d %d", &e, &p, &q);
      if (e == 'C') {
        if (ocupado + q <= c) {
          for (int j = 0; j < n; j++) {
            if (estacionamento[j] == 0) {
              estacionamento[j] = p;
              tamanhos[j] = q;
              ocupado += q;
              faturamento += tarifa;
              printf("Ping\n");
              break;
            }
          }
        }
      } else {
        for (int j = 0; j < n; j++) {
          if (estacionamento[j] == p) {
            estacionamento[j] = 0;
            ocupado -= tamanhos[j];
            tamanhos[j] = 0;
            break;
          }
        }
      }
    }
    printf("%d\n", faturamento);
  } while (fim != EOF);

  return 0;
}
/*
20 10
C 1234 20
C 5678 1
S 1234
C 1234 20
C 5678 1
S 1234
C 5678 1
C 1234 20
C 5555 1
S 5678
*/