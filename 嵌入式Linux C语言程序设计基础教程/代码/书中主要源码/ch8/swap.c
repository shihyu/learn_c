#include <stdio.h>

void exchange(int a, int b)
{
    int t;

    printf("&a=%p &b=%p\n", &a, &b);

    t = a;
    a = b;
    b = t;

    printf("a=%d b=%d\n\n", a, b);
}

int main()
{
    int m = 10, n = 20;

    exchange(m, n);
    printf("&m=%p &n=%p\n", &m, &n);
    printf("m=%d n=%d\n", m, n);

    return 0;
}
