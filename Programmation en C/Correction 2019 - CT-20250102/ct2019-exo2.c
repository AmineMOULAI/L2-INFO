#include <stdio.h>

int
main(void)
{
  int i, j, n;
  printf("Entrer une valeur de n= ");
  scanf("%d", &n);

  if(n < 1)
    printf("La valeur de n doit etre > 1.\n");
  else{
    // ... Q1
    for(i = 1; i <= n; i++) {
      printf("(");
      for(j = 1; j <= i; j++) {
	        printf("%d", j);
      }
      printf(")");
    }
    printf("\n");
    
    // ... Q2
    i = 1;
    while(i <= n) {
      j = 1;
      printf("(");
      while(j <= i) {
	    printf("%d", j);
	    j ++;
      }
      printf(")");
      i ++;
    }
    printf("\n");
  }
  return 0;
}
