#include <stdio.h>

int main() {
  int c, n, tarifa, faturamento, ocupado;
  int estacionamento[10000];
  int tamanhos[10000];
  while (scanf("%d %d", &c, &n) != EOF) {
    tarifa = 10;
    faturamento = 0;
    ocupado = 0;

    //scanf("%d %d", &c, &n);

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
  }
  return 0;
}

