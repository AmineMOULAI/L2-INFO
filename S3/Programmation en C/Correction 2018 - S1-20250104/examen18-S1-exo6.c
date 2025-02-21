#include <stdio.h>

// ... Q1
void
swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void
renverse(int tab[10])
{
  int i = 0, j = 9, tmp;

  // ...
  while(i < j) {
    // swap(&tab[i++], &tab[j--]);
    swap(&tab[i], &tab[j]);
    i++;
    j--;
  }

  // ...
  for(i = 0; i < 10; i++)
    printf("%d ", tab[i]);  
  printf("\n");
}

// ... Q3
void renverse_n(int tab[], int n);

// ... Q2
int
main(void)
{
  int i, tab[10] = {1,2,3,4,5,6,7,8,9,10};
  renverse(tab);
  // ...
  for(i = 0; i < 10; i++)
    printf("%d ", tab[i]);  
  printf("\n");
  // ...
  
  return 0;
}


