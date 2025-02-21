// fréquence d'apparition 

#include <stdio.h>

int main()
{
    char s[50];
    int t[50], l = 0, occ = 0, max, min;


    printf("Entrer la chaine de caracteres : ");
    scanf("%s", s);

    while (l < 50 && s[l] != '\0')
    {
        l += 1;
    }

    for (int i = 0; i < l; i++)
    {
        t[i] = -1;
    }

    for (int i = 0; i < l; i++)
    {
        occ = 1;
        for (int j = i + 1; j < l; j++)
        {
            if (s[i] == s[j])
            {
                occ += 1;
                t[j] = 0;
            }      
        }
        if (t[i] != 0)
        {
            t[i] = occ; 
        }  
    }

    min = 0;
    max = 0;
    for (int i = 0; i < l; i++)
    {
        if (t[i] < min)
        {
            min = t[i];
        }
        if (max < t[i])
        {
            max = t[i];
        } 
    }
    
    printf("Le plus repete : %c\n", s[max]);
    printf("Le moins repete : %c\n", s[min]);

    
    return 0;
}