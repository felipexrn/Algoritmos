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
    }                                // 1 0 1 0 1
    if (i >= contador) {             // 3 3 3 3 3
      contador = 0;                  // 0 1 0 1 0
    }                                // 0 1 2 3 4
    if (contador == vaga) {
      vaga = i - vaga + 1;
      break;
    }
    if (i == t - 1 && contador < vaga) {
      vaga = -1;
    }
  }
  return vaga;
}

void livra_vaga(int lista[], int t, int vaga, int placa) {
  for (int i = 0; i < t; i++) {
    if (lista[i] == placa) {
      lista[i] = 0;
      if (lista[i] != placa) {
        break;
      }
    }
  }
}

void ocupa_vaga(int lista[], int t, int vaga, int placa) {
  for (int i = vaga; i > 0; i--) {
    lista[vaga -i] = placa;
  }
}

int main() {
  int c, n, tarifa, faturamento, ocupado;
  while (scanf("%d %d", &c, &n) != EOF) { // Lê entrada até terminar documento
    tarifa = 10;
    faturamento = 0;
    ocupado = 0;
    int estacionamento[c];
    for (int i = 0; i < c; i++) { // cria estacionamento com tamanho C (1 ≤ C ≤ 1000)
      estacionamento[i] = 0;
    }
    
    for (int i = 0; i < n; i++) { // percorre N eventos (1 ≤ N ≤ 10000) 
      char e;
      int p, q, vaga;
      scanf("%c", &e);
      
      if (e == 'C') {  // evento de entrada de carro 'C'
        scanf("%d %d", &p, &q); // Lê evento, placa P e tamanho do carro Q. (1000 ≤ P ≤ 9999) e (1 ≤ Q ≤ 1000)         
        if (ocupado + q <= c) { // verifica se tem espaço livre no estacionamento  para o carro 
          int achou_vaga = acha_vaga(estacionamento, c, q);
          if (achou_vaga > -1) {
            ocupa_vaga(estacionamento, c, achou_vaga, p);
            ocupado += q;
            faturamento += tarifa;
          }
        }
      } else { // evento de saída de carro 'S'
        scanf("%d", &p);
        livra_vaga(estacionamento, c, vaga, p);
      }
    }
    imprime_lista(estacionamento, c);
    printf("%d\n", faturamento);
  }
  return 0;
}
