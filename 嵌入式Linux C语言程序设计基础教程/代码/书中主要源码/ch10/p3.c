#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a[5] = {1, 9, 6, 2, 10}, *p, i, n;

    n = sizeof(a) / sizeof(n);
    p = a;

    for (i = 0; i <= n; i++)
    {
        printf("%d ", *p);
        p++;
    }
    printf("\n");

    *p = 100;
    printf("*p=%d\n", *p);

    return 0;
}
