// chiffrement du Cesar

#include <stdio.h>

int main()
{
    char s[30];
    int k, k1, l;

    printf("Entrer la chaine de caracteres: ");
    scanf("%s", s);

    printf("Entrer k :");
    scanf("%d", &k);

    while (l < 30 && s[l] != '\0')
    {
        l++;
    }

    k1 = k;

    for (int i = 0; i < l; i++)
    {
       if (s[i] >= 'a' && s[i] <= 'z')
       {
            s[i] = ((s[i] - 'a' + k) % 26) + 'a';
       }
       
    }

    printf("Chiffrement : %s", s);
    

    return 0;
}