// Comparaison des chaines de caractères 

#include <stdio.h>

int main()
{
    char s1[50], s2[50];
    int i = 0, res = 0;


    printf("Entrer la 1ere chaine de caracteres : ");
    scanf("%s", s1);

    printf("Entrer la 2eme chaine de caracteres :");
    scanf(" %s", s2);


   while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
   {
       i++;
   }

   if (s1[i] == s2[i]) res = 0;
   else if (s1[i] < s2[i]) res = -1;
   else res = 1;
   
   printf("Resultat : %d\n", res);

    return 0; 
 
}