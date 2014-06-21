#include <stdio.h>
#include <stdlib.h>

// p++ 會改變malloc 存在p指標的起始位址 , 而另外一個 p + i 並不會改變p 內容的位址

#if 0
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
int main(int argc, char *argv[])
{
    int *p = malloc(10 * sizeof(int));

    for (int i = 0; i < 10; ++i)
    {
       *(p + i) = 1000;
    }

    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", *(i + p));
    }


    return 0;
}
#endif
