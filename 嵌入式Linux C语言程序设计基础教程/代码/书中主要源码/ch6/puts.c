#include <stdio.h>

#define N 20

int main()
{
    int i = 0;
    char s[N] = {0};

    printf(">");
    while (gets(s) != NULL)
    {
        printf(">");
       // scanf("%s", s);
        printf("i = %d :%s\n", i, s);
        i++;
    }

    printf("end main\n");

    return 0;
}

