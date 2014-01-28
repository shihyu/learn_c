#include <stdio.h>

int test_array(int a[], int n, int *p)
{
    int i, sum = 0;

    *p = 0;
    for (i = 0; i < n; i++)
    {
        sum += a[i];
        if (a[i] % 2)
            (*p)++;
    }
    
    return sum;
}

int main()
{
    int a[2][3] = {{9, 12, 2}, {3, 29, 31} } , n;
    int sum = 0,  odd= 0;

    n = sizeof(a) / sizeof(int);

    sum = test_array(a[0], n, &odd);

    printf("sum=%d odd numbers count =%d\n",
            sum, odd);

    return 0;
}
