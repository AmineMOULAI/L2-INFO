#include <stdio.h>

int 
main(void) {
  int a = 2, b = a;
  int * ptr = &a;
  *ptr = a * (*ptr);
  printf("--> a= %d et *ptr= %d... et b= %d\n", a, *ptr, b); 
  a = ((*ptr)--) - 1;
  printf("--> a= %d et *ptr= %d... et b= %d\n", a, *ptr, b); 
  a = (*ptr--) - 1;
  printf("--> a= %d et *ptr= %d... et b= %d\n", a, *ptr, b); 
  return 0;
}

// ... Q1
// Un pointeur est une variable dont la valeur est une adresse memoire

// ... Q2 : Resultat d'execution: 
// --> a= 4 et *ptr= 4... et b= 2
//   Ici ptr pointe vers a, et b a la valeur de a.
//   En modifiant la valeur pointee par ptr (a + *(ptr) = 4), on modifie egalement a, mais pas b.
// --> a= 3 et *ptr= 3... et b= 2
//   On modifie ce qui est pointe par ptr (*(ptr) - 1 = 3).
//   Ensuite seulement on decremente ce qui est pointe par ptr (*(ptr)--), et donc a.
//   Mais toujours, on ne modifie pas b.
// --> a= 2 et *ptr= XXXX... et b= 2
//   On modifie a (*ptr-1 = 2), mais toujours pas b.
//   Ensuite seulement on decremente ptr... qui ne pointe plus vers rien, et donc
//   ce qui est pointe ne correspond a rien.
