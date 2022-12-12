#include <stdio.h>
int main() {
  char a[] = "Hello world!\n";
  int i = 0;
  while(a[i] != 0) {
    printf("%c", a[i]);
    i++;
  }
}