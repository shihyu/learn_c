#include <stdio.h>

int n;
double factorial();

int main()
{
    double s = 0;

    printf("input:");
    scanf("%d", &n);

    s = factorial();
    printf("%e\n", s);

    return 0;
}

double factorial()
{
    double ret = 1;
    int i;

    for (i = 1; i <= n; i++)
        ret *= i;

    return ret;
}
