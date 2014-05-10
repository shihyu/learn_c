#include <stdio.h>

int main(int argc, char *argv[])
{
    int *a = NULL;
    char *c  = NULL;
    printf("%ld\n", sizeof(a));
    printf("%ld\n", sizeof(c));

    printf("%p\n", a + 1);
    printf("%p\n", c + 1);

    return 0;
}
