#include <stdio.h>

int main(int argc, char *argv[])
{
    int *p = malloc(10 * sizeof(int));

    for (int i = 0; i < 10; ++i)
    {
        // p[i] = i;
        *(p+i) = i;
    }

    // int *tmp = p;

    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", *(i + p));
    }

    printf("\n");

    // p = tmp;

    printf("\n");

    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", p[i]);
    }

        
    return 0;
}
