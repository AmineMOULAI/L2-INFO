// nombres de chiffres et de lettres

#include <stdio.h>

int main()
{

    char ch[50];
    int nbrN = 0, nbrL = 0, i;

    printf("Entrer la chaine de caractères : ");
    scanf("%s", ch);

    i = 0;
    while (i < 50 && ch[i] != '\0')
    {
        if ((('a' <= ch[i]) && (ch[i] <= 'z')) || (('A' < ch[i]) && (ch[i] < 'Z')))
        {
            nbrL += 1;
        }
        if (('0' <= ch[i]) && (ch[i] <= '9'))
        {
            nbrN += 1;
        }
        
        i += 1;
        
    }

    printf("Nombres de lettres : %d\n", nbrL);
    printf("Nombres de chiffres : %d\n", nbrN);
    



    return 0;
}