// renverser une chaine de caracteres

#include <stdio.h>

int main()
{

    char ch[50];
    int c = 0; // init

    printf("[DEBUG] c : %d\n",c);

    printf("Entrer la chaine de caractères : ");
    scanf("%s", ch);

    
    while (c < 50 && ch[c] != '\0')
    {
        c += 1;
    }

    for (int i = c; i > 0; i -= 1)
    {
        printf(" %c", ch[i]);
    }
    

    return 0;
}