// indice du premiere occurrence 

#include <stdio.h>

int main()
{
    char s[50], c;
    int i = 0, indx = 0, l = 0;


    printf("Entrer la chaine de caracteres : ");
    scanf("%s", s);

    printf("Entrer le caractere : ");
    scanf(" %c", &c);

    while (l < 50 && s[l] != '\0')
    {
        l += 1;
    }

    while (i < l && s[i] != c)
    {   
        i++;
    }
    
    if (i == l)
    {
        indx = -1;
        printf("Indice : %d\n", indx);
    }else
    {
        indx = i+1;
        printf("Indice : %d\n", indx);
    }
    

    return 0;
}