#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n = 5, *p, i;

    if ((p = (int *)malloc(n * sizeof(int))) == NULL)
    {
        printf("malloc error\n");
        return 0;
    }
    memset(p, 0, n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        p[i] = i+1;
        printf("%d ", p[i]);
    }
    printf("\n");

    printf("p=%p *p=%d\n", p, *p);
    free(p);
    printf("after free:p=%p *p=%d\n", p, *p);

    *p = 100;
    printf("p=%p *p=%d\n", p, *p);


    return 0;
}
