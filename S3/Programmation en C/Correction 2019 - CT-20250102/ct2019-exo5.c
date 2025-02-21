#include <stdio.h>

// ... Q1
void
tri_comptage(int t[10])
{
  int nb = 0, i;
  // ...
  for(i = 0; i < 10; i++)
    if(t[i] == 0)
      nb++;
  // ...
  for(i = 0; i < nb; i++)
    t[i] = 0;
  for(i = nb; i < 10; i++)
    t[i] = 1;
}

// ... Q3
void tri_comptage_n(int t[], int n);

// ... Q4
void
tri_comptage_v2(int t[], int n)
{
  int idx = -1, i, tmp;
  for(i = 0; i < n; i++) {
    if(idx == -1 && t[i] == 1)
      idx = i;
    else if(idx != -1 && t[i] == 0) {
      tmp = t[idx];
      t[idx] = t[i];
      t[i] = tmp;
      idx = (i<idx+1?i:idx+1); // idx = min(i, idx+1);
    }
  }
}

// ... Q2
int
main(void)
{
  int i, t[10] = {0, 1, 1, 0, 1, 0, 0, 1, 1, 0};
  // ...
  printf("[ ");
  for(i = 0; i < 10; i++)
    printf("%d ", t[i]);
  printf("]\n");
  // ...
  tri_comptage(t);
  // tri_comptage_v2(t, 10);
  // ...
  printf("[ ");
  for(i = 0; i < 10; i++)
    printf("%d ", t[i]);
  printf("]\n");
  return 0;
}

// ... Q3

