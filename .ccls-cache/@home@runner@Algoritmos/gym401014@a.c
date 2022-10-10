#include <stdio.h>

int soma(int a, int b){
  int soma = a + b;
  return soma;
}

int main() {
  int a, b, ans;
  scanf("%d", &a);
  scanf("%d", &b);
  ans = soma(a, b);
  printf("%d\n", ans);
  return 0;
}