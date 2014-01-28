#include <stdio.h>

int main()
{
    int a[10], b[10], *p;

    p = b;
    a = p;

    printf("%d\n", *a);

    return 0;
}
