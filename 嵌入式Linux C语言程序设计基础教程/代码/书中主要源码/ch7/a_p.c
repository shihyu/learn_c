#include <stdio.h>

int main()
{
    int a[] = {9, 1, 34, 7, 3, 10}, i;
    int *p, n;

    p = a;
    n = sizeof(a) / sizeof(int);

    for (i = 0; i < n; i++)
        printf("%d %d %d %d\n", *(a+i), a[i], *(p+i), p[i]);

    return 0;
}
