#include <stdio.h>
int main(){
  int n;
  double s = 0;
  scanf("%d", &n);
  int d = 0, k = 0;
  int a[n];
  for(int c = 0; c < n; c++){
       scanf("%llu", &a[c]);
       s += a[c];
  }
  s = s/n;
  for(int i = 0; i < n; i++){
      if( a[i] < s)
         d++;
      else
         k++;
  }
  printf("%.1f\n",s); // media
  printf("%lld\n",d); // abaixo da média
  printf("%lld\n",k); // acima ou igual
  
  return 0;
}
