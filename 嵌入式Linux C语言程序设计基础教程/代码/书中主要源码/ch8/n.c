#include <stdio.h>

double factorial(int n);

int main()
{
    double r;

    r = factorial(5);
    printf("5!=%lf\n", r);

    return 0;
}

double factorial(int n)
{
    if (n <= 1)
        return 1;
    return (n * factorial(n-1));
}
