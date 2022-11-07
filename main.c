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

int acha_vaga(int lista[], int t, int carro) {
  int contador = 0, vaga;
  for (int i = 0; i < t; i++) {
    if (lista[i] == 0) {
      contador++;
    } else contador = 0;                                         
    if (contador == carro) {
      vaga = i - carro + 1;
      break;
    }
  }
  /*
  if (contador < carro) {
      vaga = -1;
    }
  */
  return vaga;
}

void livra_vaga(int lista[], int t, int placa) {
  for (int i = 0; i < t; i++) {
    if (lista[i] == placa) {
      lista[i] = 0;
    }
  }
}

void ocupa_vaga(int lista[], int t, int vaga, int placa, int carro) {
  for (int i = vaga; i < carro + vaga; i++) {
    lista[i] = placa;
  }
}

int main() {
  int c, n, tarifa, faturamento = 0, ocupado;
  int fim = scanf("%d %d", &c, &n);
  while (fim != EOF) { // Lê entrada até terminar documento
    tarifa = 10;
    ocupado = 0;
    faturamento = 0;
    int estacionamento[1000];
    for (int i = 0; i < c; i++) { // cria estacionamento com tamanho C (1 ≤ C ≤ 1000)
      estacionamento[i] = 0;
    } 
    for (int i = 0; i < n; i++) { // percorre N eventos (1 ≤ N ≤ 10000) 
      char e;
      int p, q, vaga;
      scanf("%c %d", &e, &p);
      if (e == 'C') {  // evento de entrada de carro 'C'
        scanf("%d", &q); // Lê evento, placa P e tamanho do carro Q. (1000 ≤ P ≤ 9999) e (1 ≤ Q ≤ 1000)
        if (ocupado + q <= c) { // verifica se tem espaço livre no estacionamento  para o carro 
          vaga = acha_vaga(estacionamento, c, q);
          if (vaga > -1) {
            ocupa_vaga(estacionamento, c, vaga, p, q);
            ocupado += q;
            faturamento += tarifa;
          }
        }
      } else if (e == 'S') { // evento de saída de carro 'S'
        scanf("%d", &p);
        livra_vaga(estacionamento, c, p);
      }
      imprime_lista(estacionamento, c);
      if (i == n -1) printf("%d\n", faturamento);
    }
     
    fim = scanf("%d %d", &c, &n);
  }  
  return 0;
}
