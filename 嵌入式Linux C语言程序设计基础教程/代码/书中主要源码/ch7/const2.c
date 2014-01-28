#include <stdio.h>

int main(int argc, char *argv[])
{
    int m = 100, n = 200;
    int * const p = &m;

    printf("1) %d %p %d %p\n", m, &m, *p, p);

    m++;
    printf("2) %d %p %d %p\n", m, &m, *p, p);

    *p = n;
    printf("3) %d %p %d %p\n", m, &m, *p, p);

#ifdef _DEBUG_
    p = &n;
    printf("4) %d %p %d %p\n", n, &n, *p, p);
#endif

    return 0;
}
