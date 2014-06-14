#include <stdio.h>
#if 1
int main(int argc, char *argv[])
{
    int *p = malloc(10 * sizeof(int));
    int *tmp = p;

    for (int i = 0; i < 10; ++i)
    {
        *(p++) = 1000;
    }

    p = tmp;


    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", *(i + p));
    }


    return 0;
}
#else

void assign_value(int *p) {
    printf("%p\n",p);
    printf("%p\n",&p);
    for (int i = 0; i < 10; ++i)
    {
        // p[i] = i;
        *(p++) = 1000;
    }
}


int main(int argc, char *argv[])
{
    int *p = malloc(10 * sizeof(int));

    printf("%p\n",p);
    printf("%p\n",&p);

    assign_value(p);

    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", *(i + p));
    }

    printf("\n");

    // p = tmp;

        
    return 0;
}

#endif
