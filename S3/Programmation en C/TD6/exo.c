#include <stdio.h>

int main()
{
    char c;
    int pos;

    FILE* f = fopen("exo.txt", "r");

    if (f != NULL)
    {
        
        fseek(f, 0,SEEK_END);
        pos = ftell(f);

        for (int i = 1; i <= pos; i++)
        {
            fseek(f, -i,SEEK_END);
            c = fgetc(f);
            printf("%c", c);
        }
        fclose(f);
        printf("\nTraitement reussi !");
    }else printf("Erreur !");
    


    return 0;
}