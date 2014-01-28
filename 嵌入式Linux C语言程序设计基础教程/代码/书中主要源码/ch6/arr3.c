#include <stdio.h>

int main()
{
    int a[2][3] = {{8, 2, 6}, {1, 7, 9}}, i, j;;

    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            printf("%d ", a[i][j]);
    printf("\n");


    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            printf("%p ", &a[i][j]);
    printf("\n");

    return 0;
}

