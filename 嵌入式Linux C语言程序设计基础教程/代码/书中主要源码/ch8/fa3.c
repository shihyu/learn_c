#include <stdio.h>

int test_array(int n, int m, int a[][m], int *p)
{
    int i, j, sum = 0;

    *p = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            sum += a[i][j];
            if (a[i][j] % 2)
                (*p)++;
        }
    
    return sum;
}

int main()
{
    int a[2][3] = {{9, 12, 2}, {3, 29, 31} } , n, m;
    int sum = 0,  odd= 0;

    n = sizeof(a) / sizeof(a[0]);
    m = sizeof(a[0]) / sizeof(int);

    sum = test_array(n, m, a, &odd);

    printf("sum=%d odd numbers count =%d\n",
            sum, odd);

    return 0;
}
