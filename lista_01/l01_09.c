#include <stdio.h>
#include <time.h>
int find(int array[], int len_array, int value) {
  int found_value = 0;
  for (int i = 0; i < len_array; i++) {
    if (array[i] == value) {
      found_value = 1;
      break;
    }
  }
  return found_value;
}
int main() {
  clock_t inicio, fim;
  int n = 5;
  int numeros[] = {0, 4, 2, 6, 8};
  printf("%d\n", find(numeros, n, 3));
  return 0;
}