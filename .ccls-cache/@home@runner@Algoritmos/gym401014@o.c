#include <stdio.h>

int contem(int v, int a[], int tamA) {
  for (int i = 0; i < tamA; i++) {
    if (v == a[i])
      return 1;
  }
  return 0;
}

void populaComValor(int a[], int tamA, int valor) {
  for(int i = 0; i < tamA; i++) {
    a[i] = valor;
  }
}

void solve() {

  int nOvelhas = 0;
  scanf("%d", &nOvelhas); // Le o numero de carneiros
  int ovelhas[nOvelhas];
  for (int i = 0; i < nOvelhas; i++) //Le os carneiros do caso de teste
    scanf("%d", &ovelhas[i]);

  int ovelhasContadas[nOvelhas];
  /* for (int i = 0; i < nOvelhas; i++) // Popula o vetor com -1
    ovelhasContadas[i] = -1; */

  populaComValor(ovelhasContadas, nOvelhas, -1);
  
  int count = 0;
  for (int i = 0; i < nOvelhas; i++) {
    if (!contem(ovelhas[i], ovelhasContadas, nOvelhas)) //Se a ovelha nao estiver no vetor, adicione
      ovelhasContadas[count++] = ovelhas[i];
  }


  int n = 0;
  while (n < nOvelhas && ovelhasContadas[++n] != -1); //Conta a quantidade de ovelhas unicas
  printf("%d\n", n);
}


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}

/*
#include <stdio.h>

int main() {
  int t, k, y, qtd, n, i, j;
  scanf("%d", &t); // número de casos de teste T (1 ≤ T ≤ 100)
  for (y = 0; y < t; y++) {
    scanf("%d", &n); // número de carneiros N (1 ≤ N ≤ 10^4)
    int v[n];
      scanf("%d", &v[0]); // Identificadores dos carneiros K (0 ≤ K ≤ 10^9)
    for (k = 1; k < n; k++) {
      int carneiro;
      scanf("%d", &carneiro); // Novo carveiro
      for (i = 0; i < k; i++) {
        if (v[i] != -1) {
          if (v[i] == carneiro) {
            v[i] = -1; // !!!IMPORTANTE!!! retirar carneiro já contador transformando em -1
            qtd++;     // acumulador de carneiros iguais
          } else {
            v[k] = carneiro; // adiciona carneiro somente se for distinto
          }
        }
      }  
    }
    printf("%d\n", n - qtd); // guarda a quantidade de carneiros distintos por caso de teste
    qtd = 0;
  }
  return 0;
}
*/