#include <stdio.h>

int main()
{
    int i, sum = 0;

    for (i = 1; i <= 100; i++)
        sum += i;

    printf("The sum of 100 is %d\n", sum);

    return 0;
}
