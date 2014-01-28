#include <stdio.h>

int plus(int, int);
int minus(int, int); 

int main()
{
    int (*pFunc[2])(int, int);
    int i;

    pFunc[0] = plus;
    pFunc[1] = minus;

    for (i = 0; i < 2; i++)
        printf("%d\n", (* pFunc[i])(15, 85));

    return 0;
}

int plus(int a, int b)
{
    return (a+b);
}

int minus(int a, int b)
{
    return (a-b);
}
