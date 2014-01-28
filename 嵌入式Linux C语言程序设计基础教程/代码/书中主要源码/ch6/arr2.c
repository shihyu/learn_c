#include <stdio.h>

int main()
{
    int a[5], i;
    char b[5];

    for (i = 0; i < 5; i++)
        printf("%p ", &a[i]);
    printf("\n");

    for (i = 0; i < 5; i++)
        printf("%p ", &b[i]);
    printf("\n");

    int c[2][] = {{1, 2, 3}, {4, 5, 6}};

    return 0;
}

