#include <stdio.h>
#include <string.h>

#define N 128

int main()
{
    char buf[N];
    char *arg[N];
    int i = 0, j;

    printf("Input a string:");
    while (gets(buf) != NULL)
    {
        printf("buf:%s\n", buf);

        i = 0;
        arg[i++] = strtok(buf, " ");
        do
        {
            arg[i++] = strtok(NULL, " ");
        }while (arg[i-1] != NULL);

        printf("A sequence of tokens:");
        for (j = 0; j < i-1; j++)
            printf("%s  ", arg[j]);
        printf("\n");

        printf("buf:%s\n", buf);
        printf("Input a string:");
    }

    return 0;
}
