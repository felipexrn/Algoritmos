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