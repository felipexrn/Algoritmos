#include <stdio.h>

int main() {
int a = 20;
int *p;
p = &a;
printf("Valor de *p:    %d\n",*p);
printf("Valor de p:     %p\n",p);
  printf("Endereço de p:  %p\n",&p);
*p = 50;
printf("Valor de a:     %d\n",a);
  printf("Endereço de a:  %p\n",&a);
return 0;
}