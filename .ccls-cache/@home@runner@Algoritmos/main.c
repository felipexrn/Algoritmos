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

    for (int i = 0; i < c; i++) {
      estacionamento[i] = 0;
    }

    for (int i = 0; i < n; i++) {
      char e;
      int p, q;
      scanf("%c %d %d", &e, &p, &q); // Lê evento, placa e tamanho do carro
      if (e == 'C') { // evento de entrada de carro
        if (ocupado + q <= c) { // verifica se tem espaço livre no estacionamento  para o carro
          for (int j = 0; j < c; j++) {
            
            int temVaga = 1;
            int vaga = 0;
            
            for (int k = vaga; k < q; k++) {
              if (estacionamento[k] > 0) {
                temVaga = 0;
                printf("%d", estacionamento[k]);
                vaga = k;
                break;
              }
            }
            
            if (temVaga == 1) {
              for (int k = vaga; k < q; k++) {
                estacionamento[k] = p;
              }
              ocupado += q;
              faturamento += tarifa;
              break;
            }

            for (int k = 0; k < c; k++) {
              printf("%d ", estacionamento[k]);
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

