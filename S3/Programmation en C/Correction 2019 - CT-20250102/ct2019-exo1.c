#include <stdio.h>

int
main(void)
{
  float CT, CC1, CC2, note;

  // ... Q1
  printf("Entrez vos 3 notes (CT, CC1, et CC2)= ");
  scanf("%f %f %f", &CT, &CC1, &CC2);
  if(CC1 > CC2)
    note = .5f * CT + .5f * CC1;
  else
    note = .5f * CT + .5f * CC2;
  printf("Votre note finale esr %f.\n", note);
  
  // ... Q2
  if(note >= 10.f)
    printf("Vous validez la matière.\n");
  else
    printf("Vous ne validez pas la matière.\n");
  
  return 0;
}
