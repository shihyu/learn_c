#include <stdio.h>

int main(int argc, char *argv[])
{
    int m = 100;
    int *p;

    p = &m;

    printf("%d %p %p %p\n", m, &m, p, &p);

    return 0;
}
