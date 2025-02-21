// pointeurs

#include <stdio.h>

int main()
{
    int i;
    int* p;

    i = 10;
    p = &i;

    printf("%d\n", i);
    *p = 18;
    printf("%d\n", i);

    printf("%p\n", &p);
    printf("%p\n", &i);
    printf("%d", *p);

    return 0;
}