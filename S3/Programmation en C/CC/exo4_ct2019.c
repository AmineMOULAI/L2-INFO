#include <stdio.h>

int min(int t[], int n, int k)
{
    int min = t[k];
    int indx_min;

    for (int i = k; i < n; i++)
        if (min > t[i]) indx_min = i;
    
    return indx_min;
}

void tri(int t[], int n)
{
    int tmp, indx;

    for (int i = 0; i < n; i++)
    {
        indx = min(t, n, i);
        tmp = t[i];
        t[i] = t[indx];
        t[indx] = tmp;
    }
    
}

int main()
{
    int n = 10;

    int t[10] = {0, 1, 0, 0, 1, 1, 0, 0, 1, 1};

    tri(t, n);

    return 0;
}