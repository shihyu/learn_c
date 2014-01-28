#include <stdio.h>

int main(int argc, char *argv[])
{
    int a[3][2] = {9, 6, 1, 7, 8, 3};
    int* p[3], i, j;
    int **q;

    p[0] = a[0];
    p[1] = a[1];
    p[2] = a[2];
    q = p;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d %d %d ", *(p[i]+j), *(*(p+i)+j), p[i][j]);
            printf("%d %d %d ", *(q[i]+j), *(*(q+i)+j), q[i][j]);
        }
        printf("\n");
    }

    return 0;
}
