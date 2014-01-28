#include <stdio.h>

int main()
{
    int a[][3] = {9, 1, 4, 7, 3, 6}, i, j;
    int *p, r, c, n;

    p = &a[0][0];
    r = sizeof(a) / sizeof(a[0]);
    c = sizeof(a[0]) / sizeof(int);
    n = sizeof(a) / sizeof(int);

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            printf("%d  %p\n", a[i][j], &a[i][j]);

    printf("\n");

    for (i = 0; i < n; i++)
        printf("%d  %p\n", *(p+i), p+i);

    return 0;
}
