// conversion en MAJ

#include <stdio.h>

int main()
{
    char s[50];
    int i = 0, l = 0;


    printf("Entrer la chaine de caracteres : ");
    scanf("%s", s);

    while (l < 50 && s[l] != '\0')
    {
        l += 1;
    }
    while (i < l)
    {
        while (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 32;
        }
        
        i++;
    }

    printf("Majuscule : %s\n", s);
    

    return 0;
}