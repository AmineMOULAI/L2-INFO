#include <stdio.h>

typedef struct 
{
    char name[50];
    char tel[20];
}agenda_tel;

int main()
{
    int n;

    printf("Entrer n :");
    scanf("%d", &n);

    agenda_tel a[n];

    for (int i = 0; i < n; i++)
    {
        printf("Elt %d:\n", i + 1);

        printf("Name : ");
        scanf("%s", a[i].name);

        printf("Tel : ");
        scanf("%s", a[i].tel);

    }
    
    FILE* f = fopen("agenda.txt", "w");

    if (f != NULL)
    {
        for (size_t i = 0; i < n; i++)
        {
            fprintf(f, "Name : %s\nTel: %s\n\n", a[i].name, a[i].tel);
        }

        fclose(f);
    }else printf("Erreur !\n");

    agenda_tel contact;
    f = fopen("agenda.txt", "r");

    if (f != NULL)
    {
        
        while (fscanf(f, "Name : %49[^\n]\nTel : %19[^\n]\n\n", contact.name, contact.tel) == 2)
        {
            printf("elt lu :\nName : %s\nTel : %s\n\n", contact.name, contact.tel);            
        } 

        fclose(f);   
    }else printf("Erreur !\n");

    int p;
    printf("Entre la position :");
    scanf("%d", &p);

    f = fopen("agenda.txt", "r");


     if (f != NULL)
     {
        int c = 1;

        while(fscanf(f, "Name : %49[^\n]\nTel : %19[^\n]\n\n", contact.name, contact.tel))
        {
            if (p == c)
            {
                printf("elt pos%d :\nName : %s\nTel : %s\n\n",p , contact.name, contact.tel);

            }
            c++;
        }
        fclose(f);
     }
     
    
    

    return 0;
}