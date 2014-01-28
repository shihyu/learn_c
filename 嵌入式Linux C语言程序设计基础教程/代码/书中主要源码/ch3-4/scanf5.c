#include <stdio.h>

int main()
{
    int a, b, n;

    printf("input numbers:");
    while ((n = scanf("%d%d", &a, &b)) == 2)
    {
        printf("a=%d, b=%d\n", a, b);
        printf("input numbers:");
    }
    printf("n=%d\n", n);

    return 0;
}
