#include <stdio.h>

int main(int argc, char *argv[])
{
    int *p1, *p2, a, b;

    a = 1;
    b = 20;

    p1 = &a;
    p2 = &b;

    printf("a=%d, b=%d\n", a, b);
    printf("*p1=%d, *p2=%d\n", *p1, *p2);
    printf("&a=%p, &b=%p\n", &a, &b);
    printf("p1=%p, p2=%p\n", p1, p2);

    *p1 = 20;
    printf("after changing *p1......\n");

    printf("a=%d, b=%d\n", a, b);
    printf("*p1=%d, *p2=%d\n", *p1, *p2);

    return 0;
}
