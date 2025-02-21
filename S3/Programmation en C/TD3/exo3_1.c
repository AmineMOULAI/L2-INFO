// chaines de caractères 

#include <stdio.h>

int main()
{
    char ch[50], c = 0;

    printf("Entrer la chaine de caractères :");
    scanf("%s", ch);
        

    while (c < 50 && ch[c] != '\0')
    {
        c += 1;
    }

    printf("La longeur de la chaine de charactères (%s) : %d\n", ch, c);
    
    return 0;
    
}