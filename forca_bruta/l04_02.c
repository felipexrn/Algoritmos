#include <stdio.h>

int f1(int n){
  if (n<=0) return 0;
    return (n&1) + f1(n>>1);
}

int main() {
  int n = 0b100111011001;
  printf("%d\n", f1(n));
  return 0;
}