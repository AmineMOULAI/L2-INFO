// afficher la table ASCII

#include <stdio.h>

char ascii(unsigned short c)
{
    return (char) c;   
}

int ascii1(char c)
{
    return (int) c;
}

int main()
{
    int a;
    char c = 'a';
    for (int i = 0; i < 128; i++)
    {
        printf("%hu : %c\n", i, ascii(i));
    }

    a = ascii1(c);

    printf("%c = %d\n",c, a);

    
    return 0;
}