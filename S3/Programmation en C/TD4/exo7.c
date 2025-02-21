#include <stdio.h>

// Min
int min_tab(int t[], int n)
{
    int m ;

    m = t[0];
    for (int i = 0; i < n; i++)
    {
        if (m > t[i])
        {
            m = t[i];
        }
        
    }

    return m;
}

// Max
int max_tab(int t[], int n)
{
    int m ;

    m = t[0];
    for (int i = 0; i < n; i++)
    {
        if (m < t[i])
        {
            m = t[i];
        }
        
    }
    return m;

}

// Moyenne 
float moyenne_tab(int t[], int n)
{
    float s = 0;

    for (int i = 0; i < n; i++)
    {
        s += t[i];
    }

    return s / n;
}

// nbr de valeurs petits que k
int petit(int t[], int n, int k)
{
    int c = 0;

    for (int i = 0; i < n; i++)
    {
        if (k > t[i])
        {
            c += 1;
        }
        
    }
    return c;
}


int main()
{
    const int n = 10;
    int t[n], k;

    for (int i = 0; i < n; i++)
    {
        printf("Entrer un elt :");
        scanf("%d", &t[i]);
    }

    printf("Entrer k :");
    scanf("%d", &k);

    printf("Le min : %d\n", min_tab(t, n));
    printf("Le max : %d\n", max_tab(t, n));
    printf("La moyenne : %.2f\n", moyenne_tab(t, n));
    printf("Nbr de valeurs < %d : %d\n", k, petit(t, n, k));
    

    
    return 0;
}