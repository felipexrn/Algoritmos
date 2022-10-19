#include <stdio.h>

void imprime_lista(int lista[], int t) {
  for (int i = 0; i < t; i++) {
    printf("%d", lista[i]);
    if (i < t - 1) {
      printf(" ");
    }
  }
  printf("\n");
}

int acha_vaga(int lista[], int t, int vaga) {
  int contador = 0;
  for (int i = 0; i < t; i++) {
    if (lista[i] == 0) {
      contador++;
    }
    if (i >= contador) {
      contador = 0;
    }
    if (contador == vaga) {
      vaga += i;
      break;
    }
  }
  return vaga - contador;
}

void ocupa_vaga() {
  
}

int main() {
  int c, n, tarifa, faturamento, ocupado;
  
  while (scanf("%d %d", &c, &n) != EOF) {
    tarifa = 10;
    faturamento = 0;
    ocupado = 0;
    int estacionamento[c];
    
    for (int i = 0; i < c; i++) { // cria estacionamento com tamanho C (1 ≤ C ≤ 1000)
      estacionamento[i] = 0;
    }

    acha_vaga(estacionamento, c, 5);
    
    for (int i = 0; i < n; i++) { // percorre N eventos (1 ≤ N ≤ 10000) 
      char e;
      int p, q;
      scanf("%c %d %d", &e, &p, &q); // Lê evento, placa P e tamanho do carro Q. (1000 ≤ P ≤ 9999) e (1 ≤ Q ≤ 1000)
      if (e == 'C') {                // evento de entrada de carro 'C'
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
      } else { // evento de saída de carro 'S'
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
    imprime_lista(estacionamento, c);
    printf("%d\n", faturamento);
  }
  return 0;
}
