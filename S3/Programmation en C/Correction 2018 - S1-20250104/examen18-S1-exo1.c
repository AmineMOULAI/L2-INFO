#include <stdio.h>

int
main(void)
{
  // ... Q1
  int h, m, s;
  
  printf("Entrez une heure (h:m:s)= ");
  scanf("%d %d %d", &h, &m, &s);

  if(h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
    printf("L'heure %d:%d:%d est correcte.\n", h, m, s);
    // ... Q2
    int rh, rm, rs;
    rs = 59 - s;
    rm = 59 - m;
    rh = 23 - h;
    printf("Il reste %d:%d:%d pour atteindre 23:59:59.\n", rh, rm, rs);
  } else
    printf("L'heure %d:%d:%d n'est pas est correcte.\n", h, m, s);
  
  return 0;
}
