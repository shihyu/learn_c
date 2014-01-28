#include <stdio.h>

int main(int argc, char *argv[])
{
    int m = 100;
    void *p;

    p = (void *)&m;

    p++;
    printf("%d\n", sizeof(void));

    return 0;
}
