#include <stdio.h>

int main()
{
    char let = 'F';
    int i, j;

    for (i = 0; i < let - 'A'; i++)
    {
        for (j = 0; j < i; j++)
            printf("_");

        for (j = 0; j <= i; j++)
            printf("%c", let-j);
        printf("\n");
    }

    return 0;

}
