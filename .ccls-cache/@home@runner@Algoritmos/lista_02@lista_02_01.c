#include <stdio.h>
int main() {
  int a, b, ans = 0;
  scanf("%d %d", &a, &b);
  for(int i = 0; i < a; i++) {
    for(int j = 0; i < b; j++) {
      ans++;
    }
  }
  printf("%d", ans);
  return 0;
}