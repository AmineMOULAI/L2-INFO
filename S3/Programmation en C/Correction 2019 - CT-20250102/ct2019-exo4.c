#include <stdio.h>

void
somme_produit(int a, int b,
	      int *S, int *P) {
  *S = a + b;
  *P = a * b;
}

int
main(void) {
  int a = 17, b = 18, S = 0, P = 0;
  somme_produit(a, b, &S, &P);
  printf("S= %d et P= %d \n", S, P);
  return 0;
}

// On illustre ici le passage des paramètre par copie et par adresse,
// et pas uniquement l'utilisation des pointeurs.
