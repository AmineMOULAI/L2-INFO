#include <stdio.h>
#include <math.h>

int main()
{
    int age;

    printf("Entrer l'âge :");
    scanf("%d", &age);

    switch (age)
    {
    case 5: printf("Poussin");
         break;

    case 6: printf("Poussin");
         break;

    case 7: printf("Diaboltin");
         break;

    case 8: printf("Diaboltin");
         break;
         
    case 9: printf("Préminime");
         break;

    case 10: printf("Préminime");
         break;

    case 11: printf("minime");
         break;

    case 12: printf("minime");
         break;
    
    case 13: printf("Cadet");
         break;
    
    case 14: printf("Cadet");
         break;
    
    case 15: printf("Scolaire");
         break;

    case 16: printf("Scolaire");
         break;

    case 17: printf("Espoir");
         break;

    case 18: printf("Espoir");
         break;
    default:
        printf("Au delà de 18 ans");
        break;
    }

    return 0; 

}
