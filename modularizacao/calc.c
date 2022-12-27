#include <stdio.h>
#include "modulo.h"

int main() {
  int x, y, op, ans;
  scanf("%d %d %d", &op, &x, &y);
  if if(op==0) return 0;
  else if(op==1) ans = add(x, y);
  else if(op==2) ans = sub(x, y);
  else if(op==3) ans = div(x, y);
  else if(op==4) ans = mul(x, y);
  printf("%d\n", ans);
  return 0;
}