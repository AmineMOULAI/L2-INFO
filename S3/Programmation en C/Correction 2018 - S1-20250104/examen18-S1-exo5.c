#include <stdio.h>

// ... Q1

int /* somme */
somme_produit(int a, int b, int* p /* produit */)
{
  *p = a * b;
  return a + b;
}

int
main(void)
{
  int a =17, b =2, s, p;
  s = somme_produit(a, b, &p);
  printf("(s, p) = (%d, %d)\n", s, p);
  return 0;
}

// ... Q2
// Passage par valeur : le parametre par valeur dans la fonction appelee (ici a) est une copie
//   memoire de celui dans la fonction appelante (ici x).
//   Meme si a est modifié, x ne le sera pas.
// Passage par adresse : le parametre par adresse dans la fonction appelee (ici p) est une copie
//   memoire de celui dans la fonciton appelante (ici &y), mais ils pointent tous les deux vers
//   le meme espace memoire. Si dans la fonction, on modifie ce qui est pointe par p (cad, *p),
//   cette modification affectera ce qui est pointe par &y (cad, y).
