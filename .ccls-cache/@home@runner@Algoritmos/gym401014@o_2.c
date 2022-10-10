#include <stdio.h>

void solve() {
  int nOvelhas = 0;
  scanf("%d", &nOvelhas); // Le o numero de carneiros
  int ovelhas[nOvelhas];
  for (int i = 0; i < nOvelhas; i++) // Le os carneiros do caso de teste
    scanf("%d", &ovelhas[i]);

  int count = 0;
  for (int i = 0; i < nOvelhas; i++) {
    for (int j = 0; j < nOvelhas; j++) {
      if (i != j && ovelhas[i] == ovelhas[j]) {
        ovelhas[j] = -1;
      }
    }
  }

  int n = 0;
  for (int j = 0; j < nOvelhas; j++) {
    if (ovelhas[j] > -1)
      n++;
  }
  printf("%d\n", n);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}