#include <stdio.h>

long long count_algarism(long long algarism, long long num) {
  long long candidate = num % 10;
  if (num / 10 == 0) return 0;
  if (num / 10 > 0 && candidate == algarism) {
    return count_algarism(algarism, num/10) + 1;
  } else {
    return count_algarism(algarism, num/10) + 0;
  }
}

int main() {
  long long algarism, num;
  scanf("%ld %ld", &algarism, &num);
  long long qtd_algarism = count_algarism(algarism, num);
  printf("%ld\n", qtd_algarism);
  return 0;
}