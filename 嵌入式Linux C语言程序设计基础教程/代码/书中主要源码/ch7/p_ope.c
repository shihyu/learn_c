#include <stdio.h>

int main(int argc, char *argv[])
{
    int m = 100;
    double n = 200;
    int *p;
    double *q;


    p = &m;
    q = &n;

    printf("m=%d &m=%p\n", m, &m);
    printf("p=%p p+2=%p\n", p, p+2);

    printf("n=%lf &n=%p\n", n, &n);
    printf("q=%p q+2=%p\n", q, q+2);
    return 0;
}
