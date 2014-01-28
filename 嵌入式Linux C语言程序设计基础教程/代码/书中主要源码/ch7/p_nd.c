#include <stdio.h>

int main(int argc, char *argv[])
{
    int m = 100, *p;
    int **q;

    p = &m;
    q = &p;

//    printf("m=%d    &m=%p   p=%p    &p=%p\n", m, &m, p, &p);
    printf("q=%p    &q=%p   *q=%p   **q=%d\n", q, &q, *q, **q);
    printf("q+1=%p\n", q+1);

    return 0;
}
