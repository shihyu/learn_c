#include <stdio.h>

int main(int argc, char *argv[])
{
    int m = 100;
    double n = 200;

    int *p1, *p2;
    double *q1, *q2;

    p1 = &m;
    p2 = p1 + 2;

    q1 = &n;
    q2 = q1 + 2;

    printf("p1=%p p2=%p\n", p1, p2);
    printf("p2-p1=%d\n", p2-p1);

    printf("q1=%p q2=%p\n", q1, q2);
    printf("q2-q1=%d\n", q2-q1);

    return 0;
}
