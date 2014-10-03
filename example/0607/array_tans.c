#include <stdio.h>

// int *p = a;
void test(int *p)
{
    int i;
#if 0
    for (i = 0; i < 10; ++i) {
        printf("%d ",p[i]);
    }
#endif

    for (i = 0; i < 10; ++i) {
        p[i] = p[i] + 10;
    }

    printf("\n");
}

int main(int argc, char *argv[])
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int i;

    for (i = 0; i < 10; ++i) {
        printf("%d ",a[i]);
    }
    printf("\n");

    test(a);

    for (i = 0; i < 10; ++i)
    {
        printf("%d ",a[i]);
    }

    return 0;
}
