#include <stdio.h>

int main_Q3(void); // ... utile pour la question 3

// ... Q1
// Definition: un pointeur est une variable dont la valeur est une adresse memoire
// ...

// ... question 2
int
main(void)
{
  int a = 17;
  int * ptr = &a;
  *ptr = a + 1;
  printf("--> a= %d et *ptr= %d \n", a, *ptr);
  a = (*ptr--) - 1;
  printf("--> a= %d et *ptr= %d \n", a, *ptr);
  // ...
  main_Q3();
  return 0;
}
// Resultat d'execution: 
// --> a= 18 et *ptr= 18
//   Ici ptr pointe vers a.
//   En modifiant la valeur pointee par ptr (a + 1 = 18), on modifie egalement a.
// --> a= 17 et *ptr= 32767
//   On modifie a (*ptr-1 = 17).
//   Ensuite seulement on decremente ptr... qui ne pointe plus vers rien, et donc
//   ce qui est pointe ne correspond a rien.
// ...

// ... Q3
int
main_Q3(void) // main est renomme ici en main_q3
{
  int tab[17];
  int *ptr = tab; // &(tab[0]);
  // ... partie a completer
  int i;
  for(i = 0; i < 17; i++)
    scanf("%d", ptr++ /* ptr+i */);
  // ... verification
  for(i = 0; i < 17; i++)
    printf("tab[%d]= %d \n", i, *(tab+i) /* *(ptr+i) */);
  return 0;
}
// ...
