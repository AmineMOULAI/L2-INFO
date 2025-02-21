#include <stdio.h>

int add_sub(int a, int b, int op)
{
    if (b == 0)
        return a;
    else
    { 
        if(op == 0) return 1 + add_sub(a, b - 1, op);
        else return add_sub(a, b - 1, op) - 1;
    }
}

int mult(int a, int b)
{
    int res, tmp;
    if (b % 2 == 0) res = 0;
    else res = a;
    
    for (int i = 0; i < b / 2; i++)
    {
        tmp = add_sub(a, a, 0);
        res += tmp;
    }
    
    return res;
}

int main()
{
    int a, b, op, res, m;

    printf("Entrer a et b :");
    scanf("%d %d", &a, &b);

    printf("Entrer l'operation (0 (+) / 1 (-)) :");
    scanf("%d", &op);

    res = add_sub(a, b, op);

    if (op == 0) printf("%d + %d = %d\n", a, b, res);
    else printf("%d - %d = %d\n", a, b, res);

    m = mult(a, b);

    printf("%d x %d = %d\n", a, b, m);
    
    
    return 0;
}