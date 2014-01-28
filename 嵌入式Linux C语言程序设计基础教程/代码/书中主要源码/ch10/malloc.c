#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *get_memory(int n)
{
    int *p, i;

    if ((p = (int *)malloc(n * sizeof(int))) == NULL)
    {
        printf("malloc error\n");
        return p;
    }
    memset(p, 0, n * sizeof(int));

    for (i = 0; i < n; i++)
        p[i] = i+1;

    return p;
}

int main()
{
    int n, *p, i;

    printf("input n:");
    scanf("%d", &n);
    if ((p = get_memory(n)) == NULL)
        return 0;

    for (i = 0; i < n; i++)
        printf("%d ", p[i]);
    printf("\n");

    free(p);
    free(p);


    return 0;
}
