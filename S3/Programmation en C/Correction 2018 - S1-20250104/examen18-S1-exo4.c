#include <stdio.h>

// ... Q1
// ... Il y avait une petite erreur dans l'enonce: la fonction
//       doit retourne 10^(poids+1) 
int
poids_enonce(unsigned int n)
{
  int p = 0;
  if(n == 0)
    return 0;
  else{
    while(n != 0) {
      n /= 10;
      p += 1;
    }
    return p-1;
  }
}

int
poids(unsigned int n)
{
  int p = 1;
  if(n == 0)
    return p;
  else{
    while(n != 0) {
      n /= 10;
      p *= 10;
    }
    return p;
  }
}

unsigned long int
conway(unsigned int n)
{
  unsigned long int i;
  unsigned long int C0 = 1, C1 = 0, terme, nb, res, p;
  
  printf("C[0] = 1\n");
  for(i = 1; i <= n; i++) {
    // ...
    while(C0 != 0){
      // ... nb = nombre de terme identique au chiffre de poids faible
      nb = 0;
      terme = C0 % 10;
      while(C0 % 10 == terme) {
	nb ++;
	C0 /= 10;
      }
      res = nb * 10 + terme;
      // ... 
      p = poids(C1);
      C1 = C1 + res * p;
    }
    printf("C[%lu] = %lu\n", i, C1);
    C0 = C1;
    C1 = 0;
  }

  return C0;
}

int
main(void)
{
  int n = 2018;
  printf("poids_enonce(%d)= %d\n", n, poids_enonce(n));
  printf("poids(%d)= %d\n", n, poids(n));
  printf("Conway(3)= %ld\n", conway(3));
  
  return 0;
}
