#include <stdio.h>

int main ()
{
    char str1 [256] = " Vive le cours de programmation C";
    char str2 [256] = " ... on a hate d ’ etre \0 a la semaine prochaine ";
    char str3 [256];
    
    // ...
    printf (" Entrez une chaine de caracteres : ");
    scanf ("%s" , str3 ); // /!\ pas de symbole &
    
    // ...
    printf (" str1 : ’%s ’ \n" , str1 );
    printf (" str2 : ’%s ’ \n" , str2 );
    printf (" str3 : ’%s ’ \n" , str3 );

    return 0;
}