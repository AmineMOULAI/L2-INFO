#include <stdio.h>

typedef struct 
{
    char name[50];
    char tel[20];
}agenda_tel;



int main()
{
    int n;
    int p;

    printf("entrer n :");
    scanf("%d", &n);

    agenda_tel a[n];

   
    
    for (int i = 0; i < n; i++)
    {
        printf("Name : ");
        scanf("%s", a[i].name);
        printf("Tel : ");
        scanf("%s", a[i].tel);
    }

    printf("\n");
    

    FILE* f = fopen("agenda.bin", "wb");

    if (f != NULL)
    {
        fwrite(&a,sizeof(agenda_tel), n, f);
        fclose(f);
    }

    f = fopen("agenda.bin", "rb");

    if (f != NULL)
    {
        while (fread(&a, sizeof(agenda_tel), 1, f) == 1)
        {
            printf("Name : %s\n", a->name);
            printf("Tel : %s\n", a->tel);
        }
        
        fclose(f);
    }

    printf("entrer la position : ");
    scanf("%d", &p);

    f = fopen("agenda.bin", "rb");

    if (f != NULL)
    {
        fseek(f, p * sizeof(agenda_tel), SEEK_SET);

        fread(&a, sizeof(agenda_tel), 1, f);

        printf("L'elt lu :\nName : %s\nTel: %s", a->name, a->tel);

        fclose(f);
    }
    
    
    
    return 0;
}