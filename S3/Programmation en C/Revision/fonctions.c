/* Une fonction est une suite d'instructions regroupées sous un nom. Elle contient des paramétres et retourne des résultat 
    * entrés -> traitement -> resultat
    * syntaxe :
             type_retour nom(type arg1; type arg2, ...)
             {
                 // bloc d'instruction;

                 return resultat;
             }
    * types de fonctions :
        * pas de return / pas d'args
        * pas de return / args
        * return / pas d'args
        * return / args
    
    * Ex : fonction puissance 2

        * pas de return / args :
            void puissance2(int n)
            {
                int p;
                p = n * n;
                printf("%d² = %d", n, p);
            }
        * return / pas d'args :
            int puissance2(int n)
            {
                int p;
                p = n * n; // return n * n;
                return p;
            }

    * appel de la fx :
        * pas de return / pas d'args : nom_fx();
        * pas de return / args : nom_fx(arg1, arg2, ...);
        * return / pas d'args : x = nom_fx();
        * return / args : x = num_fx(arg1, arg2, ...);
    
    * Les vars déclarés dans les fonctions sont appelés var locales
    * Une var globale se déclare en dehors de toutes les fx
*/


/*#include <stdio.h>

int puissance(int N)       // void puissance(int n 
{                          //{
    return N*N;                 //int p;
}                               // p = n*n;
                                //printf("%d² = %d", n, p);
int main(){                 //}

    int n = 5, p5;
    p5 = puissance(n);      // puissance(n);
    printf("%d² = %d\n", n, p5);
    return 0;
}*/

#include <stdio.h>

void signe(int a, int b)
{
    if (a * b > 0)
    {
        printf("même signe !\n");
    }else
    {
        printf("Signe différent!\n");
    }
}

int min(int a, int b)
{
    if (a < b) return a;
    else return b;
}

int max(int a, int b)
{
    if (a > b) return a;
    else return b;
}


int main()
{
    int a, b, m, m1;

    printf("Entrer a et b :");
    scanf("%d%d", &a, &b);

    signe(a, b);
    m = min(a, b);
    m1 = max(a, b);

    printf("Min : %d\n", m);
    printf("Max : %d\n", m1);
    return 0;
}