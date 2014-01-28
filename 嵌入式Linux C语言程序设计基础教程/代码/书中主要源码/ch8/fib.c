#include <stdio.h>

long fib(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return (fib(n-1)+fib(n-2));
}

int main()
{
    int i;

    for (i = 0; i < 8; i++)
        printf("%ld ", fib(i));
    printf("\n");

    return 0;
}
