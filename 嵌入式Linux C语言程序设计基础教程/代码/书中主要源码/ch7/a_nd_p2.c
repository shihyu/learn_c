#include <stdio.h>

int main()
{
    int a[][3] = {9, 1, 4, 7, 3, 6}, i, j,r, c;
    int (*p)[3];

    p = a;
    r = sizeof(a) / sizeof(a[0]);
    c = sizeof(a[0]) / sizeof(int);

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d  %d  %d  ", a[i][j], *(*(a+i)+j), *(a[i]+j));
            printf("%d  %d  %d\n", p[i][j], *(*(p+i)+j), *(p[i]+j));
        }
        printf("\n");
    }

    return 0;
}
