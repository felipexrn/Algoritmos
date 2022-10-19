#include <stdio.h>

void imprime(int lista[], int t) {
  for (int i = 0; i < t; i++) {
    printf("%d", lista[i]);
    if (i < t - 1) {
      printf(" ");
    }
  }
  printf("\n");
}

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
      scanf("%c %d %d", &e, &p, &q); // Lê evento, placa e tamanho do carro
      if (e == 'C') {                // evento de entrada de carro
        if (ocupado + q <= c) { // verifica se tem espaço livre no estacionamento  para o carro
          int temVaga = 1;
          int vaga = q;
          for (int j = 0; j < c; j++) { // verifica espaço por espaço do estacionamento
            for (int k = vaga + j ; k > j; k--) { // procura por um espaço livre igual ao carro
              if (estacionamento[k] > 0) {
                temVaga = 0;
                break;
              }
              vaga = j;
            }
            if (temVaga == 1) {
              for (int k = vaga; k < vaga + q; k++) {
                estacionamento[k] = p;
              }

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
    imprime(estacionamento, c);
    printf("%d\n", faturamento);
  }
  return 0;
}
