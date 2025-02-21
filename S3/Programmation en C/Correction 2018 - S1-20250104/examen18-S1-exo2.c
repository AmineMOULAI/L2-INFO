#include <stdio.h>

int
main(void)
{
  int n, i, j;

  // ... Q1
  printf("Lire une valeur de n= ");
  scanf("%d", &n);
  
  // ... non sanctionnee
  while(n <= 1) {
    printf(" ... Relire une valeur de n= ");
    scanf("%d", &n);
  }
  // ...
  
  for(i = 1; i <= n; i++)
    for(j = 1; j <= i; j++)
      printf("%d", i);
  printf("\n");

  // ... Q2
  i = 1;
  while(i <= n) {
    j = 1;
    while(j <= i) {
      printf("%d", i);
      j ++;
    }
    i ++;
  }
  printf("\n");
  
  return 0;
}
