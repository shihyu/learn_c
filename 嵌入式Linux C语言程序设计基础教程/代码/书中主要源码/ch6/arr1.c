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

    return 0;
}

