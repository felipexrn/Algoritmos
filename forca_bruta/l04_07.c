#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int soma_sublista_bt(int a[], int tam, int soma){
int r;
if (soma == 0) return 1; /* Aceita */
if (soma < 0 || tam == 0) return 0; /* Rejeita */
r = soma_sublista_bt(a, tam - 1, soma - a[tam - 1]);
r = r || soma_sublista_bt(a, tam-1, soma);
return r;
}

int main(){
int n, s, i, casos;
scanf("%d", &casos);
while(casos > 0) {
  scanf("%d %d", &n , &s);
  int a[n];
  for (i=0 ; i<n ; ++i) scanf("%d",&a[i]);
  clock_t inicio, fim;
  inicio = clock();
  int ans = soma_sublista_bt(a, n, s);
  fim = clock();
  double tempo = ((double)(fim - inicio)) / (CLOCKS_PER_SEC / 1000.0);
  printf("N: %d, S: %d, R: %d, (%.4lf ms)\n", n, s, ans, tempo);
  casos--;
}

return 0;
}