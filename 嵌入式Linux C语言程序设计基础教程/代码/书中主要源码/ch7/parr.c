#include <stdio.h>

int main(int argc, char *argv[])
{
    int m = 100, n = 200;
    int* p[2];

    p[0] = &m;
    p[1] = &n;

    printf("&m=%p\t&n=%p\n", &m, &n);
    printf("p[0]=%p\tp[1]=%p\n", p[0], p[1]);
    printf("p=%p\t&p[0]=%p\t&p[1]=%p\n", p, &p[0], &p[1]);

    printf("\nm=%d\tn=%d\n", m, n);
    printf("*p[0]=%d\t*p[1]=%d\n", *p[0], *p[1]);
    printf("**p=%d\t**(p+1)=%d\n", **p, **(p+1));

    return 0;
}
