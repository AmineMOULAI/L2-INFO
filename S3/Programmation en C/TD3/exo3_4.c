// Occurences d'un caractere dans une chaine de caracteres 

#include <stdio.h>

int main()
{
    char s[50], c;
    int i = 0, occ = 0;


    printf("Entrer la chaine de caracteres : ");
    scanf("%s", s);

    printf("Entrer le caractere : ");
    scanf(" %c", &c);

    while (i < 50 && s[i] != '\0')
    {
        if (s[i] == c)
        {
            occ += 1;
        }
        i++;
        
    }
    
    printf("Nombre d'occurence de (%c) : %d", c, occ);

    return 0;
}